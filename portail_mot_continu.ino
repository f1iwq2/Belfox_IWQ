// *********************************************************
// Version 07 09 2022 17h20
// Pilotage PWM de moteurs à courant continu
// pour ARDUINO NANO - F1IWQ
// pour la compilation et le téléchargement, sélectionner arduino NANO sinon le téléchargement ne fonctionnera pas.
// La fréquence PWM est par défaut de 976,56 Hz. Elle utilise les broches D5 et D6 et le pilotage PWM utilise le timer 0.
// Attention la fonction delay() utilise le timer 0 !
// Ne pas utiliser Tempo() dans la fonction traitement() ni dans les fonctions à l'intérieur à savoir recul() et avance() mais delay.
// pos fin=7300
// *********************************************************

// 1 tour programme principal (main) dure en moyenne 800 à 850µs

#include <TimerOne.h>
#include <EEPROM.h>

// bibliothèque ssd1306ascii allégée pour nano pour écran oled
#include <SSD1306Ascii.h>
#include <SSD1306AsciiAvrI2c.h>
#include <SSD1306AsciiSoftSpi.h>
#include <SSD1306AsciiSpi.h>
#include <SSD1306AsciiWire.h>
#include <SSD1306init.h>

// écran oled
#define I2C_ADDRESS 0x3C  // a changer suivant écran
// Sans broche RESET
#define RST_PIN -1

// organisation des lignes de l'écran d'exploitation---------------------
#define ligne_pos        3
#define ligne_erreur     7

#define Tempo_sortie_menu 30 // 30 s
// organisation des lignes Y de l'écran MENU (1)
#define premiere_ligneM  1
#define derniere_ligneM  9
#define offset_M         2  // début de l'affichage en Y=2

#define ligne_aprentiss  1  // lancement de l'apprentissage
#define ligne_Param_sens 2  // sens d'ouverture du portail
#define ligne_Param_PPS  3  // paramètre F7  : 0=ouverture complète/fermeture complète  1=ouverture/arret/fermeture/arret
#define ligne_eprom      4  // Sauvegarde des paramètres en EPROM
#define ligne_ES         5  // affichage des E/S
#define ligne_tpsmax     6  // temps maxi de fonctionnement
#define ligne_acc        7  // 
#define ligne_dec        8  // 
#define ligne_dist_dec   9  // distance de décélération au fins de courses


const String ligne_menu_S[]={"Apprentissage",
                             "Sens d'ouverture=",
                             "Sequencement=",
                             "Sauvegarde EPROM",
                             "Affichage entrees",
                             "Tps max fonction=",
                             "Tps accel=",
                             "Tps decel=",
                             "Dist decel="};


// ports d'entrées / sorties nano----------------------------------------
#define   buzzer     13     // D13 portB.5 led intégrée et buzzer
#define   BpM        12     // D12 portB.4 Bouton -
#define   BpP        11     // D11 portB.3 Bouton +
#define   BpE        10     // D10 portB.2 Bouton ENTREE
#define   infomarche  9     // D9  portB.1 Relais K1
#define   BpEch       8     // D8  portB.0 Bouton Ech
#define   Commande    7     // D7  portD.7 Commande ouverture/fermeture 
#define   RPWM        6     // D6  portD.6 pilotage PWM R
#define   LPWM        5     // D5  portD.5 pilotage PWM L
#define   Cellule     4     // D4  portD.4 Photo-cellule
#define   Fuse        3     // D3  portD.3 Fusible F1
#define   rien        2     // D2  portD.2 

// port C de l'ATMEGA328 
#define   Scl        A5     // portC.5 SCL
#define   Sda        A4     // portC.4 SDA
#define   FcFerme    A3     // portC.3 bit 3 Fin de course fermé
#define   FcOuvert   A2     // portC.2 bit 2 Fin de course ouvert
#define   radiorelR  A1     // portC.1 bit 1 Radio2 par relais
#define   radiorelL  A0     // portC.0 bit 0 Radio1 par relais

// sélection de A6 et A7 du convertisseur analogique - 10 bits valeurs de 0 à 1023.
#define   LIS         6     // A6 image courant L
#define   RIS         7     // A7 image courant H

// vitesses lente et rapide (maxi 255)
#define   lent      150
#define   rapide    255

volatile int  compsec,Compt10Sec,secondes,nombre,i,dist_decP,dist_dec;
volatile int  Temps_boutonM,Temps_boutonP,val_tempo,ligne_menu,intensite,intensite_max ;
volatile int  Temps_boutonE,AncErreur,Seq,Temps_boutonEch,pos_ferme,Nbip;
volatile int  Tempo_menu,derniere_ligne,premiere_ligne,PageMenu,cpt_mvt,timer;
volatile int  tempo_affT,Temps_bornier,Tps_fonctionnement,Tps_fonc_P;
volatile int  decale,offset,cpt_mvt_10,courantRIS,courantLIS,s_consigne,courantLIS_arr,courantRIS_arr;
volatile int  Tps_accP,Tps_acc,Tps_dec,Tps_decP,pos,consigne,cons_loc,increment,anc_consigne;
volatile int  tempo_bip,nombre_bip,Max_bip,compt_seq,ADC_p,tps_marche,msg_fdc,tempo_apres_acc;
         int  _intensite_max,autorepeat,delayautorepeat; 
volatile byte Sens_Ouv,Sens_Ouv_P,PPS,PPS_P;
volatile byte bip,HauteurBuz,erreur;
volatile bool demande_arret,Fc_ferme,Fc_ouvert,avance,recul,debug ; 
volatile bool Aferme,Aouvert,simu,recul_cours,avance_cours,MemRecul,MemAvance ;
volatile bool dem_inc_boutonM,dem_inc_boutonP,Cellule_ok,ACellule,menu,Anc_BpP,Anc_BpM,Anc_BpE ;
volatile bool simuMenu,Simu8,Simu2,Enter,Anc_BpEch,Etat_BpP,Etat_BpM,Msg_cell_ok;
volatile bool dem_inc_boutonE,Etat_BpE,Etat_BpEch,curseur,decel,accel;
volatile bool Fm_M,Fm_E,Fm_P,Fm_Ech,dem_inc_boutonEch,Fm_O,Fm_F,Fd_O,Fd_F;
volatile bool arrete,Cde_bornier,Fm_Bornier,Abornier,demande_arr_imm;
volatile bool demande_recul_imm,FmBornier,Man_Bornier,litRIS,radioR,radioL,dem_aff_pos;
volatile bool Msg_cell_nok,trajet_long,Anc_Fus,Etat_Fus,marche_buz,AncR,AncL,FaireApprend;
volatile long iteration,poslong,tps_erreur;
char          inByte ;
String        s,chaine,vide,chaineEnCours; 

SSD1306AsciiWire oled;

// interruption timer toutes les 217,01388 micro secondes (2,017 ms) (460 Hz)
// compteur à 460  = génère 1 seconde
void Interrupt_T1() 
{
  Anc_Fus=Etat_Fus;
  Etat_Fus=digitalRead(Fuse);         // fusible ok à 0
  
  //if (!Etat_Fus) // si le fusible est ok, on tient compte des Fdc et de la cellule
  {
    Aferme=Fc_ferme;
    Aouvert=Fc_ouvert;
    ACellule=Cellule_ok;
    
    Fc_ferme=digitalRead(FcFerme);      // les Fdc ouvert et fermé doivent être électriquement à 1 au repos.
    Fc_ouvert=digitalRead(FcOuvert);    //  
    Cellule_ok=!digitalRead(Cellule);   // LOW=Cellule ok donc on inverse

    // fronts montants des Fdc (acostage)
    Fm_F=(!Aferme) & Fc_ferme;
    Fm_O=(!Aouvert) & Fc_ouvert;

    if (!ACellule & Cellule_ok) Msg_cell_ok=HIGH;
    if (ACellule & !Cellule_ok) Msg_cell_nok=HIGH;  
  }
  
  if ((!Anc_Fus) & (Etat_Fus)) erreur=3;
  if ((Anc_Fus) & (!Etat_Fus)) erreur=0;
 
  
  // Fronts descendants des Fdc (on les quitte)
  Fd_F=Aferme & (!Fc_ferme);
  Fd_O=Aouvert & (!Fc_ouvert); 

  // acostage du fdc fermé : mémoriser la position si on a démarré depuis le fdc_recul sans arret
  if (Fm_F & avance) // & trajet_long)
  {
    trajet_long=LOW;
    pos_ferme=pos;
    //proc_arret_immediat();
    //Serial.println(pos_ferme);
  }

  if (marche_buz)
  {
    digitalWrite(buzzer,bitRead(bip,HauteurBuz));   // HauteurBuz=bit de 0 à 3 pour la hauteur de la note
    ++bip; // compteur de 0 à 15
    if (bip==16) bip=0;
  }
  else digitalWrite(buzzer,LOW);
 
  ++Compt10Sec;    // compteur 1/10eme de seconde

  // compteurs appui boutons (en temps timer 217µs)
  if ((dem_inc_boutonM) & (Temps_boutonM<32000)) ++Temps_boutonM;
  if ((dem_inc_boutonP) & (Temps_boutonP<32000)) ++Temps_boutonP;
  if ((dem_inc_boutonE) & (Temps_boutonE<32000)) ++Temps_boutonE;
  if ((dem_inc_boutonEch) & (Temps_boutonEch<32000)) ++Temps_boutonEch;

  // séquenceur 1/10 seconde---------------
  if (Compt10Sec>=460)
  {
    Compt10Sec=0;
    ++compsec;       // compteur 1 seconde
    if (avance_cours | recul_cours) ++cpt_mvt_10; else cpt_mvt_10=0;  // compteur mvt en 1/10 de s
        
    if (val_tempo!=0) --val_tempo;
    if (tempo_bip!=0) ++tempo_bip;
    if (tempo_apres_acc!=0) {++tempo_apres_acc;}
    if (tempo_apres_acc>10) tempo_apres_acc=0;
    
    if (nombre_bip<Max_bip)
    {
      if (tempo_bip==0)
      {
        tempo_bip=1;
      }
      if (tempo_bip==5) 
      {
        marche_buz=HIGH;
      }
      if (tempo_bip==10)
      {
        if (marche_buz) ++nombre_bip;
        tempo_bip=1;
        marche_buz=LOW;
      } 
    }

    if (tempo_bip>10) tempo_bip=0;
    if (erreur==0) {tempo_bip=0;marche_buz=LOW;}
    
    // on recommence un cycle buzzer au bout de 8s
    if (compt_seq==8)
    {
      compt_seq=1;  // séquenceur buzzer à 10s (cycle complet)
      tempo_bip=1;
      nombre_bip=0;
    }
    
    // seconde------------------
    if (compsec>=10)
    {
      ++compt_seq;  // séquenceur buzzer
      
      compsec=0;
      ++secondes;

      if (tps_erreur!=0) tps_erreur++;
      // arreter le buzzer au bout d'une heure
      if (tps_erreur>3600) 
      {
        Max_bip=0;
      }
      if (tempo_affT!=0) --tempo_affT;
      if (avance_cours | recul_cours) ++cpt_mvt;
      if (Tempo_menu>0) {++Tempo_menu;} 
      if (tps_marche>0) ++tps_marche;
      if (tps_marche==30) {digitalWrite(infomarche,LOW);tps_marche=0;}
    } 

    // intégration position: la distance est la vitesse (cons_loc) mesuré tous les 1/10ème de s  ------------------
    if (avance_cours)
    {
      poslong=poslong+cons_loc;   // longint
      pos=poslong/10;
    }
    if (recul_cours)
    {
      poslong=poslong-cons_loc;  // longint
      pos=poslong/10;
    }
  }
  
  // filtrage commande---------------------------------------------------------
  Abornier=Cde_bornier;
  if ((digitalRead(Commande))==LOW) {Temps_bornier=60;Cde_bornier=HIGH;}
  if (Temps_bornier>0) 
  {
    --Temps_bornier;
    if (Temps_bornier==0) {Cde_bornier=LOW;}
  }
  Fm_Bornier=!Abornier & Cde_bornier;
  if (Fm_Bornier) Man_Bornier=!menu;

  // raz de la position si FDC ouvert (origine)
  if (Fc_ouvert) {pos=0;poslong=0;}
  
  // lecture courant pont L et R (LIS et RIS) ---------------------------------
  if (bit_is_clear(ADCSRA,ADSC))  // échantillon prêt ?
  {  
    // lire la valeur analogique ; elle peut être faible ...
    ADC_p=ADC; 
    if (litRIS) 
    {
      courantRIS=ADC_p;  
      if (arrete) courantRIS_arr=ADC_p;  // courant RIS à l'arret (offset)
    }
    else 
    {
      courantLIS=ADC_p ;  
      if (arrete) courantLIS_arr=ADC_p;  // courant LIS à l'arret (offset)
    }
   
    if ( ((avance_cours) & (Sens_Ouv==1)) | ((recul_cours) & (Sens_Ouv==0)) )  
    {  
      intensite=courantLIS-courantLIS_arr;
    }  
    if ( ((recul_cours)  & (Sens_Ouv==1)) | ((avance_cours) & (Sens_Ouv==0)) )
    {
      intensite=courantRIS-courantRIS_arr;
    
    }
    // on ne vérifie pas l'intensité en accélération ou en décélération car elle crée un pic
    if ((avance_cours | recul_cours) & (!accel) & (!decel) & (tempo_apres_acc==0) )
    { 
      if (intensite>255L*intensite_max/consigne)  // la consigne max sert de comparaison de courant. "L" obligatoire car on travaille en entier long.
      {
        if (avance_cours) erreur=1; else erreur=2;
        if (debug) Serial.print(intensite);Serial.print(" / ");Serial.println(255L*intensite_max/consigne);
        demande_arr_imm=HIGH;
      }
    }  
   
    litRIS=!litRIS;
    
    // demande de conversion analogique suivante
    if (litRIS) ADMUX=(0xf0 & ADMUX) | RIS ;     // A7 au multiplexeur 
    else        ADMUX=(0xf0 & ADMUX) | LIS ;     // A6 
    ADCSRA |=(1 << ADSC);            // mise à 1 du bit ADSC du registre ADCSRA (demande de conversion)   
  }
} 

// masque de l'écran de base
void Ecran_base()
{
  oled.setInvertMode(0);
  oled.setFont(System5x7);
  oled.clear();
  oled.set2X();
  oled.println(F("Portail FS")); 
  oled.set1X();
  //oled.setScrollMode(SCROLL_MODE_AUTO);
  oled.setScrollMode(SCROLL_MODE_OFF);
  oled.setCursor(0,ligne_pos);oled.print(F("Pos=0"));
  oled.setCursor(0,7);oled.print(F("Intensite MAX="));oled.println(intensite_max);
}

void ecrit_eprom()
{
  EEPROM.write(0,Sens_Ouv); 
  EEPROM.write(1,PPS); 

  EEPROM.write(3,Tps_fonctionnement);
  EEPROM.write(4,dist_dec >> 8);    // 2 octets
  EEPROM.write(5,dist_dec & 0xFF);   
  EEPROM.write(6,Tps_acc);
  EEPROM.write(7,Tps_dec);
  EEPROM.write(8,intensite_max >>8);
  EEPROM.write(9,intensite_max & 0xFF); 
  EEPROM.write(10,pos_ferme >>8);
  EEPROM.write(11,pos_ferme & 0xFF); 
}

void lit_eprom()
{
   Sens_Ouv=EEPROM.read(0);           // sens de l'ouverture
   PPS=EEPROM.read(1);                // mode de fonctionnement : Avance / Arret / Recul  (sinon Avance / Recul) 
   Tps_fonctionnement=EEPROM.read(3); // temps maximal de fonctionnement
   dist_dec=EEPROM.read(4)*256+EEPROM.read(5);    // paramètre sur 2 octets (int) au moins 500
   Tps_acc=EEPROM.read(6);           
   Tps_dec=EEPROM.read(7);
   intensite_max=EEPROM.read(8)*256+EEPROM.read(9);
   pos_ferme=EEPROM.read(10)*256+EEPROM.read(11);
   // intensite_max=1500;  // &&
   
   if ((Sens_Ouv>1) | (Sens_Ouv<0)) Sens_Ouv=1;
   if ((PPS>1) | (PPS<0)) PPS=1;
   if ((Tps_fonctionnement>99) | (Tps_fonctionnement<1)) Tps_fonctionnement=99;
   if ((dist_dec>3000) | (dist_dec<500)) dist_dec=500;  
  
   if ((Tps_acc>30) | (Tps_acc<2)) Tps_acc=10;
   if ((Tps_dec>30) | (Tps_dec<2)) Tps_dec=10;

   if (intensite_max<=0) intensite_max=500;
        
   Serial.print(F("Sens ouverture="));Serial.println(Sens_Ouv);
   Serial.print(F("Sequentiel="));Serial.println(PPS);
   Serial.print(F("Tps fonctionnement maxi="));Serial.println(Tps_fonctionnement); 
   Serial.print(F("Distance ralenti="));Serial.println(dist_dec);
   Serial.print(F("Tps acc="));Serial.println(Tps_acc);
   Serial.print(F("Tps dec="));Serial.println(Tps_dec);
   Serial.print(F("Courant Max="));Serial.println(intensite_max);
   Serial.print(F("Position Fdc ferme="));Serial.println(pos_ferme);
}

// Arrêt moteur sur pente de décélération
void arret()
{
  oled.setCursor(0,2); s=F("Arret          ");oled.println(s);
  oled.setCursor(0,5);oled.println(vide);
  Serial.println(s); 

  if (Fc_ferme==LOW) 
  {
    increment=anc_consigne/Tps_acc;
    cons_loc=anc_consigne;
  }
              
  i=0;
  // pente de décélération
  decel=HIGH;  
  do
  {
    ++i;
    //Serial.println(cons_loc);     
    cons_loc=cons_loc-increment;
    if ( ((Sens_Ouv==1) & (avance_cours)) | ((Sens_Ouv==0) & (avance_cours)) )
    {
      analogWrite(LPWM,cons_loc);
      analogWrite(RPWM,0);
    }
    if ( ((Sens_Ouv==1) & (recul_cours)) | ((Sens_Ouv==0) & (recul_cours)) )
    {
      analogWrite(LPWM,0);
      analogWrite(RPWM,cons_loc); 
    }        
    delay(100);
  }
  while ((!Fc_ouvert) & (!Fc_ferme) & (i<Tps_acc) & (cons_loc>0)) ;  // sort si Fc_ferme=HIGH ou Fc_ouvert=HIGH ou i>=Tps_act  
  cons_loc=0;
  analogWrite(RPWM,0);
  analogWrite(LPWM,0);
  tps_marche=1;   // lance la tempo de retombée du relais K1
  demande_arret=LOW;      // raz flag demande arret
  avance_cours=LOW;
  recul_cours=LOW;
  arrete=HIGH;
  trajet_long=LOW;
  cpt_mvt=0;
  cpt_mvt_10=0;
  anc_consigne=0;
  decel=LOW;  
  consigne=0;
  dem_aff_pos=HIGH;
}

//-------------------------------------------------- I N I T I A L I S A T I O N S -------------------------------------------------
void setup() 
{
  // Initialisations de la liaison série USB
  Serial.begin(115200);     // USB
  
  // ports d'entrées et de sorties
  pinMode(RPWM,OUTPUT);
  pinMode(LPWM,OUTPUT);
  pinMode(infomarche,OUTPUT);
  pinMode(BpP,INPUT);
  pinMode(BpM,INPUT);
  pinMode(BpE,INPUT);
  pinMode(BpEch,INPUT);
  pinMode(Fuse,INPUT);
  pinMode(Commande,INPUT);
  pinMode(FcFerme,INPUT);
  pinMode(FcOuvert,INPUT);
  pinMode(Cellule,INPUT);
  pinMode(radiorelL,INPUT_PULLUP);
  pinMode(radiorelR,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  
  digitalWrite(infomarche,LOW);
  
  Serial.println(F("Programme portail FS - F1IWQ 2022\r\nTapez ? pour l'aide"));

  // initialisation de la conversion analogique
  // nota: on ne peut pas utiliser analogRead qui dure 100µS ce qui est beaucoup trop long.
  // On utlise donc les convertiseurs de façon asynchrone. (demande de conv et lecture de la valeur plus tard)
  ADMUX |= (1 << REFS0);  // référence de tension interne
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // prédivision à 128
  ADCSRA |= (1 << ADEN);  //valide le convertisseur

  // Initialisation des variables
  chaine="";
  chaineEnCours="";
  erreur=0;
  AncErreur=0;
  nombre_bip=0;
  tps_marche=0;
  Max_bip=0;
  HauteurBuz=3;
  //pos_ferme=1000; //&&&
  vide=F("                      ");
  
  menu=LOW;          // pas mode menu
  trajet_long=LOW;   // mémorise qu'un trajet a été fait de Fdc à Fdc sans arret, pour valider la position de fermeture
  demande_recul_imm=LOW;
  demande_arr_imm=LOW;
  arrete=HIGH;
  Cellule_ok=HIGH;   // provoque le message cellule coupée au démarrage si la cellule est coupée
  debug=LOW;
  marche_buz=LOW;
  for (i=20 ; i<160 ; i++)
  {
    tone(buzzer,i*10);
    delay(5);
  }
  for (i=20 ; i<160 ; i++)
  {
    tone(buzzer,(160-i)*10);
    delay(5);
  }
  noTone(buzzer);
     
  // lecture de la configuration et des télécommandes mémorisées
  lit_eprom();
  
  // I2C pour oled
  Wire.begin();
  Wire.setClock(400000L);
 
  // oled sans reset ------------------------------
  #if RST_PIN >= 0
   oled.begin(&Adafruit128x64,I2C_ADDRESS,RST_PIN);
  #else // RST_PIN >= 0
    oled.begin(&Adafruit128x64,I2C_ADDRESS);
  #endif // RST_PIN >= 0
  
  Ecran_base();
  
  // ne plus utiliser tone après l'initialisation du timer 1
  // initialisation interruption Timer 1
  timer=217;
  Timer1.initialize(timer);  // interruption timer 1 toutes les 217,01388 micro secondes (0,217 ms) (4608 Hz)
  Timer1.attachInterrupt(Interrupt_T1);
 
  arret();


}

// renvoie HIGH si le bouton + est à 1 depuis 0,2 seconde
bool Etat_BoutonP()
{
  dem_inc_boutonP=!digitalRead(BpP);  // si bouton=0, incrémenter la tempo d'appui dans timer
  if (!dem_inc_boutonP) Temps_boutonP=0;
  if (Temps_boutonP>500) Tempo_menu=1;  // réarmement de la temporisation de sortie du mode menu
  return (Temps_boutonP>500) ;          // si tempo d'appui>0,2 s ok
}

bool Etat_BoutonM()
{
  dem_inc_boutonM=!digitalRead(BpM);  // si bouton=0, incrémenter la tempo d'appui
  if (!dem_inc_boutonM) Temps_boutonM=0;
  if (Temps_boutonM>500) Tempo_menu=1;
  return (Temps_boutonM>500) ;            // si tempo d'appui>0,2 s ok
}

bool Etat_BoutonE()
{
  dem_inc_boutonE=!digitalRead(BpE);  // si bouton=0, incrémenter la tempo d'appui dans timer
  if (!dem_inc_boutonE) Temps_boutonE=0;
  if (Temps_boutonE>500) Tempo_menu=1;
  return (Temps_boutonE>500) ;            // si tempo d'appui>0,2 s ok
}

bool Etat_BoutonEch()
{
  dem_inc_boutonEch=!digitalRead(BpEch);  // si bouton=0, incrémenter la tempo d'appui
  if (!dem_inc_boutonEch) Temps_boutonEch=0;
  if (Temps_boutonEch>500) Tempo_menu=1;
  return (Temps_boutonEch>500) ;            // si tempo d'appui>0,2 s ok
}

// Arrêt moteur sans pente de décélération
void proc_arret_immediat()
{
  decel=HIGH;  
  oled.setCursor(0,2); s=F("Arret Immediat        ");oled.println(s);
  oled.setCursor(0,5);oled.println(vide);
  Serial.println(s); 

  cons_loc=0;
  analogWrite(RPWM,0);
  analogWrite(LPWM,0);
  tps_marche=1;
 
  demande_arret=LOW;      // raz flag demande arret
  avance_cours=LOW;
  recul_cours=LOW;
  arrete=HIGH;
  trajet_long=LOW;
  cpt_mvt=0;
  cpt_mvt_10=0;
  anc_consigne=0;
  consigne=0;
  decel=LOW;  
}

void proc_recul()
{
  if ((Cellule_ok) | HIGH)  // on autorise le recul sur cellule coupée
  {
    if (Fc_ouvert==LOW) 
    {  
      if (avance_cours)   // inversion
      {
        Serial.println(F("Inversion"));
        s_consigne=consigne;
        arret();
        consigne=s_consigne;
      }

      recul=HIGH;
      avance=LOW;
      avance_cours=LOW;
      recul_cours=HIGH;
      arrete=LOW;
      
      digitalWrite(infomarche,HIGH);tps_marche=0;
      
      // si on est dans la zone de ralenti, obliger consigne lente
      if (pos<dist_dec) consigne=lent;
      Serial.print(F("Ancienne consigne a "));Serial.print(anc_consigne);Serial.print(F(" - Recul a "));Serial.println(consigne);
      oled.setCursor(0,2); s=F("Recul          ");oled.println(s);
      increment=(consigne-anc_consigne)/Tps_acc;
      cons_loc=anc_consigne;             
      i=0;
      accel=HIGH;
      do
      {
        ++i;
        //Serial.println(cons_loc);  
        cons_loc=cons_loc+increment;
        if (Sens_Ouv==1)
        {
          analogWrite(LPWM,0);
          analogWrite(RPWM,cons_loc);
        }
        else
        {
          analogWrite(LPWM,cons_loc);
          analogWrite(RPWM,0); 
        }        
        delay(100);
      }
      while ((!Fc_ouvert) and (i<Tps_acc)) ;  // sort si Fc_ferme=HIGH ou i>=Tps_act 
      tempo_apres_acc=1;  // démarre la tempo après accélération
      accel=LOW;
    }  
  }
  else Serial.println(F("Cellule nok"));  
  anc_consigne=consigne;
  if (Fc_ouvert) proc_arret_immediat();
}


void proc_avance()
{ 
  if (Cellule_ok)
  {
    if (Fc_ferme==LOW) 
    {    
      if (recul_cours)   // inversion
      {
        Serial.println(F("Inversion"));
        s_consigne=consigne;
        arret();
        consigne=s_consigne;
      }

      recul=LOW;
      avance=HIGH;
      avance_cours=HIGH;
      recul_cours=LOW;
      arrete=LOW;
      
      digitalWrite(infomarche,HIGH);tps_marche=0;

      if (Fc_ouvert) trajet_long=HIGH; // début de la séquence d'un mouvement complet de Fc_ouvert à Fc_ferme pour le comptage temps maxi

      // si on est dans la zone de ralenti, obliger consigne lente
      if (pos>pos_ferme-dist_dec) consigne=lent;
      Serial.print(F("Ancienne consigne a "));Serial.print(anc_consigne);Serial.print(F(" - Avance a "));Serial.println(consigne);
      oled.setCursor(0,2); s=F("Avance         ");oled.println(s);
      increment=(consigne-anc_consigne)/Tps_acc;
      cons_loc=anc_consigne;

      // pente d'accélération
      i=0;
      accel=HIGH;
      do
      {
        ++i;
        //Serial.println(cons_loc);  
        cons_loc=cons_loc+increment;
        if (Sens_Ouv==1)
        {
          analogWrite(LPWM,cons_loc);
          analogWrite(RPWM,0);
        }
        else
        {
          analogWrite(LPWM,0);
          analogWrite(RPWM,cons_loc); 
        }        
        delay(100);
      }
      while ((!Fc_ferme) and (i<Tps_acc)) ;  // sort si Fc_ferme=HIGH ou i>=Tps_act 
      tempo_apres_acc=1;  // démarre la tempo après accélération
      accel=LOW;
    }
  } 
  else Serial.println(F("Cellule nok"));  
  anc_consigne=consigne;
  if (Fc_ferme) {proc_arret_immediat();} 
}


// traitement de fond à effectuer à chaque itération-----------------------
void traitement()
{
  ++iteration;
  if (iteration>32000) iteration=0;  
  
  // lecture des fins de course et des autres entrées
  // Etats précédents (n-1)

  Anc_BpP=Etat_BpP;
  Anc_BpM=Etat_BpM;
  Anc_BpE=Etat_BpE;
  Anc_BpEch=Etat_BpEch; 

  // Etats actuels (n)
  Etat_BpP=Etat_BoutonP();
  Etat_BpM=Etat_BoutonM();
  Etat_BpE=Etat_BoutonE();
  Etat_BpEch=Etat_BoutonEch();
  
  // Fronts montants !(n-1) & (n)
  Fm_P=!Anc_BpP & Etat_BpP;
  Fm_M=!Anc_BpM & Etat_BpM;
  Fm_E=!Anc_BpE & Etat_BpE;
  Fm_Ech=!Anc_BpEch & Etat_BpEch;

  // vérification temps de mvt
  if (cpt_mvt>Tps_fonctionnement) 
  {
    Serial.println(F("Arret par tps>fonctionnement long"));
    arret();
    erreur=4;
  }

  // recul immédiat
  if (demande_recul_imm)
  {
    demande_recul_imm=LOW;
    s=F("Demande recul immediat ");
    Serial.println(s); 
    oled.setCursor(0,2);oled.print(s);
    arret();
    consigne=lent;
    proc_recul();  
  }
  
  // arret immédiat (sans décélération)
  if (demande_arr_imm) 
  {
    demande_arr_imm=LOW;
    //s=F("Demande arret immediat B");
    //Serial.println(s); 
    //oled.setCursor(0,2);oled.print(s);
    proc_arret_immediat();
  }

  // affichage position  temps de fonctionnement et courant
  if (avance_cours | recul_cours | dem_aff_pos)
  {  
    if ((iteration % 400)==0)  // Affichage tous les 400 tours
    {
      dem_aff_pos=LOW;
      oled.setCursor(24,ligne_pos);oled.print(pos);oled.print(" "); 
      oled.print(cpt_mvt);oled.print("s ");
      // copie de la variable globale "intensité" dans la variable locale 
      int _intensite=intensite;
      if (_intensite!=0)
      {
        oled.print(_intensite);
        oled.print("    ");
      }  
      //Serial.print(F("Courant R="));Serial.println(courantRIS);
      //Serial.print(F("Courant L="));Serial.println(courantLIS);
    }  
  }
  /*
  if ((iteration % 200)==0)  // Affichage tous les 200 tours
  {
   Serial.print(F("Courant R="));Serial.println(courantRIS);
   Serial.print(F("Courant L="));Serial.println(courantLIS);
  }*/
  
  // avance en cours (fermeture) ----------------------------------------------
  if (avance_cours==HIGH)
  {
    if (erreur==4) erreur=0;   
       
    // Fin de course fermé ou cellule coupée arreter le mouvement d'avance
    if ((Fc_ferme) | (!Cellule_ok)) 
    {
      proc_arret_immediat();
    }
   
    // passer en pv
    if ((pos>pos_ferme-dist_dec) & (consigne==rapide))  
    {
      Serial.println(F("Position lente vers avance atteinte"));
      consigne=lent;
      proc_avance();
    }
  }  
      
  // recul en cours (ouverture) -----------------------------------------------
  if (recul_cours==HIGH)
  {
    if (erreur==4) erreur=0;
    
    // Fin de course ouvert arreter le mouvement de recul (on ne tient pas compte de la cellule en recul)
    if (Fc_ouvert)  
    {
       proc_arret_immediat();
    }
    
    // passer en PV
    if ((pos<dist_dec) & (consigne==rapide)) 
    {
      Serial.println(F("Position lente vers recul atteinte"));
      consigne=lent;
      proc_recul();
    }   
  }
  
  // récepteur radio par relais
  AncR=radioR;
  AncL=radioL;
  radioL=!digitalRead(radiorelL) ;
  radioR=!digitalRead(radiorelR) ;
  
  // effacement du message de la télécommande
  if ((tempo_affT==1) & !menu) {oled.setCursor(0,6);oled.print(vide);}
}

// tempo en 1/10 de secondes
void tempo(int valeur)
{
  val_tempo=valeur;
  do
    traitement();
  while (val_tempo!=0);
}


// fond de la page menu, page à déroulement pour afficher les paramètres
void fond_menu()
{
  // afficher 6 lignes du menu avec la valeur des paramètres
  for (i=0 ; i<6 ; i++)
  {
    oled.setCursor(6,i+offset);oled.print(ligne_menu_S[i+decale]+vide);
    // paramètres
    if (i+decale+1==ligne_Param_sens) {oled.setCursor(108,i+offset);oled.print(Sens_Ouv);}
    if (i+decale+1==ligne_Param_PPS)  {oled.setCursor(84,i+offset);oled.print(PPS);}
    if (i+decale+1==ligne_tpsmax)     {oled.setCursor(108,i+offset);oled.print(Tps_fonctionnement);}
    if (i+decale+1==ligne_acc)        {oled.setCursor(66,i+offset);oled.print(Tps_acc);}
    if (i+decale+1==ligne_dec)        {oled.setCursor(66,i+offset);oled.print(Tps_dec);}
    if (i+decale+1==ligne_dist_dec)   {oled.setCursor(70,i+offset);oled.print(dist_dec);}
  }    
}

int coordY()
{
  return (ligne_menu+offset-decale-1);
}

void serialFlush()
{
  while(Serial.available() > 0) 
  {
    Serial.read();
  }
}

// ------------------------------------------------ P R O G R A M M E   P R I N C I P A L --------------------------------------------
void loop() 
{
  traitement();    // traitement de fond 
  if (debug)
  {  
    if (((avance_cours | recul_cours)) & (intensite!=0)) 
    {
      if (consigne==lent) Serial.print("L "); else Serial.print("R ");
      Serial.println(intensite);
    }
  }  
  
  if (!menu)
  { 
    // affichage erreur
    if ( (AncErreur==0) & ((erreur==1) | (erreur==2)) )
    { 
      AncErreur=erreur;
      s=F("Courant moteur elevé");
      Max_bip=erreur;
      tps_erreur=1;
      Serial.println(s);
      oled.setCursor(0,ligne_erreur);oled.print(s);
      oled.print(vide);

      if (erreur==1) {consigne=lent;proc_recul();}
    }

    /*
    if ((AncErreur==1) & (erreur==0))
    { 
      AncErreur=erreur;
      oled.setCursor(0,ligne_erreur);oled.print(vide);
    }
    */

    if ((AncErreur==0) & (erreur==4))
    { 
      AncErreur=erreur;
      s=F("Erreur mvt trop long");
      tps_erreur=1;
      Max_bip=4;
      oled.setCursor(0,ligne_erreur);oled.print(s);
      oled.print(vide);
      Serial.println(s);
    }  

    if ((AncErreur==0) & (erreur==3))
    { 
      AncErreur=erreur;
      Max_bip=3; 
      tps_erreur=1;
      
      arret();
      s=F("Fusible F1 HS");
      oled.setCursor(0,ligne_erreur);oled.print(s);
      oled.print(vide);
      Serial.println(s);   
    }  

    if ((AncErreur!=0) & (erreur==0))
    { 
      AncErreur=erreur;
      Max_bip=0;
      //oled.setCursor(0,ligne_erreur);oled.print(vide);
      Ecran_base();
    }
    
   
    // Affichage Evt Fdc et cellule ----------------------------------------------------------
    if ((Fc_ferme) & (Fc_ouvert) & (msg_fdc!=1)) 
    {
      s=F("Fdc ouvert et ferme ");
      msg_fdc=1;
      Serial.println(s);
      oled.setCursor(0,4);oled.print(s);
    }
    
    if ((Fc_ferme) & (!Fc_ouvert) & (msg_fdc!=2)) 
    {
      s=F("Fdc ferme           ");
      msg_fdc=2;
      Serial.println(s);
      oled.setCursor(0,4);oled.print(s);
    }
    if ((!Fc_ferme) & (!Fc_ouvert) & (msg_fdc!=3))
    {
      Serial.println(F("Fdc ferme libéré "));
      msg_fdc=3;
      oled.setCursor(0,4);oled.print(vide);
    }
    
    if ((Fc_ouvert) & (!Fc_ferme) & (msg_fdc!=4)) 
    {
      msg_fdc=4;
      s=F("Fdc ouvert           ");
      Serial.println(s);
      oled.setCursor(0,4);oled.print(s);
    }
   

    if (Msg_cell_ok)
    {
      Msg_cell_ok=LOW;
      s=F("Cellule OK");
      Serial.println(s);
      oled.setCursor(0,6);oled.print(s);oled.print(vide);
    } 

    if (Msg_cell_nok)
    {
      Msg_cell_nok=LOW;
      s=F("Cellule occultee");
      Serial.println(s);
      oled.setCursor(0,6);oled.println(s);
    }
  }
  
  //réception des données depuis USB
  nombre=Serial.available() ; // nombre de caractères disponibles sur la liaison série
  if (nombre>0)
  {
    //Serial.println(nombre);
    for (i=0 ; i<nombre ; i++)
    {
      inByte = Serial.read();
      //Serial.print(inByte);
      //if (inByte==13) Serial.print("CR");
      //if (inByte==10) Serial.print("LF");
      if ((inByte!=13) & (inByte!=10)) chaineEnCours=chaineEnCours+inByte;
      if (inByte==13)
      {  
        //Serial.println("CR");Serial.println(chaineEnCours);
        if (menu) Tempo_menu=1;
        chaine=chaineEnCours;
        if (chaine=="") {demande_arret=!menu;Enter=HIGH;chaine="";}  // pas de demande d'arret en mode menu
        //Serial.println();
        //Serial.print("chaine=");Serial.println(chaine);
        chaineEnCours=""; 
      }
    }
  }    
  
  if (chaine=="?") 
  {
    Serial.println(F("pos     : Affiche la position"));
    Serial.println(F("cour    : Affiche les courants"));
    Serial.println(F("tar     : Avance en rapide")); 
    tempo(1);
    Serial.println(F("trr     : Recul en rapide\r\ntal     : Avance en lent\r\ntrl     : Recul en lent")); 
    tempo(1);  
    Serial.println(F("ENTREE  : Arret")); 
    Serial.println(F("e       : Etat des entrees"));   
    tempo(1);  
    Serial.println(F("simu    : Simu commande bornier"));
    Serial.println(F("menu    : Mode menu (touches 8/2 = < >)"));
    Serial.println(F("im      : Infos menu"));
    Serial.println(F("apprend : lance l'apprentissage"));
    chaine="";
  }
  else

  if (chaine==F("pos"))
  {
    Serial.print(F("Pos=")); Serial.println(pos);
    Serial.print(F("Pos ferme=")); Serial.println(pos_ferme);
    chaine="";
  }
  else

  if (chaine==F("cour"))
  {
    Serial.print(F("Courant R="));Serial.println(courantRIS);
    Serial.print(F("Courant L="));Serial.println(courantLIS);
    Serial.print(F("Courant arret L="));Serial.println(courantLIS_arr);
    Serial.print(F("Courant arret R="));Serial.println(courantRIS_arr);  
    chaine="";
  }
  else
  
  if (chaine==F("menu"))
  {
    simuMenu=HIGH;
    Serial.println(F("Mode MENU"));
    chaine="";
  }
  else

  if (chaine==F("8"))
  {
    Simu8=HIGH;
    chaine="";
    Tempo_menu=1;
  }
  else

  if (chaine==F("2"))
  {
    Simu2=HIGH;
    chaine="";
    Tempo_menu=1;
  }
  else
  
  if (chaine==F("simu"))
  {
    simu=HIGH;
    chaine="";
  }
  else

  if (chaine.substring(0,3)=="e")
  {
    Serial.print(F("Fc Ferme   ")); Serial.print(digitalRead(FcFerme));Serial.print("  ");Serial.println(Fc_ferme);
    Serial.print(F("Fc Ouvert  ")); Serial.print(digitalRead(FcOuvert));Serial.print("  ");Serial.println(Fc_ouvert);
    tempo(1);
    Serial.print(F("Cellule    ")); Serial.println(digitalRead(Cellule));
    Serial.print(F("Commande   ")); Serial.println(digitalRead(Commande));
    Serial.print(F("Bouton ECH ")); Serial.println(digitalRead(BpEch));
    tempo(1);
    Serial.print(F("Bouton E   ")); Serial.println(digitalRead(BpE));
    Serial.print(F("Bouton +   ")); Serial.println(digitalRead(BpP));
    Serial.print(F("Bouton -   ")); Serial.println(digitalRead(BpM));   
    chaine="";
  }
  else
  
  if (chaine==F("apprend"))
  {  
    menu=HIGH;
    FaireApprend=HIGH;
    chaine="";
  }
  else
    
  // avance rapide
  if (chaine==F("tar"))
  {  
    consigne=rapide;
    proc_avance();
    chaine="";
  }
  else

  // recul rapide
  if (chaine==F("trr"))
  {
    consigne=rapide;
    proc_recul();
    chaine="";
  }
  else

  // avance lente
  if (chaine==F("tal"))
  {
    consigne=lent;
    proc_avance();
    chaine="";
  }
  else

  // recul lent
  if (chaine==F("trl"))
  {
    consigne=lent;
    proc_recul();
    chaine="";
  }
  else
  
  if (chaine==F("im"))
  {
    Serial.print(F("Menu="));Serial.println(menu);
    Serial.print(F("ligne menu="));Serial.println(ligne_menu);
    Serial.print(F("Page="));Serial.println(PageMenu);
    Serial.print(F("Curseur="));Serial.println(curseur); 
    chaine="";
  }

  else
  if (chaine!="")
  {
   Serial.print(F("Commande inconnue:"));Serial.println(chaine);
   chaine="";
  }

  // demande de mouvement depuis le bornier (J4 bornes 2/7) ou radio -----------------------
  if (
      (
        Man_Bornier | 
        (!AncR & radioR) | 
        (!AncL & radioL)
      ) 
      & ((!menu & !Etat_Fus) | simu) 
     )  
   {  
    if (Man_Bornier) s=F("Commande bornier");
    if (radioL | radioR) s=F("Commande radio  ");
    Man_Bornier=LOW;
    simu=LOW;
    Serial.println(s);
    oled.setCursor(0,5);oled.println(s);
    if ((erreur==1) | (erreur==2)) erreur=0;
    
    // si arreté sur un FdC 
    if (Fc_ouvert | Fc_ferme)
    {
      if (!avance_cours & !recul_cours) 
      {
        Serial.println(F("cas1"));
        if (Fc_ouvert) {consigne=rapide;proc_avance();}
        if (Fc_ferme)  {consigne=rapide;proc_recul();}
      }  
      else 
        { if ((erreur==1) | (erreur==2)) erreur=0;
          Serial.println(F("cas2"));arret();}
    }  
    
    else
    {
      // si pas arrété sur un FdC et pas de mvt en cours
      if (!avance_cours & !recul_cours)
      {
        
        // si cellule occultée, on autorise que le recul en lent
        if (!Cellule_ok) {Serial.println(F("cas3.1"));consigne=lent;proc_recul();}
        else
        {
          // dernier mvt était recul ou avance?
          Serial.println(F("cas3.2"));
          if (recul) {consigne=rapide;proc_avance();} else {consigne=rapide;proc_recul();} 
        }  
      } 

      else
      // si mvt en cours
      {
        Serial.println(F("cas4"));
        // si (sequencement) mode Av -> arret -> recul -> arret
        if (PPS==1)
        {
          arret();
          /*
          if (consigne==lent) arret();
          if (avance_cours & (consigne==rapide)) {consigne=lent;proc_avance();tempo(Tps_dec);arret();}
          if (recul_cours & (consigne==rapide)) {consigne=lent;proc_recul();tempo(Tps_dec);arret();} 
          */
        }
        else
        // si mode Av -> Re -> Av -> Re (PPS=0)
        {
          //regarder le dernier mouvement effectué pour inverser
          Serial.println(F("cas 5"));
          MemRecul=recul;
          MemAvance=avance;  
          if (MemRecul) 
          {
            consigne=rapide;
            proc_avance();
          }
      
          if (MemAvance) 
          {
            consigne=rapide;
            proc_recul();
          }
          // si pas de dernier mouvement, reculer en lent.
          if ((avance==LOW) & (recul==LOW)) {consigne=lent;proc_recul();}
        }  
      }  
    }  
  }

  // arret ----------------------------------------------------------------
  if (demande_arret)
  {
     Serial.println(F("Demande arret"));
     arret();
     chaine="";
  }

  // Boutons hors mode menu
  if (!menu & !Etat_Fus) 
  {
    if (Fm_P) 
    {
      if ((erreur==1) | (erreur==2)) erreur=0;
      consigne=rapide;proc_avance();
    }
    if (Fm_M) 
    {
      if ((erreur==1) | (erreur==2)) erreur=0;
      consigne=rapide;proc_recul();
    } 
    if (Fm_Ech & (recul_cours | avance_cours))
    {
      Serial.println(F("Arret par BP"));
      if ((consigne==rapide) & recul_cours) {consigne=lent;proc_recul();tempo(Tps_dec);}
      if ((consigne==rapide) & avance_cours) {consigne=lent;proc_avance();tempo(Tps_dec);}   
      arret();
    }
  }

  // gestion écrans -----------------------------------------------
 
  // entrée en mode MENU
  if ( ((Temps_boutonE>5000) | simuMenu) & (!menu) )
  {
    arret();       // arret de tout mouvement
    Seq=0;         // Séquence 0
    Fm_E=LOW;      // reforcer pas front montant touche entrée puisque appui long  
    Tempo_menu=1;  // initialisation de la tempo menu
    simuMenu=LOW;
    dem_aff_pos=LOW;
    Enter=LOW;
    menu=HIGH;
    curseur=HIGH;  // autoriser le curseur
    oled.clear();
    oled.set2X();
    oled.setCursor(15,0);oled.println(F("**MENU**")); 
    oled.set1X();
    decale=0;      // décalage 0 (descente plus bas que l'affichage)
    ligne_menu=premiere_ligneM; 
    derniere_ligne=derniere_ligneM;
    premiere_ligne=premiere_ligneM;
    offset=offset_M;
    fond_menu();
    PageMenu=1;
    oled.setCursor(0,offset);oled.write(">");
        
    // attendre relache bouton ENTREE
    do 
    {
      tempo(1);
    }  
    while (digitalRead(BpE)==0); 
  }

  // boutons en mode MENU
  if (menu)
  {
    // sortie du mode MENU
    if ( (Fm_Ech & (Seq==0)) | (Tempo_menu>Tempo_sortie_menu) )
    {
      Serial.print(F("sortie du menu "));
      if (Fm_Ech) Serial.println(F("Bouton ECH"));
      if (Seq==0) Serial.println(F("Seq=0"));
      if (Tempo_menu>Tempo_sortie_menu) Serial.println(F("Tempo"));
      
      simuMenu=LOW;   
      menu=LOW;
      curseur=LOW;
      PageMenu=0;
      Tempo_menu=0;   // figeage à 0 de la tempo menu
      Ecran_base();  
    }

    // descente curseur
    if ( (Fm_P | Simu2) & menu & curseur)  
    {
      Enter=LOW;
            
      if (ligne_menu<derniere_ligne)
      {
        if (ligne_menu-decale+offset<8)
        {
          oled.setCursor(0,coordY());oled.println(" ");
          ++ligne_menu;
          oled.setCursor(0,coordY());oled.println(">");
        }
        else 
        {
          // on descend plus bas que la dernière ligne déclarée pour l'affichage
          if (ligne_menu<derniere_ligne) 
          { 
            ++decale;
            ++ligne_menu;
            if (PageMenu==1) fond_menu();
            oled.setCursor(0,coordY());oled.println(">");
          }          
        }       
        Seq=0;
      }
      Simu2=LOW;
      //Serial.print("ligne menu=");Serial.print(ligne_menu);Serial.print(" decale=");Serial.print(decale);Serial.print(" offset=");Serial.println(offset);
    }
    
    // montée curseur
    if ( (Fm_M | Simu8) & menu & curseur)
    {
      Enter=LOW;
      if (ligne_menu-decale>premiere_ligne)
      {
        oled.setCursor(0,coordY());oled.println(" ");
        --ligne_menu;
        //Serial.print("A");Serial.println(ligne_menu);
        oled.setCursor(0,coordY());oled.println(">");
      } 
      else 
      if (decale>0)
      {
        --decale;
        --ligne_menu;
        //Serial.print("B");Serial.println(ligne_menu);
        if (PageMenu==1) fond_menu();
        oled.setCursor(0,coordY());oled.println(">");
      }
      Seq=0;
      Simu8=LOW;
      //Serial.print("ligne menu=");Serial.print(ligne_menu);Serial.print(" decale=");Serial.print(decale);Serial.print(" offset=");Serial.println(offset);
    }

    // écran 1
    // apprentissage
    if ( (((PageMenu==1) & menu) | FaireApprend ) & Cellule_ok & !Etat_Fus & !(Fc_ouvert & Fc_ferme))
    {
      if ( ((ligne_menu==ligne_aprentiss) & (Enter | Fm_E) ) | FaireApprend) 
      {
        curseur=LOW;
        FaireApprend=LOW;
        Tempo_menu=0;
        Enter=LOW;  
        oled.clear();
        oled.set2X();
        s=F("Apprentiss.");
        oled.print(s);
        oled.set1X();
        Serial.println(s);
        arret();  
        serialFlush();
        oled.setCursor(0,ligne_pos);oled.print(F("Pos="));
        intensite_max=4095;
        
        // si on est sur le Fdc arrière (ouvert), avancer pour se dégager      
        if (Fc_ouvert) 
        {
           consigne=lent;
           proc_avance(); 
           oled.setCursor(0,4);oled.print(F("Degagement  "));
           Serial.println(F("Dégagement arrière"));
           do
           {
             traitement();
           }
           while ( Fc_ouvert & (Serial.available()==0) & !Fm_Ech) ;
           proc_arret_immediat();
           Serial.println(F("Fdc arriere libere"));
        }
        
        // reculer pour accoster le FdC ouvert
        consigne=lent;
        proc_recul(); 
        s=F("recul lent");
        oled.setCursor(0,4);oled.print(s);
        Serial.println(s);
        do
        {
          traitement();
        }
        while ( (!Fc_ouvert) & (Serial.available()==0) & !Fm_Ech) ;
        proc_arret_immediat();
        
        if (Fc_ouvert)
        {
          s=F("prise origine faite  ");
          oled.setCursor(0,4);oled.println(s);
          Serial.print(s);
          s=F("Avance lente");
          oled.setCursor(0,5);oled.println(s);
          Serial.println(s);         
        }  
        delay(500);
        
        // avancer en lent vers le FdC ferme (avant) pour trouver la position du Fdc avant       
        dem_aff_pos=HIGH;
        consigne=lent;              
        proc_avance(); // avancer pour trouver le FDC avant
        do
        {
          traitement();
        }  
        while ( !Fc_ferme & (Serial.available()==0) & !Fm_Ech);
        if (Serial.available()!=0) Serial.println(F("Arret par liaison serie"));
        if (Fm_Ech) Serial.println(F("Arret par ECH"));
        
        proc_arret_immediat();
        if ((Fc_ferme) & (pos>500))
        {
          s=F("Position finale mesuree ");
          oled.setCursor(0,4);oled.println(s);
          Serial.println(s);
        }  

        if ((Fc_ferme) & (pos<500))
        {
          s=F("Erreur position      ");
          oled.setCursor(0,4);oled.println(s);
          Serial.println(s);
        }  
  
        // aller chercher le FDC recul pour mesurer le courant en reculant ----------
        if (!Fm_Ech) // si pas appui sur bp ECH
        {         
          tempo(20);
          consigne=rapide;
          proc_recul();
          s=F("Mesure courant max recul  ");
          oled.setCursor(0,4);oled.println(s);
          oled.println(vide);
          Serial.println(s);
          _intensite_max=0;
          do
          {
            traitement();  
            int _intensite=intensite;
            if ((_intensite_max<_intensite) & (!accel) & (!decel) & (tempo_apres_acc==0)) 
            {
              _intensite_max=_intensite;
              Serial.println(_intensite);
            }
          }  
          while ( (!Fc_ouvert) & (Serial.available()==0) & !Fm_Ech );
          inByte = Serial.read();  // vide tampon 
          proc_arret_immediat();
        }  
        oled.setCursor(0,4);oled.println(vide);

        // aller chercher le FDC avance pour mesurer le courant en avance---------
        if (!Fm_Ech) // si pas appui sur bp ECH
        {    
          tempo(20);
          consigne=rapide;
          proc_avance();
          s=F("Mesure courant max avance ");
          oled.setCursor(0,4);oled.println(s);oled.println(vide);
          Serial.println(s);
          do
          {
            traitement();  
            int _intensite=intensite;
            if ((_intensite_max<_intensite) & (!accel) & (!decel) & (tempo_apres_acc==0)) 
            {
              _intensite_max=_intensite;
              Serial.println(_intensite);
            }
          }  
          while ( (!Fc_ferme) & (Serial.available()==0) & !Fm_Ech );
          inByte = Serial.read();  // vide tampon 
          proc_arret_immediat();
        }  
        oled.setCursor(0,4);oled.println(vide);

        if (_intensite_max>50)
        {
          intensite_max=_intensite_max;
          s=F("courant max=");
          Serial.print(s);Serial.print(intensite_max);
          oled.setCursor(0,5);oled.print(s);oled.print(intensite_max); 
          intensite_max=intensite_max+((intensite_max*10)/100);
          if (intensite_max>4095) intensite_max=4095;
          s=F(" +10%=");
          Serial.print(s);Serial.println(intensite_max);
          oled.setCursor(0,6);oled.print(s);oled.print(intensite_max); 
          oled.setCursor(0,7);oled.print("Sauvegarde EPROM");
          ecrit_eprom();   // mémorise les positions avance et recul ralentissement
        }
        else 
        {
          s=F("Erreur mesure courant");
          Serial.println(s);
          oled.setCursor(0,5);oled.print(s);   
        }
        
        dem_aff_pos=LOW;
        tempo(50);
        Enter=LOW;
        simuMenu=HIGH;  // retour en page menu
        menu=LOW;
        Tempo_menu=1;
      }
    
      // Paramètre sens d'ouverture
      if ((ligne_menu==ligne_Param_sens) & (PageMenu==1))
      {
        if ((Seq==0) & (Enter | Fm_E))
        {
          curseur=LOW;
          oled.setInvertMode(1);
          Sens_Ouv_P=Sens_Ouv;            // variable provisoire
          oled.setCursor(108,coordY());oled.print(Sens_Ouv_P);
          Seq=1;
          Enter=LOW;
          Fm_E=LOW;
          Tempo_menu=1;
        }  
        if (Seq==1)
        {
          if (Fm_P | Simu8) 
          {
            Sens_Ouv_P=1;
            oled.setCursor(108,coordY());oled.print(Sens_Ouv_P);
            Simu8=LOW;
          }
          if (Fm_M | Simu2) 
          {
            Sens_Ouv_P=0;
            oled.setCursor(108,coordY());oled.print(Sens_Ouv_P);
            Simu2=LOW;
          }
          if (Fm_E | Enter) // validation
          {
            Sens_Ouv=Sens_Ouv_P;
            oled.setInvertMode(0);
            oled.setCursor(108,coordY());oled.print(Sens_Ouv);
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }
          if (Fm_Ech)  // annulation
          {
            oled.setInvertMode(0);
            oled.setCursor(108,coordY());oled.print(Sens_Ouv);
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }  
        }
      }  
      
      // paramètre PPS
      if ((ligne_menu==ligne_Param_PPS) & (PageMenu==1))
      {
        if ((Seq==0) & (Enter | Fm_E))
        {
          curseur=LOW;
          oled.setInvertMode(1);
          PPS_P=PPS;            // variable provisoire
          oled.setCursor(84,coordY());oled.print(PPS_P);
          Seq=1;
          Enter=LOW;
          Fm_E=LOW;
        }  
        if (Seq==1)
        {
          if (Fm_P | Simu8) 
          {
            PPS_P=1;
            oled.setCursor(84,coordY());oled.print(PPS_P);
            Simu8=LOW;
          }
          if (Fm_M | Simu2) 
          {
            PPS_P=0;
            oled.setCursor(84,coordY());oled.print(PPS_P);
            Simu2=LOW;
          }
          if (Fm_E | Enter) // validation
          {
            PPS=PPS_P;
            oled.setInvertMode(0);
            oled.setCursor(84,coordY());oled.print(PPS);
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }
          if (Fm_Ech)  // annulation
          {
            oled.setInvertMode(0);
            oled.setCursor(84,coordY());oled.print(PPS);
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }  
        } 
      }
              
      // Sauvegarde EPROM
      if ((ligne_menu==ligne_eprom) & (PageMenu==1))
      {
        if (Fm_E | Enter) // validation
        {
          Enter=LOW;
          oled.setCursor(6,coordY());
          oled.setInvertMode(1);
          oled.println(F("Sauvegarde EPROM")); 
          ecrit_eprom(); 
          tempo(10);
          oled.setCursor(6,coordY());
          oled.setInvertMode(0);
          oled.println(F("Sauvegarde EPROM"));       
        }
      }
        
      if ((ligne_menu==ligne_ES) & (PageMenu==1))
      {
        if ((Seq==0) & (Fm_E | Enter)) // validation
        {
          curseur=LOW;
          Enter=LOW;
          oled.clear();
          oled.set2X();
          oled.setCursor(0,0);oled.println(F("**Entrees**")); 
          oled.set1X();
          oled.setCursor(0,3);
          oled.println(F("Cellule       :"));
          oled.println(F("Commande      :"));
          oled.println(F("Fc recul      :"));
          oled.println(F("Fc avance     :"));
          Seq=1;
          Tempo_menu=2;
          Enter=LOW;         
        }
        // affichage dynamique des entrées
        if (Seq==1)
        {
          oled.setCursor(100,3),oled.print(digitalRead(Cellule));
          oled.setCursor(100,4),oled.print(digitalRead(Commande));
          oled.setCursor(100,5),oled.print(digitalRead(FcOuvert));
          oled.setCursor(100,6),oled.print(digitalRead(FcFerme));
          if (Fm_Ech)  // annulation
          {
            // retour en page menu
            menu=LOW;
            simuMenu=HIGH;
          }  
        }      
      }
      
      // paramètre temps de fonctionnement maximal
      if ((ligne_menu==ligne_tpsmax) & (PageMenu==1))
      {
        if ((Seq==0) & (Enter | Fm_E))
        {
          curseur=LOW;
          oled.setInvertMode(1);
          Tps_fonc_P=Tps_fonctionnement;            // variable provisoire
          oled.setCursor(108,coordY());oled.print(Tps_fonc_P);
          Seq=1;
          Fm_E=LOW;
          Enter=LOW;
        }  
        if (Seq==1)
        {
          if ((Fm_P | Simu2) & (Tps_fonc_P<99)) 
          {
            ++Tps_fonc_P;
            oled.setCursor(108,coordY());oled.print(Tps_fonc_P);
            Simu2=LOW;
          }
          if ((Fm_M | Simu8) & (Tps_fonc_P>2))  
          {
            --Tps_fonc_P;
            oled.setCursor(108,coordY());oled.print(Tps_fonc_P);
            Simu8=LOW;
          }
          if (Fm_E | Enter) // validation
          {
            Tps_fonctionnement=Tps_fonc_P;
            oled.setInvertMode(0);
            oled.setCursor(108,coordY());oled.print(Tps_fonctionnement);
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }
          if (Fm_Ech)  // annulation
          {
            oled.setInvertMode(0);
            oled.setCursor(108,coordY());oled.print(Tps_fonctionnement);
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }  
        } 
      }
     
      // paramètre temps d'accélération
      if ((ligne_menu==ligne_acc) & (PageMenu==1))     
      {
        if ((Seq==0) & (Enter | Fm_E))
        {
          curseur=LOW;
          oled.setInvertMode(1);
          Tps_accP=Tps_acc;            // variable provisoire
          oled.setCursor(66,coordY());oled.print(Tps_accP);
          Seq=1;
          Fm_E=LOW;
          Enter=LOW;
        }  
        if (Seq==1)
        {
          if ((Fm_P | Simu2) & (Tps_accP<20)) 
          {
            ++Tps_accP;
            oled.setCursor(66,coordY());oled.print(Tps_accP);
            Simu2=LOW;
          }
          if ((Fm_M | Simu8) & (Tps_accP>2))  
          {
            --Tps_accP;
            oled.setCursor(66,coordY());oled.print(Tps_accP);oled.print(" ");
            Simu8=LOW;
          }
          if (Fm_E | Enter) // validation
          {
            Tps_acc=Tps_accP;
            oled.setInvertMode(0);
            oled.setCursor(66,coordY());oled.print(Tps_acc);
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }
          if (Fm_Ech)  // annulation
          {
            oled.setInvertMode(0);
            oled.setCursor(66,coordY());oled.print(Tps_acc);oled.print(" ");
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }  
        }  
      }
    
      // paramètre décélération
      if ((ligne_menu==ligne_dec) & (PageMenu==1))     
      {
        if ((Seq==0) & (Enter | Fm_E))
        {
          curseur=LOW;
          oled.setInvertMode(1);
          Tps_decP=Tps_dec;            // variable provisoire
          oled.setCursor(66,coordY());oled.print(Tps_decP);
          Seq=1;
          Fm_E=LOW;
          Enter=LOW;
        }  
        if (Seq==1)
        {
          if ((Fm_P | Simu2) & (Tps_decP<20)) 
          {
            ++Tps_decP;
            oled.setCursor(66,coordY());oled.print(Tps_decP);
            Simu2=LOW;
          }
          if ((Fm_M | Simu8) & (Tps_decP>2))  
          {
            --Tps_decP;
            oled.setCursor(66,coordY());oled.print(Tps_decP);oled.print(" ");
            Simu8=LOW;
          }
          if (Fm_E | Enter) // validation
          {
            Tps_dec=Tps_decP;
            oled.setInvertMode(0);
            oled.setCursor(66,coordY());oled.print(Tps_dec);
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }
          if (Fm_Ech)  // annulation
          {
            oled.setInvertMode(0);
            oled.setCursor(66,coordY());oled.print(Tps_dec);oled.print(" ");
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }  
        }  
      }
      
      // paramètre distance de décélération
      if ((ligne_menu==ligne_dist_dec) & (PageMenu==1))     
      {
        if ((Seq==0) & (Enter | Fm_E))
        {
          curseur=LOW;
          oled.setInvertMode(1);
          dist_decP=dist_dec;            // variable provisoire
          oled.setCursor(70,coordY());oled.print(dist_decP);
          Seq=1;
          Fm_E=LOW;
          Enter=LOW;
        }  
        if (Seq==1)
        {
          if ((Etat_BpP | Etat_BpM) & (delayautorepeat<1000)) ++delayautorepeat;        
          if (!Etat_BpP & !Etat_BpM) {delayautorepeat=0;autorepeat=0;}
                
          if ( (Fm_P | Simu2 | (Etat_BpP & (autorepeat==50)) ) & (dist_decP<3000) ) 
          {
            ++dist_decP;
            oled.setCursor(70,coordY());oled.print(dist_decP);oled.print(" ");
            Simu2=LOW;
          }
          if ( (Fm_M | Simu8 | (Etat_BpM & (autorepeat==50)) ) & (dist_decP>2) )  
          {
            --dist_decP;
            oled.setCursor(70,coordY());oled.print(dist_decP);oled.print(" ");
            Simu8=LOW;
          }
          if (Fm_E | Enter) // validation
          {
            dist_dec=dist_decP;
            oled.setInvertMode(0);
            oled.setCursor(70,coordY());oled.print(dist_dec);
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          }
          if (Fm_Ech)  // annulation
          {
            oled.setInvertMode(0);
            oled.setCursor(70,coordY());oled.print(dist_dec);oled.print(" ");
            Seq=0;
            Enter=LOW;
            curseur=HIGH;
          } 
        }
        if (delayautorepeat==1000) ++autorepeat;
        if (autorepeat==51) autorepeat=0;
      }     
    }
  }      
  
 
}
