EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Pilotage moteur à courant continu pour portail"
Date "02-08-2022"
Rev "1.1"
Comp "F1IWQ"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 62C03373
P 950 1000
F 0 "J1" H 1100 950 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 900 1200 50  0000 C CNN
F 2 "Connector_Phoenix_MSTB:PhoenixContact_MSTBVA_2,5_2-G-5,08_1x02_P5.08mm_Vertical" H 950 1000 50  0001 C CNN
F 3 "~" H 950 1000 50  0001 C CNN
	1    950  1000
	-1   0    0    1   
$EndComp
Text Notes 750  800  0    50   ~ 0
Arrivée 24V=\npar fusible 5A
$Comp
L power:GND #PWR02
U 1 1 62C03C90
P 1250 1350
F 0 "#PWR02" H 1250 1100 50  0001 C CNN
F 1 "GND" H 1255 1177 50  0000 C CNN
F 2 "" H 1250 1350 50  0001 C CNN
F 3 "" H 1250 1350 50  0001 C CNN
	1    1250 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 1000 1250 1000
$Comp
L Device:D_TVS D1
U 1 1 62C24DF2
P 2300 1150
F 0 "D1" V 2250 950 50  0000 L CNN
F 1 "1.5KE39C" V 2350 650 50  0000 L CNN
F 2 "Diode_THT:D_DO-201AD_P5.08mm_Vertical_KathodeUp" H 2300 1150 50  0001 C CNN
F 3 "~" H 2300 1150 50  0001 C CNN
	1    2300 1150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 62C2558D
P 2300 1350
F 0 "#PWR07" H 2300 1100 50  0001 C CNN
F 1 "GND" H 2305 1177 50  0000 C CNN
F 2 "" H 2300 1350 50  0001 C CNN
F 3 "" H 2300 1350 50  0001 C CNN
	1    2300 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 1000 1250 1350
Wire Wire Line
	2300 1350 2300 1300
Text Notes 9500 1150 0    79   ~ 0
     Module IBT_2\n  pilotage du moteur \n  à courant continu\nconstitué de 2xBTS7960
$Comp
L Connector:Conn_01x08_Male J11
U 1 1 62C4A28E
P 10900 1900
F 0 "J11" H 10950 2250 50  0000 C CNN
F 1 "Conn_01x08_Male" H 11450 2300 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 10900 1900 50  0001 C CNN
F 3 "~" H 10900 1900 50  0001 C CNN
	1    10900 1900
	-1   0    0    1   
$EndComp
$Comp
L Regulator_Linear:LM7805_TO220 U3
U 1 1 62C4BCDE
P 4750 1550
F 0 "U3" H 4750 1900 50  0000 C CNN
F 1 "LM7805_TO220" H 4850 1800 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 4750 1775 50  0001 C CIN
F 3 "https://www.onsemi.cn/PowerSolutions/document/MC7800-D.PDF" H 4750 1500 50  0001 C CNN
	1    4750 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1850 4750 1950
$Comp
L power:GND #PWR015
U 1 1 62C4DB48
P 4750 1950
F 0 "#PWR015" H 4750 1700 50  0001 C CNN
F 1 "GND" H 4755 1777 50  0000 C CNN
F 2 "" H 4750 1950 50  0001 C CNN
F 3 "" H 4750 1950 50  0001 C CNN
	1    4750 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 62C4E2D2
P 4100 1700
F 0 "C6" H 4215 1746 50  0000 L CNN
F 1 "100nF" H 4215 1655 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 4138 1550 50  0001 C CNN
F 3 "~" H 4100 1700 50  0001 C CNN
	1    4100 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 62C4E9B2
P 5350 1700
F 0 "C8" H 5465 1746 50  0000 L CNN
F 1 "100nF" H 5465 1655 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 5388 1550 50  0001 C CNN
F 3 "~" H 5350 1700 50  0001 C CNN
	1    5350 1700
	1    0    0    -1  
$EndComp
Connection ~ 5350 1550
$Comp
L power:GND #PWR018
U 1 1 62C4F4FF
P 5350 1950
F 0 "#PWR018" H 5350 1700 50  0001 C CNN
F 1 "GND" H 5355 1777 50  0000 C CNN
F 2 "" H 5350 1950 50  0001 C CNN
F 3 "" H 5350 1950 50  0001 C CNN
	1    5350 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 62C4F863
P 4100 1950
F 0 "#PWR014" H 4100 1700 50  0001 C CNN
F 1 "GND" H 4105 1777 50  0000 C CNN
F 2 "" H 4100 1950 50  0001 C CNN
F 3 "" H 4100 1950 50  0001 C CNN
	1    4100 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 1850 5350 1950
Wire Wire Line
	4100 1850 4100 1950
Text Label 10450 2200 0    50   ~ 0
RPWM
Text Label 10450 2100 0    50   ~ 0
LPWM
Text Label 10450 2000 0    50   ~ 0
REN
Text Label 10450 1900 0    50   ~ 0
LEN
Text Label 10450 1800 0    50   ~ 0
RIS
Text Label 10450 1700 0    50   ~ 0
LIS
Text Label 10450 1500 0    50   ~ 0
GND
$Comp
L Device:D_Zener D5
U 1 1 62C5A5F0
P 9350 2050
F 0 "D5" V 9250 1950 50  0000 C CNN
F 1 "D_Z5.1V" V 9650 2050 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 9350 2050 50  0001 C CNN
F 3 "~" H 9350 2050 50  0001 C CNN
	1    9350 2050
	0    1    1    0   
$EndComp
$Comp
L Device:R R25
U 1 1 62C69F9B
P 9800 1600
F 0 "R25" V 9900 1450 50  0000 C CNN
F 1 "1k" V 9900 1750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 9730 1600 50  0001 C CNN
F 3 "~" H 9800 1600 50  0001 C CNN
	1    9800 1600
	0    1    1    0   
$EndComp
$Comp
L Device:D_Zener D6
U 1 1 62C71CA2
P 8650 2050
F 0 "D6" V 8550 1950 50  0000 C CNN
F 1 "D_Z5.1V" V 8950 2050 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 8650 2050 50  0001 C CNN
F 3 "~" H 8650 2050 50  0001 C CNN
	1    8650 2050
	0    1    1    0   
$EndComp
$Comp
L Device:R R27
U 1 1 62C71CAC
P 9800 1350
F 0 "R27" V 9900 1200 50  0000 C CNN
F 1 "1k" V 9900 1500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 9730 1350 50  0001 C CNN
F 3 "~" H 9800 1350 50  0001 C CNN
	1    9800 1350
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR017
U 1 1 62C4041C
P 5350 1400
F 0 "#PWR017" H 5350 1250 50  0001 C CNN
F 1 "+5V" H 5365 1573 50  0000 C CNN
F 2 "" H 5350 1400 50  0001 C CNN
F 3 "" H 5350 1400 50  0001 C CNN
	1    5350 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 1550 5350 1400
Text Label 2550 900  0    50   ~ 0
24V=
Wire Notes Line
	7850 600  550  600 
Text Notes 1100 1950 0    118  ~ 0
ALIMENTATIONS
$Comp
L Diode:1N4004 D4
U 1 1 62CC9194
P 4100 1200
F 0 "D4" V 4146 1120 50  0000 R CNN
F 1 "1N4004" V 4055 1120 50  0000 R CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 4100 1025 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 4100 1200 50  0001 C CNN
	1    4100 1200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4100 1050 4100 900 
Wire Wire Line
	4100 1350 4100 1550
Connection ~ 4100 1550
$Comp
L Diode:1N4004 D2
U 1 1 62CE5B5C
P 2850 1150
F 0 "D2" V 2900 1350 50  0000 R CNN
F 1 "1N4004" V 2800 1550 50  0000 R CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 2850 975 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 2850 1150 50  0001 C CNN
	1    2850 1150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 62CE931D
P 2850 1350
F 0 "#PWR08" H 2850 1100 50  0001 C CNN
F 1 "GND" H 2855 1177 50  0000 C CNN
F 2 "" H 2850 1350 50  0001 C CNN
F 3 "" H 2850 1350 50  0001 C CNN
	1    2850 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 1300 2850 1350
Wire Wire Line
	2300 1000 2300 900 
Connection ~ 2300 900 
Wire Wire Line
	2300 900  2850 900 
Wire Wire Line
	2850 1000 2850 900 
Connection ~ 2850 900 
$Comp
L Switch:SW_MEC_5E Bp+1
U 1 1 62D5DD4A
P 1800 4950
F 0 "Bp+1" H 1800 5335 50  0000 C CNN
F 1 "SW_MEC_5E" H 1800 5244 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-101xP" H 1800 5250 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=1371" H 1800 5250 50  0001 C CNN
	1    1800 4950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 62D5DD50
P 1150 4950
F 0 "R4" V 943 4950 50  0000 C CNN
F 1 "5,6k" V 1034 4950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1080 4950 50  0001 C CNN
F 3 "~" H 1150 4950 50  0001 C CNN
	1    1150 4950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR06
U 1 1 62D5DD56
P 2250 5100
F 0 "#PWR06" H 2250 4850 50  0001 C CNN
F 1 "GND" H 2255 4927 50  0000 C CNN
F 2 "" H 2250 5100 50  0001 C CNN
F 3 "" H 2250 5100 50  0001 C CNN
	1    2250 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 4950 2100 4950
Wire Wire Line
	2000 4850 2100 4850
Wire Wire Line
	2100 4850 2100 4950
Connection ~ 2100 4950
Wire Wire Line
	2100 4950 2000 4950
Wire Wire Line
	1600 4850 1450 4850
Wire Wire Line
	1450 4850 1450 4950
Wire Wire Line
	1600 4950 1450 4950
Connection ~ 1450 4950
Wire Wire Line
	1450 4950 1300 4950
Wire Wire Line
	800  4950 1000 4950
$Comp
L power:+5V #PWR01
U 1 1 62D5DD67
P 800 2600
F 0 "#PWR01" H 800 2450 50  0001 C CNN
F 1 "+5V" H 815 2773 50  0000 C CNN
F 2 "" H 800 2600 50  0001 C CNN
F 3 "" H 800 2600 50  0001 C CNN
	1    800  2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 4850 1450 4450
Text Label 1450 4450 3    50   ~ 0
Bp+
Connection ~ 1450 4850
Text Notes 950  5250 0    59   ~ 0
Boutons poussoir
$Comp
L Switch:SW_MEC_5E Bp-1
U 1 1 62D5DD92
P 1800 4300
F 0 "Bp-1" H 1800 4685 50  0000 C CNN
F 1 "SW_MEC_5E" H 1800 4594 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-101xP" H 1800 4600 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=1371" H 1800 4600 50  0001 C CNN
	1    1800 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 4300 2100 4300
Wire Wire Line
	2250 4300 2250 4950
Connection ~ 2250 4950
Wire Wire Line
	2000 4200 2100 4200
Wire Wire Line
	2100 4200 2100 4300
Connection ~ 2100 4300
Wire Wire Line
	2100 4300 2250 4300
Wire Wire Line
	1600 4300 1450 4300
Wire Wire Line
	1600 4200 1450 4200
Wire Wire Line
	1450 4200 1450 4300
Connection ~ 1450 4300
$Comp
L Device:R R3
U 1 1 62D5DDA3
P 1150 4300
F 0 "R3" V 943 4300 50  0000 C CNN
F 1 "5,6k" V 1034 4300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1080 4300 50  0001 C CNN
F 3 "~" H 1150 4300 50  0001 C CNN
	1    1150 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	1300 4300 1450 4300
Wire Wire Line
	1450 4200 1450 3800
Connection ~ 1450 4200
Text Label 1450 3800 3    50   ~ 0
Bp-
Wire Wire Line
	1000 4300 800  4300
Wire Wire Line
	800  2600 800  3000
$Comp
L Switch:SW_MEC_5E BpEch1
U 1 1 62D5DDB2
P 1800 3000
F 0 "BpEch1" H 1800 3385 50  0000 C CNN
F 1 "SW_MEC_5E" H 1800 3294 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-101xP" H 1800 3300 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=1371" H 1800 3300 50  0001 C CNN
	1    1800 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 3000 2100 3000
Wire Wire Line
	2000 2900 2100 2900
Wire Wire Line
	2100 2900 2100 3000
Connection ~ 2100 3000
Wire Wire Line
	2100 3000 2250 3000
Wire Wire Line
	1600 3000 1450 3000
Wire Wire Line
	1600 2900 1450 2900
Wire Wire Line
	1450 2900 1450 3000
Connection ~ 1450 3000
$Comp
L Device:R R1
U 1 1 62D5DDC1
P 1150 3000
F 0 "R1" V 943 3000 50  0000 C CNN
F 1 "5,6k" V 1034 3000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1080 3000 50  0001 C CNN
F 3 "~" H 1150 3000 50  0001 C CNN
	1    1150 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	1300 3000 1450 3000
Wire Wire Line
	1450 2900 1450 2500
Connection ~ 1450 2900
Text Label 1450 2500 3    50   ~ 0
BpEch
Wire Wire Line
	1000 3000 800  3000
Connection ~ 800  3000
Wire Wire Line
	800  3000 800  3650
Wire Wire Line
	2250 4950 2250 5100
$Comp
L Switch:SW_MEC_5E Bp-Ent1
U 1 1 62D5DDCF
P 1800 3650
F 0 "Bp-Ent1" H 1800 4035 50  0000 C CNN
F 1 "SW_MEC_5E" H 1800 3944 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_Omron_B3FS-101xP" H 1800 3950 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=1371" H 1800 3950 50  0001 C CNN
	1    1800 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 3650 2100 3650
Wire Wire Line
	2000 3550 2100 3550
Wire Wire Line
	2100 3550 2100 3650
Connection ~ 2100 3650
Wire Wire Line
	2100 3650 2250 3650
Wire Wire Line
	1600 3650 1450 3650
Wire Wire Line
	1600 3550 1450 3550
Wire Wire Line
	1450 3550 1450 3650
Connection ~ 1450 3650
$Comp
L Device:R R2
U 1 1 62D5DDDE
P 1150 3650
F 0 "R2" V 943 3650 50  0000 C CNN
F 1 "5,6k" V 1034 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1080 3650 50  0001 C CNN
F 3 "~" H 1150 3650 50  0001 C CNN
	1    1150 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	1300 3650 1450 3650
Wire Wire Line
	1450 3550 1450 3150
Connection ~ 1450 3550
Text Label 1450 3150 3    50   ~ 0
BpEnt
Wire Wire Line
	1000 3650 800  3650
Wire Wire Line
	800  3650 800  4300
Connection ~ 800  3650
Connection ~ 800  4300
Wire Wire Line
	800  4300 800  4950
Wire Wire Line
	2250 3000 2250 3650
Wire Wire Line
	2250 3650 2250 4300
Connection ~ 2250 3650
Connection ~ 2250 4300
$Comp
L power:GND #PWR?
U 1 1 62D74080
P 3400 4050
AR Path="/62D5014D/62D74080" Ref="#PWR?"  Part="1" 
AR Path="/62D74080" Ref="#PWR012"  Part="1" 
F 0 "#PWR012" H 3400 3800 50  0001 C CNN
F 1 "GND" H 3550 4000 50  0000 C CNN
F 2 "" H 3400 4050 50  0001 C CNN
F 3 "" H 3400 4050 50  0001 C CNN
	1    3400 4050
	1    0    0    -1  
$EndComp
Text Label 3000 3200 1    50   ~ 0
FOuv
Text Label 3100 3200 1    50   ~ 0
Ffer
Text Notes 3300 2550 2    50   ~ 0
fermé
Text Notes 3050 2550 2    50   ~ 0
ouvert
$Comp
L Device:C C?
U 1 1 62D8D2A6
P 3700 3800
AR Path="/62D5014D/62D8D2A6" Ref="C?"  Part="1" 
AR Path="/62D8D2A6" Ref="C4"  Part="1" 
F 0 "C4" H 3600 3700 50  0000 L CNN
F 1 "100nF" H 3450 3900 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 3738 3650 50  0001 C CNN
F 3 "~" H 3700 3800 50  0001 C CNN
	1    3700 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 62D8D2AC
P 3400 3800
AR Path="/62D5014D/62D8D2AC" Ref="C?"  Part="1" 
AR Path="/62D8D2AC" Ref="C3"  Part="1" 
F 0 "C3" H 3300 3700 50  0000 L CNN
F 1 "100nF" H 3150 3900 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 3438 3650 50  0001 C CNN
F 3 "~" H 3400 3800 50  0001 C CNN
	1    3400 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 3650 3400 3600
Wire Wire Line
	3400 3600 3000 3600
Connection ~ 3000 3600
Wire Wire Line
	3100 3550 3700 3550
Wire Wire Line
	3700 3550 3700 3650
Connection ~ 3100 3550
$Comp
L Device:C C?
U 1 1 62D8D2BA
P 4000 3800
AR Path="/62D5014D/62D8D2BA" Ref="C?"  Part="1" 
AR Path="/62D8D2BA" Ref="C5"  Part="1" 
F 0 "C5" H 3900 3700 50  0000 L CNN
F 1 "100nF" H 3750 3900 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 4038 3650 50  0001 C CNN
F 3 "~" H 4000 3800 50  0001 C CNN
	1    4000 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 3450 4000 3450
Wire Wire Line
	4000 3650 4000 3450
Wire Wire Line
	3400 3950 3400 4000
Wire Wire Line
	3400 4000 3700 4000
Wire Wire Line
	4000 4000 4000 3950
Connection ~ 3400 4000
Wire Wire Line
	3400 4000 3400 4050
Wire Wire Line
	3700 3950 3700 4000
Connection ~ 3700 4000
Wire Wire Line
	3700 4000 4000 4000
$Comp
L Isolator:SFH617A-1 U1
U 1 1 62E0847C
P 3400 4550
F 0 "U1" H 3400 4350 50  0000 C CNN
F 1 "SFH617A-1" H 3400 4784 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm_LongPads" H 3200 4350 50  0001 L CIN
F 3 "http://www.vishay.com/docs/83740/sfh617a.pdf" H 3400 4550 50  0001 L CNN
	1    3400 4550
	1    0    0    -1  
$EndComp
$Comp
L Isolator:SFH617A-1 U2
U 1 1 62E202D9
P 4250 4550
F 0 "U2" H 4250 4350 50  0000 C CNN
F 1 "SFH617A-1" H 4250 4784 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm_LongPads" H 4050 4350 50  0001 L CIN
F 3 "http://www.vishay.com/docs/83740/sfh617a.pdf" H 4250 4550 50  0001 L CNN
	1    4250 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62E20DF6
P 3000 3950
AR Path="/62D5014D/62E20DF6" Ref="R?"  Part="1" 
AR Path="/62E20DF6" Ref="R8"  Part="1" 
F 0 "R8" H 2950 4100 50  0000 C CNN
F 1 "2,7k" H 2900 3800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2930 3950 50  0001 C CNN
F 3 "~" H 3000 3950 50  0001 C CNN
	1    3000 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62E21213
P 3100 3950
AR Path="/62D5014D/62E21213" Ref="R?"  Part="1" 
AR Path="/62E21213" Ref="R9"  Part="1" 
F 0 "R9" H 3200 4100 50  0000 C CNN
F 1 "2,7k" H 3200 3800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 3030 3950 50  0001 C CNN
F 3 "~" H 3100 3950 50  0001 C CNN
	1    3100 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 3600 3000 3800
Wire Wire Line
	3100 3550 3100 3800
Wire Wire Line
	3000 4100 3000 4450
Wire Wire Line
	3100 4450 3000 4450
Wire Wire Line
	3100 4650 3000 4650
Wire Wire Line
	3100 4100 3100 4250
Wire Wire Line
	3100 4250 3900 4250
Wire Wire Line
	3900 4250 3900 4450
Wire Wire Line
	3900 4450 3950 4450
$Comp
L power:GND #PWR?
U 1 1 62E779C3
P 3000 4850
AR Path="/62D5014D/62E779C3" Ref="#PWR?"  Part="1" 
AR Path="/62E779C3" Ref="#PWR09"  Part="1" 
F 0 "#PWR09" H 3000 4600 50  0001 C CNN
F 1 "GND" H 3150 4800 50  0000 C CNN
F 2 "" H 3000 4850 50  0001 C CNN
F 3 "" H 3000 4850 50  0001 C CNN
	1    3000 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62E7DC87
P 4650 3700
AR Path="/62D5014D/62E7DC87" Ref="R?"  Part="1" 
AR Path="/62E7DC87" Ref="R14"  Part="1" 
F 0 "R14" H 4550 3850 50  0000 C CNN
F 1 "5,6k" H 4550 3550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4580 3700 50  0001 C CNN
F 3 "~" H 4650 3700 50  0001 C CNN
	1    4650 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 4450 4650 4450
$Comp
L Device:R R?
U 1 1 62EA4F26
P 4400 3700
AR Path="/62D5014D/62EA4F26" Ref="R?"  Part="1" 
AR Path="/62EA4F26" Ref="R12"  Part="1" 
F 0 "R12" H 4300 3850 50  0000 C CNN
F 1 "5,6k" H 4250 3550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4330 3700 50  0001 C CNN
F 3 "~" H 4400 3700 50  0001 C CNN
	1    4400 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4450 3750 4450
Wire Wire Line
	3750 4450 3750 4100
Wire Wire Line
	3000 4650 3000 4800
Wire Wire Line
	4650 4800 4650 4650
Wire Wire Line
	4650 4650 4550 4650
Wire Wire Line
	3000 4800 3750 4800
Connection ~ 3000 4800
Wire Wire Line
	3000 4800 3000 4850
Wire Wire Line
	3950 4650 3950 4800
Connection ~ 3950 4800
Wire Wire Line
	3950 4800 4650 4800
Wire Wire Line
	3700 4650 3750 4650
Wire Wire Line
	3750 4650 3750 4800
Connection ~ 3750 4800
Wire Wire Line
	3750 4800 3950 4800
Text Label 4100 4100 0    50   ~ 0
Ouvert
Text Label 4650 4300 1    50   ~ 0
Ferme
Wire Notes Line
	550  2300 2500 2300
$Comp
L power:GND #PWR?
U 1 1 63192D29
P 5100 3950
AR Path="/62D5014D/63192D29" Ref="#PWR?"  Part="1" 
AR Path="/63192D29" Ref="#PWR016"  Part="1" 
F 0 "#PWR016" H 5100 3700 50  0001 C CNN
F 1 "GND" H 5250 3900 50  0000 C CNN
F 2 "" H 5100 3950 50  0001 C CNN
F 3 "" H 5100 3950 50  0001 C CNN
	1    5100 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 63192D36
P 5100 3700
AR Path="/62D5014D/63192D36" Ref="C?"  Part="1" 
AR Path="/63192D36" Ref="C7"  Part="1" 
F 0 "C7" H 5150 3800 50  0000 L CNN
F 1 "100nF" H 5150 3600 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 5138 3550 50  0001 C CNN
F 3 "~" H 5100 3700 50  0001 C CNN
	1    5100 3700
	1    0    0    -1  
$EndComp
$Comp
L Isolator:SFH617A-1 U4
U 1 1 63192D47
P 5250 4550
F 0 "U4" H 5250 4350 50  0000 C CNN
F 1 "SFH617A-1" H 5250 4784 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm_LongPads" H 5050 4350 50  0001 L CIN
F 3 "http://www.vishay.com/docs/83740/sfh617a.pdf" H 5250 4550 50  0001 L CNN
	1    5250 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 63192D4D
P 4850 3700
AR Path="/62D5014D/63192D4D" Ref="R?"  Part="1" 
AR Path="/63192D4D" Ref="R15"  Part="1" 
F 0 "R15" H 4950 3550 50  0000 C CNN
F 1 "2,7k" H 4950 3850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 4780 3700 50  0001 C CNN
F 3 "~" H 4850 3700 50  0001 C CNN
	1    4850 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 4450 4850 4450
Wire Wire Line
	4950 4650 4850 4650
Wire Wire Line
	5550 4450 5600 4450
Wire Wire Line
	4850 4650 4850 4800
Wire Wire Line
	5550 4650 5600 4650
Wire Wire Line
	5600 4650 5600 4800
Wire Wire Line
	5100 3850 5100 3950
Text Label 5100 3250 1    50   ~ 0
Cell
$Comp
L Device:R R?
U 1 1 631B7318
P 5600 3700
AR Path="/62D5014D/631B7318" Ref="R?"  Part="1" 
AR Path="/631B7318" Ref="R16"  Part="1" 
F 0 "R16" H 5500 3550 50  0000 C CNN
F 1 "5,6k" H 5500 3850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5530 3700 50  0001 C CNN
F 3 "~" H 5600 3700 50  0001 C CNN
	1    5600 3700
	1    0    0    -1  
$EndComp
Text Label 5600 4400 1    50   ~ 0
Cellule
$Comp
L power:GND #PWR04
U 1 1 632C2E7B
P 1550 1350
F 0 "#PWR04" H 1550 1100 50  0001 C CNN
F 1 "GND" H 1555 1177 50  0000 C CNN
F 2 "" H 1550 1350 50  0001 C CNN
F 3 "" H 1550 1350 50  0001 C CNN
	1    1550 1350
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 632C38BF
P 1550 1250
F 0 "#FLG01" H 1550 1325 50  0001 C CNN
F 1 "PWR_FLAG" H 1550 1423 50  0000 C CNN
F 2 "" H 1550 1250 50  0001 C CNN
F 3 "~" H 1550 1250 50  0001 C CNN
	1    1550 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 1350 1550 1250
$Comp
L Isolator:SFH617A-1 U5
U 1 1 6350BA86
P 6100 4550
F 0 "U5" H 6100 4350 50  0000 C CNN
F 1 "SFH617A-1" H 6100 4784 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm_LongPads" H 5900 4350 50  0001 L CIN
F 3 "http://www.vishay.com/docs/83740/sfh617a.pdf" H 6100 4550 50  0001 L CNN
	1    6100 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 4800 4850 4800
Connection ~ 4650 4800
Wire Wire Line
	5800 4800 5800 4650
$Comp
L Device:R R?
U 1 1 63540E6E
P 5750 3700
AR Path="/62D5014D/63540E6E" Ref="R?"  Part="1" 
AR Path="/63540E6E" Ref="R17"  Part="1" 
F 0 "R17" H 5850 3550 50  0000 C CNN
F 1 "2,7k" H 5850 3850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5680 3700 50  0001 C CNN
F 3 "~" H 5750 3700 50  0001 C CNN
	1    5750 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4450 5800 4450
Wire Wire Line
	6400 4450 6450 4450
$Comp
L Device:R R?
U 1 1 63589E29
P 6450 3700
AR Path="/62D5014D/63589E29" Ref="R?"  Part="1" 
AR Path="/63589E29" Ref="R19"  Part="1" 
F 0 "R19" H 6350 3550 50  0000 C CNN
F 1 "5,6k" H 6350 3850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6380 3700 50  0001 C CNN
F 3 "~" H 6450 3700 50  0001 C CNN
	1    6450 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4800 6450 4650
Wire Wire Line
	6450 4650 6400 4650
Text Label 5650 3250 2    50   ~ 0
Commande
Text Label 6450 4400 1    59   ~ 0
Comand
$Comp
L power:PWR_FLAG #FLG02
U 1 1 635B318B
P 4250 1550
F 0 "#FLG02" H 4250 1625 50  0001 C CNN
F 1 "PWR_FLAG" H 4300 1700 50  0000 C CNN
F 2 "" H 4250 1550 50  0001 C CNN
F 3 "~" H 4250 1550 50  0001 C CNN
	1    4250 1550
	1    0    0    -1  
$EndComp
Connection ~ 4250 1550
Wire Wire Line
	4250 1550 4100 1550
Wire Wire Line
	4250 1550 4450 1550
$Comp
L Device:C C?
U 1 1 635DAC7C
P 6000 3700
AR Path="/62D5014D/635DAC7C" Ref="C?"  Part="1" 
AR Path="/635DAC7C" Ref="C9"  Part="1" 
F 0 "C9" H 6050 3800 50  0000 L CNN
F 1 "100nF" H 6000 3600 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 6038 3550 50  0001 C CNN
F 3 "~" H 6000 3700 50  0001 C CNN
	1    6000 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3550 5750 3250
$Comp
L power:GND #PWR?
U 1 1 635EE46C
P 6000 3950
AR Path="/62D5014D/635EE46C" Ref="#PWR?"  Part="1" 
AR Path="/635EE46C" Ref="#PWR020"  Part="1" 
F 0 "#PWR020" H 6000 3700 50  0001 C CNN
F 1 "GND" H 6150 3900 50  0000 C CNN
F 2 "" H 6000 3950 50  0001 C CNN
F 3 "" H 6000 3950 50  0001 C CNN
	1    6000 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	10700 2100 10450 2100
Wire Wire Line
	10700 2200 10450 2200
Wire Wire Line
	10700 1500 10450 1500
Wire Wire Line
	10700 1700 10200 1700
Wire Wire Line
	10200 1700 10200 1600
Wire Wire Line
	9950 1600 10200 1600
$Comp
L Relay:FINDER-44.62 K1
U 1 1 62C77F16
P 3900 5850
F 0 "K1" H 4050 5550 50  0000 L CNN
F 1 "FINDER-44.62" H 3850 5300 50  0000 L CNN
F 2 "Relay_THT:Relay_DPDT_Finder_40.52" H 5250 5820 50  0001 C CNN
F 3 "http://gfinder.findernet.com/assets/Series/359/S44EN.pdf" H 3900 5850 50  0001 C CNN
	1    3900 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 6150 3900 6300
Wire Wire Line
	3500 5200 3500 5450
Text Label 3500 5400 1    50   ~ 0
24V=
Connection ~ 3100 5450
Wire Wire Line
	2900 5450 3100 5450
Wire Wire Line
	2900 5700 2900 5450
Connection ~ 3100 6200
Wire Wire Line
	2900 6200 2900 6000
Wire Wire Line
	3100 6200 2900 6200
Wire Wire Line
	3100 6000 3100 6200
Wire Wire Line
	3500 5450 3500 5550
Connection ~ 3500 5450
Wire Wire Line
	3100 5450 3100 5700
Wire Wire Line
	3500 5450 3100 5450
$Comp
L Device:C C?
U 1 1 62EEAEE2
P 2900 5850
AR Path="/62D5014D/62EEAEE2" Ref="C?"  Part="1" 
AR Path="/62EEAEE2" Ref="C1"  Part="1" 
F 0 "C1" H 2700 5950 50  0000 L CNN
F 1 "100nF" H 2650 5750 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 2938 5700 50  0001 C CNN
F 3 "~" H 2900 5850 50  0001 C CNN
	1    2900 5850
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4004 D3
U 1 1 62EE9F78
P 3100 5850
F 0 "D3" V 2500 5900 50  0000 R CNN
F 1 "1N4004" V 2600 6000 50  0000 R CNN
F 2 "Diode_THT:D_DO-41_SOD81_P3.81mm_Vertical_KathodeUp" H 3100 5675 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 3100 5850 50  0001 C CNN
	1    3100 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	3500 6200 3500 6250
Connection ~ 3500 6200
Wire Wire Line
	3500 6200 3100 6200
Wire Wire Line
	3500 6150 3500 6200
$Comp
L power:GND #PWR013
U 1 1 62E3F5A9
P 3500 6700
F 0 "#PWR013" H 3500 6450 50  0001 C CNN
F 1 "GND" H 3300 6650 50  0000 C CNN
F 2 "" H 3500 6700 50  0001 C CNN
F 3 "" H 3500 6700 50  0001 C CNN
	1    3500 6700
	1    0    0    -1  
$EndComp
Text Label 2750 6450 0    50   ~ 0
Marche
Wire Wire Line
	3200 6450 2750 6450
$Comp
L Transistor_FET:BS170 Q2
U 1 1 62C3F0B1
P 3400 6450
F 0 "Q2" H 3604 6496 50  0000 L CNN
F 1 "BS170" H 3604 6405 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92L_Inline_Wide" H 3600 6375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BS170-D.PDF" H 3400 6450 50  0001 L CNN
	1    3400 6450
	1    0    0    -1  
$EndComp
Text Label 7250 3850 0    59   ~ 0
Comand
Text Label 7250 3550 0    50   ~ 0
Cellule
Text Label 7250 4250 0    50   ~ 0
Bp+
Text Label 7250 3950 0    50   ~ 0
BpEch
Text Label 7250 3750 0    50   ~ 0
RPWM
Text Label 7250 3650 0    50   ~ 0
LPWM
Text Label 7250 4350 0    50   ~ 0
Bp-
Text Label 7250 4150 0    50   ~ 0
BpEnt
Text Label 10800 3950 2    50   ~ 0
Ouvert
Text Label 10800 4050 2    50   ~ 0
Ferme
Text Label 7250 4050 0    59   ~ 0
Marche
Wire Wire Line
	3500 6650 3500 6700
$Comp
L Connector:Screw_Terminal_01x06 J4
U 1 1 631FBE62
P 5000 5750
F 0 "J4" H 4950 6100 50  0000 L CNN
F 1 "Screw_Terminal_01x06" H 4450 5100 50  0000 L CNN
F 2 "Connector_Phoenix_MSTB:PhoenixContact_MSTBVA_2,5_6-G-5,08_1x06_P5.08mm_Vertical" H 5000 5750 50  0001 C CNN
F 3 "~" H 5000 5750 50  0001 C CNN
	1    5000 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 6300 3900 6300
Text Notes 4100 6750 0    59   ~ 0
Eclairage et\navertissement
Wire Notes Line
	2600 5150 2600 6850
Wire Wire Line
	9300 2750 9300 2700
NoConn ~ 9100 4750
NoConn ~ 9200 2750
NoConn ~ 9000 2750
Text Label 10800 4150 2    50   ~ 0
SDA
Text Label 10800 4250 2    50   ~ 0
SCL
$Comp
L Device:R R20
U 1 1 62D66B02
P 7950 3550
F 0 "R20" V 7900 3350 50  0000 C CNN
F 1 "1k" V 7900 3700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7880 3550 50  0001 C CNN
F 3 "~" H 7950 3550 50  0001 C CNN
	1    7950 3550
	0    1    1    0   
$EndComp
NoConn ~ 9600 3150
NoConn ~ 9600 3250
NoConn ~ 9600 3550
Text Label 10800 4350 2    50   ~ 0
PLIS
Text Label 10800 4450 2    50   ~ 0
PRIS
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 62C4A351
P 9100 3750
F 0 "A1" H 9400 2750 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 9700 2650 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 9100 3750 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 9100 3750 50  0001 C CNN
	1    9100 3750
	1    0    0    -1  
$EndComp
Connection ~ 4850 4800
Connection ~ 5600 4800
Connection ~ 5800 4800
Wire Wire Line
	4850 4800 5600 4800
$Comp
L Connector:Screw_Terminal_01x03 J2
U 1 1 62F40F9A
P 3100 2850
F 0 "J2" V 3100 3100 50  0000 R CNN
F 1 "Screw_Terminal_01x03" V 3200 2650 50  0000 R CNN
F 2 "Connector_Phoenix_MSTB:PhoenixContact_MSTBVA_2,5_3-G-5,08_1x03_P5.08mm_Vertical" H 3100 2850 50  0001 C CNN
F 3 "~" H 3100 2850 50  0001 C CNN
	1    3100 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 4100 4400 3850
Wire Wire Line
	3750 4100 4400 4100
Wire Wire Line
	4400 3550 4400 3450
Wire Wire Line
	4400 3450 4650 3450
Connection ~ 4650 3450
Wire Wire Line
	4650 3850 4650 4450
Wire Wire Line
	4850 3850 4850 4450
Wire Wire Line
	4650 3450 4650 3550
Wire Wire Line
	5600 3550 5600 3450
Connection ~ 5600 3450
Wire Wire Line
	5600 3850 5600 4450
Wire Wire Line
	5750 3850 5750 4450
Wire Wire Line
	5800 4800 6450 4800
Wire Wire Line
	5600 4800 5800 4800
Wire Wire Line
	4650 3450 5600 3450
Wire Wire Line
	4850 3550 4850 3350
Wire Wire Line
	6450 3550 6450 3450
Wire Wire Line
	6450 3850 6450 4450
Wire Wire Line
	5600 3450 6450 3450
Wire Wire Line
	4400 3450 4400 3350
Connection ~ 4400 3450
Wire Wire Line
	5200 3050 5200 3250
Wire Wire Line
	5200 3250 5750 3250
Connection ~ 5750 3250
Wire Wire Line
	5100 3050 5100 3350
Wire Wire Line
	4850 3350 5100 3350
Connection ~ 5100 3350
Wire Wire Line
	5100 3350 5100 3550
Wire Wire Line
	5000 3150 5000 3050
Wire Wire Line
	6000 3550 6000 3250
Wire Wire Line
	6000 3250 5750 3250
Wire Notes Line
	550  600  550  2200
Wire Notes Line
	7850 600  7850 2200
Wire Notes Line
	550  2200 7850 2200
Text Notes 4050 7050 0    50   ~ 0
connecteur femelle
$Comp
L Device:C C2
U 1 1 62D5DD87
P 3000 7300
F 0 "C2" H 2850 7400 50  0000 L CNN
F 1 "100nF" H 2750 7200 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 3038 7150 50  0001 C CNN
F 3 "~" H 3000 7300 50  0001 C CNN
	1    3000 7300
	-1   0    0    1   
$EndComp
Wire Wire Line
	4050 7350 3300 7350
Wire Wire Line
	3650 7250 3450 7250
Wire Wire Line
	3650 7150 3450 7150
$Comp
L Device:R R11
U 1 1 62D5DD7A
P 3800 7250
F 0 "R11" V 3950 7050 50  0000 C CNN
F 1 "330" V 3950 7250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3730 7250 50  0001 C CNN
F 3 "~" H 3800 7250 50  0001 C CNN
	1    3800 7250
	0    1    1    0   
$EndComp
Wire Wire Line
	4050 7250 3950 7250
Wire Wire Line
	3950 7150 4050 7150
$Comp
L Device:R R10
U 1 1 62D5DD72
P 3800 7150
F 0 "R10" V 3700 7050 50  0000 C CNN
F 1 "330" V 3700 7250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3730 7150 50  0001 C CNN
F 3 "~" H 3800 7150 50  0001 C CNN
	1    3800 7150
	0    1    1    0   
$EndComp
Text Notes 4600 7550 0    59   ~ 0
Ecran OLED
Text Label 3450 7150 0    50   ~ 0
SDA
Text Label 3450 7250 0    50   ~ 0
SCL
$Comp
L power:+5V #PWR011
U 1 1 62D5DD41
P 3300 7050
F 0 "#PWR011" H 3300 6900 50  0001 C CNN
F 1 "+5V" H 3450 7100 50  0000 C CNN
F 2 "" H 3300 7050 50  0001 C CNN
F 3 "" H 3300 7050 50  0001 C CNN
	1    3300 7050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 62D5DD3B
P 3000 7500
F 0 "#PWR010" H 3000 7250 50  0001 C CNN
F 1 "GND" H 3200 7450 50  0000 C CNN
F 2 "" H 3000 7500 50  0001 C CNN
F 3 "" H 3000 7500 50  0001 C CNN
	1    3000 7500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 62D5DD35
P 4250 7250
F 0 "J3" H 4330 7242 50  0000 L CNN
F 1 "Conn_01x04" H 4330 7151 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 4250 7250 50  0001 C CNN
F 3 "~" H 4250 7250 50  0001 C CNN
	1    4250 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 7150 3000 7100
Wire Wire Line
	3000 7450 3000 7500
Wire Wire Line
	3000 7450 4050 7450
Connection ~ 3000 7450
Wire Wire Line
	3300 7100 3300 7050
Wire Wire Line
	3000 7100 3300 7100
Wire Wire Line
	3300 7100 3300 7350
Connection ~ 3300 7100
Wire Notes Line
	2600 6900 2600 7650
Text Notes 5950 5550 0    50   ~ 0
  Rx-multi\nSMG-662MRX
Wire Wire Line
	5900 6050 5900 6250
$Comp
L power:GND #PWR019
U 1 1 638D8A09
P 5900 6250
F 0 "#PWR019" H 5900 6000 50  0001 C CNN
F 1 "GND" H 5905 6077 50  0000 C CNN
F 2 "" H 5900 6250 50  0001 C CNN
F 3 "" H 5900 6250 50  0001 C CNN
	1    5900 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 6050 6000 6300
Text Label 6000 6300 1    50   ~ 0
24V=
Wire Wire Line
	6100 6500 6300 6500
Wire Wire Line
	6100 6050 6100 6500
Wire Wire Line
	6300 6050 6300 6500
Wire Wire Line
	6200 6050 6200 6350
Text Label 6200 6350 1    50   ~ 0
RadioR
Wire Wire Line
	6400 6050 6400 6350
Text Notes 5850 7550 0    59   ~ 0
 Connecteur \n  récepteur \ntélécommande\n code roulant
Wire Wire Line
	10400 2000 10400 1900
Wire Wire Line
	10400 2000 10700 2000
Wire Wire Line
	10400 1600 10700 1600
Wire Wire Line
	10400 1900 10700 1900
Connection ~ 10400 1900
Wire Wire Line
	10400 1900 10400 1600
Wire Wire Line
	9600 4050 10150 4050
Wire Wire Line
	9600 3950 10150 3950
Wire Wire Line
	9600 3850 10150 3850
Wire Wire Line
	9600 3750 10150 3750
Text Label 10800 3850 2    50   ~ 0
RadioR
Wire Wire Line
	8100 3550 8600 3550
$Comp
L Device:R R21
U 1 1 62F7F46A
P 7950 3650
F 0 "R21" V 7900 3450 50  0000 C CNN
F 1 "1k" V 7900 3800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7880 3650 50  0001 C CNN
F 3 "~" H 7950 3650 50  0001 C CNN
	1    7950 3650
	0    1    1    0   
$EndComp
$Comp
L Device:R R22
U 1 1 62F7F62A
P 7950 3750
F 0 "R22" V 7900 3550 50  0000 C CNN
F 1 "1k" V 7900 3900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7880 3750 50  0001 C CNN
F 3 "~" H 7950 3750 50  0001 C CNN
	1    7950 3750
	0    1    1    0   
$EndComp
$Comp
L Device:R R23
U 1 1 62F7F8BC
P 7950 3850
F 0 "R23" V 7900 3650 50  0000 C CNN
F 1 "1k" V 7900 4000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7880 3850 50  0001 C CNN
F 3 "~" H 7950 3850 50  0001 C CNN
	1    7950 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	8100 3650 8600 3650
Wire Wire Line
	8100 3750 8600 3750
Wire Wire Line
	8100 3850 8600 3850
Wire Wire Line
	7250 3850 7800 3850
Wire Wire Line
	7250 3750 7800 3750
Wire Wire Line
	7250 3650 7800 3650
Wire Wire Line
	7250 3550 7800 3550
$Comp
L Device:R R29
U 1 1 6313936B
P 10300 3850
F 0 "R29" V 10250 3650 50  0000 C CNN
F 1 "1k" V 10250 4000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 10230 3850 50  0001 C CNN
F 3 "~" H 10300 3850 50  0001 C CNN
	1    10300 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	10450 3850 10800 3850
$Comp
L Device:R R30
U 1 1 63176087
P 10300 3950
F 0 "R30" V 10250 3750 50  0000 C CNN
F 1 "1k" V 10250 4100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 10230 3950 50  0001 C CNN
F 3 "~" H 10300 3950 50  0001 C CNN
	1    10300 3950
	0    1    1    0   
$EndComp
$Comp
L Device:R R31
U 1 1 63176285
P 10300 4050
F 0 "R31" V 10250 3850 50  0000 C CNN
F 1 "1k" V 10250 4200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 10230 4050 50  0001 C CNN
F 3 "~" H 10300 4050 50  0001 C CNN
	1    10300 4050
	0    1    1    0   
$EndComp
Wire Wire Line
	10450 3950 10800 3950
Wire Wire Line
	10450 4050 10800 4050
Text Notes 8450 1050 0    50   ~ 0
Image des courants\n    des ponts en H
$Comp
L power:GND #PWR024
U 1 1 632E8AD4
P 9200 4800
F 0 "#PWR024" H 9200 4550 50  0001 C CNN
F 1 "GND" H 9050 4700 50  0000 C CNN
F 2 "" H 9200 4800 50  0001 C CNN
F 3 "" H 9200 4800 50  0001 C CNN
	1    9200 4800
	1    0    0    -1  
$EndComp
Text Notes 4400 4900 0    50   ~ 0
4xSFH617A ou 1xLTV847
$Comp
L Connector:Screw_Terminal_01x02 J7
U 1 1 62F68DDF
P 6450 2900
F 0 "J7" H 6600 2850 50  0000 C CNN
F 1 "Screw_Terminal_01x02" V 6600 3350 50  0000 C CNN
F 2 "Connector_Phoenix_MSTB:PhoenixContact_MSTBVA_2,5_2-G-5,08_1x02_P5.08mm_Vertical" H 6450 2900 50  0001 C CNN
F 3 "~" H 6450 2900 50  0001 C CNN
	1    6450 2900
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR021
U 1 1 62F6ACC6
P 6150 3000
F 0 "#PWR021" H 6150 2750 50  0001 C CNN
F 1 "GND" H 6155 2827 50  0000 C CNN
F 2 "" H 6150 3000 50  0001 C CNN
F 3 "" H 6150 3000 50  0001 C CNN
	1    6150 3000
	1    0    0    -1  
$EndComp
Text Notes 5850 2700 0    51   ~ 0
Alimentation cellule
$Comp
L Mechanical:Fiducial FID1
U 1 1 62C786DA
P 7100 5400
F 0 "FID1" H 7185 5446 50  0000 L CNN
F 1 "Fiducial" H 7185 5355 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7100 5400 50  0001 C CNN
F 3 "~" H 7100 5400 50  0001 C CNN
	1    7100 5400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID2
U 1 1 62C7989B
P 7100 5550
F 0 "FID2" H 7185 5596 50  0000 L CNN
F 1 "Fiducial" H 7185 5505 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7100 5550 50  0001 C CNN
F 3 "~" H 7100 5550 50  0001 C CNN
	1    7100 5550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID3
U 1 1 62C79A0E
P 7100 5700
F 0 "FID3" H 7185 5746 50  0000 L CNN
F 1 "Fiducial" H 7185 5655 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7100 5700 50  0001 C CNN
F 3 "~" H 7100 5700 50  0001 C CNN
	1    7100 5700
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID4
U 1 1 62C79B6E
P 7100 5850
F 0 "FID4" H 7185 5896 50  0000 L CNN
F 1 "Fiducial" H 7185 5805 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7100 5850 50  0001 C CNN
F 3 "~" H 7100 5850 50  0001 C CNN
	1    7100 5850
	1    0    0    -1  
$EndComp
Text Notes 7000 5300 0    50   ~ 0
trous platine
Text Notes 7750 5300 0    50   ~ 0
trous récepteur
$Comp
L Mechanical:Fiducial FID7
U 1 1 62CCCC0B
P 7800 5400
F 0 "FID7" H 7885 5446 50  0000 L CNN
F 1 "Fiducial" H 7885 5355 50  0000 L CNN
F 2 "MountingHole:MountingHole_3mm" H 7800 5400 50  0001 C CNN
F 3 "~" H 7800 5400 50  0001 C CNN
	1    7800 5400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID8
U 1 1 62CCDB15
P 7800 5550
F 0 "FID8" H 7885 5596 50  0000 L CNN
F 1 "Fiducial" H 7885 5505 50  0000 L CNN
F 2 "MountingHole:MountingHole_3mm" H 7800 5550 50  0001 C CNN
F 3 "~" H 7800 5550 50  0001 C CNN
	1    7800 5550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID9
U 1 1 62C96000
P 7800 5900
F 0 "FID9" H 7885 5946 50  0000 L CNN
F 1 "Fiducial" H 7885 5855 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7800 5900 50  0001 C CNN
F 3 "~" H 7800 5900 50  0001 C CNN
	1    7800 5900
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID10
U 1 1 62C96FE1
P 7800 6100
F 0 "FID10" H 7885 6146 50  0000 L CNN
F 1 "Fiducial" H 7885 6055 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7800 6100 50  0001 C CNN
F 3 "~" H 7800 6100 50  0001 C CNN
	1    7800 6100
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID12
U 1 1 62C98EBD
P 8450 5900
F 0 "FID12" H 8535 5946 50  0000 L CNN
F 1 "Fiducial" H 8535 5855 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 8450 5900 50  0001 C CNN
F 3 "~" H 8450 5900 50  0001 C CNN
	1    8450 5900
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID13
U 1 1 62C99E2B
P 8450 6100
F 0 "FID13" H 8535 6146 50  0000 L CNN
F 1 "Fiducial" H 8535 6055 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 8450 6100 50  0001 C CNN
F 3 "~" H 8450 6100 50  0001 C CNN
	1    8450 6100
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID11
U 1 1 62CB5326
P 7800 6300
F 0 "FID11" H 7885 6346 50  0000 L CNN
F 1 "Fiducial" H 7885 6255 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7800 6300 50  0001 C CNN
F 3 "~" H 7800 6300 50  0001 C CNN
	1    7800 6300
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID14
U 1 1 62CB54BB
P 8450 6300
F 0 "FID14" H 8535 6346 50  0000 L CNN
F 1 "Fiducial" H 8535 6255 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 8450 6300 50  0001 C CNN
F 3 "~" H 8450 6300 50  0001 C CNN
	1    8450 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 5450 4200 5550
Wire Wire Line
	4000 5350 4000 5550
Wire Wire Line
	3800 5250 3800 5550
Text Notes 7000 6050 0    50   ~ 0
trous oled
$Comp
L Mechanical:Fiducial FID5
U 1 1 62CDFF4E
P 7100 6150
F 0 "FID5" H 7185 6196 50  0000 L CNN
F 1 "Fiducial" H 7185 6105 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7100 6150 50  0001 C CNN
F 3 "~" H 7100 6150 50  0001 C CNN
	1    7100 6150
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID6
U 1 1 62CE01A7
P 7100 6300
F 0 "FID6" H 7185 6346 50  0000 L CNN
F 1 "Fiducial" H 7185 6255 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7100 6300 50  0001 C CNN
F 3 "~" H 7100 6300 50  0001 C CNN
	1    7100 6300
	1    0    0    -1  
$EndComp
Text Label 6400 6350 1    50   ~ 0
RadioL
$Comp
L Device:R R28
U 1 1 62C92FD7
P 10300 3750
F 0 "R28" V 10250 3550 50  0000 C CNN
F 1 "1k" V 10250 3900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 10230 3750 50  0001 C CNN
F 3 "~" H 10300 3750 50  0001 C CNN
	1    10300 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	10450 3750 10800 3750
Text Label 10800 3750 2    50   ~ 0
RadioL
Text Notes 4600 1450 0    50   ~ 0
ou L4940V5
Wire Wire Line
	3800 5250 4750 5250
Wire Wire Line
	4000 5350 4550 5350
Wire Notes Line
	5650 7650 6700 7650
Wire Notes Line
	2600 2300 6700 2300
Text Label 7250 4450 0    50   ~ 0
Buz
$Comp
L Device:Buzzer BZ1
U 1 1 62F12109
P 10000 5500
F 0 "BZ1" H 10200 5550 50  0000 C CNN
F 1 "Buzzer passif" H 10400 5450 50  0000 C CNN
F 2 "Buzzer_Beeper:Buzzer_12x9.5RM7.6" V 9975 5600 50  0001 C CNN
F 3 "~" V 9975 5600 50  0001 C CNN
	1    10000 5500
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_FET:BS170 Q3
U 1 1 62F13490
P 10000 5900
F 0 "Q3" H 10204 5946 50  0000 L CNN
F 1 "BS170" H 10204 5855 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92L_Inline_Wide" H 10200 5825 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BS170-D.PDF" H 10000 5900 50  0001 L CNN
	1    10000 5900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 62F54818
P 10100 6200
F 0 "#PWR025" H 10100 5950 50  0001 C CNN
F 1 "GND" H 10105 6027 50  0000 C CNN
F 2 "" H 10100 6200 50  0001 C CNN
F 3 "" H 10100 6200 50  0001 C CNN
	1    10100 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 5600 10100 5700
Wire Wire Line
	10100 6100 10100 6200
Wire Wire Line
	9800 5900 9400 5900
Text Label 9400 5900 0    50   ~ 0
Buz
Wire Wire Line
	10100 5400 10400 5400
$Comp
L Connector:Conn_01x01_Male J10
U 1 1 63216A9E
P 10750 5400
F 0 "J10" H 10900 5600 50  0000 R CNN
F 1 "Conn_01x01_Male" H 11150 5500 50  0000 R CNN
F 2 "Connector_Wire:SolderWire-0.25sqmm_1x01_D0.65mm_OD2mm" H 10750 5400 50  0001 C CNN
F 3 "~" H 10750 5400 50  0001 C CNN
	1    10750 5400
	-1   0    0    1   
$EndComp
Text Notes 8000 5800 0    50   ~ 0
trous IBT_2 3,2mm
Wire Notes Line
	6950 5200 8900 5200
Wire Notes Line
	8900 5200 8900 6450
Wire Notes Line
	8900 6450 6950 6450
Wire Notes Line
	6950 6450 6950 5200
Wire Notes Line
	9250 5200 11100 5200
Wire Notes Line
	11100 5200 11100 6450
Wire Notes Line
	11100 6450 9250 6450
Wire Notes Line
	9250 6450 9250 5200
Text Notes 9350 5350 0    59   ~ 0
Buzzer
Wire Wire Line
	9200 4800 9200 4750
Wire Notes Line
	11100 550  11100 2450
Wire Notes Line
	6950 5000 6950 2550
Wire Notes Line
	6950 2550 11100 2550
Wire Notes Line
	11100 2450 7950 2450
Wire Wire Line
	7250 3950 8600 3950
Wire Wire Line
	7250 4050 8600 4050
Wire Wire Line
	7250 4150 8600 4150
Wire Wire Line
	7250 4250 8600 4250
Wire Wire Line
	7250 4350 8600 4350
Wire Wire Line
	9600 4150 10800 4150
Wire Wire Line
	9600 4250 10800 4250
Wire Wire Line
	9600 4350 10800 4350
Wire Wire Line
	9600 4450 10800 4450
Wire Wire Line
	4400 5550 4800 5550
Wire Wire Line
	4300 6150 4300 6200
Wire Wire Line
	4300 6200 4650 6200
Wire Wire Line
	4650 6200 4650 5650
Wire Wire Line
	4650 5650 4800 5650
Wire Wire Line
	4800 5750 4700 5750
Wire Wire Line
	4700 5750 4700 5450
Wire Wire Line
	4200 5450 4700 5450
Wire Wire Line
	4550 6300 4550 5950
Wire Wire Line
	4550 5950 4800 5950
Wire Wire Line
	4800 6050 4750 6050
Wire Wire Line
	4750 6050 4750 5250
Wire Wire Line
	4800 5850 4550 5850
Wire Wire Line
	4550 5850 4550 5350
Text Notes 5050 5700 0    59   ~ 0
COM1\n
Text Notes 5050 5600 0    59   ~ 0
NO1
Text Notes 5050 5800 0    59   ~ 0
NC1
Text Notes 5050 5900 0    59   ~ 0
NO2
Text Notes 5050 6000 0    59   ~ 0
COM2
Text Notes 5050 6100 0    59   ~ 0
NC2
Wire Notes Line
	5350 5150 5350 6850
Wire Notes Line
	2600 6850 5350 6850
Wire Notes Line
	2600 5150 5350 5150
Wire Notes Line
	6950 5000 11100 5000
Wire Notes Line
	11100 5000 11100 2550
Wire Notes Line
	5650 5150 6700 5150
Wire Notes Line
	6700 5150 6700 7650
Wire Notes Line
	5650 7650 5650 5150
Text Label 4550 2500 0    59   ~ 0
ComCap
Text Notes 10200 6100 0    59   ~ 0
N-JFET
Wire Wire Line
	1150 900  2300 900 
$Comp
L Connector:Conn_01x06_Male J6
U 1 1 62D2AA24
P 6100 5850
F 0 "J6" V 6050 5800 50  0000 R CNN
F 1 "Conn_01x06_Male" V 5950 6050 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 6100 5850 50  0001 C CNN
F 3 "~" H 6100 5850 50  0001 C CNN
	1    6100 5850
	0    -1   1    0   
$EndComp
Wire Wire Line
	7250 4450 8600 4450
Wire Notes Line
	2600 5050 6700 5050
Wire Notes Line
	2600 2300 2600 5050
Wire Notes Line
	6700 2300 6700 5050
Wire Notes Line
	5350 7650 5350 6900
Wire Notes Line
	2600 7650 5350 7650
Wire Notes Line
	2600 6900 5350 6900
Text Notes 3600 6650 0    59   ~ 0
N-JFET
Wire Notes Line
	550  5400 2500 5400
Wire Notes Line
	550  2300 550  5400
Wire Notes Line
	2500 2300 2500 5400
Wire Wire Line
	6000 3850 6000 3950
Wire Wire Line
	4250 2500 4250 3150
Connection ~ 4250 3150
Wire Wire Line
	4250 3150 4500 3150
Text Label 6550 2500 2    59   ~ 0
24V=
$Comp
L Device:Fuse F1
U 1 1 62F5B4E8
P 6100 2500
F 0 "F1" V 6200 2500 50  0000 C CNN
F 1 "1A F" V 5994 2500 50  0000 C CNN
F 2 "Fuse:Fuseholder_Cylinder-5x20mm_Schurter_0031_8201_Horizontal_Open" V 6030 2500 50  0001 C CNN
F 3 "~" H 6100 2500 50  0001 C CNN
	1    6100 2500
	0    1    1    0   
$EndComp
NoConn ~ 8600 3350
NoConn ~ 8600 3250
NoConn ~ 8600 3150
Wire Notes Line
	550  5550 2500 5550
Wire Notes Line
	2500 5550 2500 7650
Wire Notes Line
	2500 7650 550  7650
Wire Notes Line
	550  7650 550  5550
$Comp
L power:GND #PWR05
U 1 1 62DAD803
P 1800 7150
F 0 "#PWR05" H 1800 6900 50  0001 C CNN
F 1 "GND" H 1805 6977 50  0000 C CNN
F 2 "" H 1800 7150 50  0001 C CNN
F 3 "" H 1800 7150 50  0001 C CNN
	1    1800 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 6900 1800 7150
Wire Wire Line
	1800 6500 1800 6400
$Comp
L Device:R R5
U 1 1 62DF46FC
P 1150 6700
F 0 "R5" V 1250 6650 50  0000 C CNN
F 1 "100k" V 1050 6650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1080 6700 50  0001 C CNN
F 3 "~" H 1150 6700 50  0001 C CNN
	1    1150 6700
	0    1    1    0   
$EndComp
Text Label 650  6700 0    59   ~ 0
ComCap
Wire Wire Line
	650  6700 1000 6700
$Comp
L Device:R R6
U 1 1 62E25852
P 1350 6950
F 0 "R6" H 1200 6900 50  0000 C CNN
F 1 "82k" H 1200 7000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1280 6950 50  0001 C CNN
F 3 "~" H 1350 6950 50  0001 C CNN
	1    1350 6950
	-1   0    0    1   
$EndComp
Wire Wire Line
	1300 6700 1350 6700
Wire Wire Line
	1350 6800 1350 6700
Connection ~ 1350 6700
Wire Wire Line
	1350 6700 1500 6700
$Comp
L power:GND #PWR03
U 1 1 62E6CE74
P 1350 7150
F 0 "#PWR03" H 1350 6900 50  0001 C CNN
F 1 "GND" H 1355 6977 50  0000 C CNN
F 2 "" H 1350 7150 50  0001 C CNN
F 3 "" H 1350 7150 50  0001 C CNN
	1    1350 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 7100 1350 7150
Wire Wire Line
	1800 6400 2150 6400
Wire Wire Line
	1800 6000 1800 5800
Text Label 2150 6400 2    59   ~ 0
PFus
Text Notes 950  7550 0    59   ~ 0
Détection fusion fusible F1
Wire Wire Line
	8600 3450 7250 3450
Text Label 7250 3450 0    59   ~ 0
PFus
$Comp
L Device:R R7
U 1 1 62ED5847
P 1800 6150
F 0 "R7" H 1650 6100 50  0000 C CNN
F 1 "10K" H 1650 6200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1730 6150 50  0001 C CNN
F 3 "~" H 1800 6150 50  0001 C CNN
	1    1800 6150
	-1   0    0    1   
$EndComp
Wire Wire Line
	1800 6300 1800 6400
Connection ~ 1800 6400
$Comp
L Transistor_BJT:BC548 Q1
U 1 1 62D88A65
P 1700 6700
F 0 "Q1" H 1891 6746 50  0000 L CNN
F 1 "BC548" H 1891 6655 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 1900 6625 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 1700 6700 50  0001 L CNN
	1    1700 6700
	1    0    0    -1  
$EndComp
Text Notes 1900 7250 0    59   ~ 0
ou BC546,\nBC547, \nBC548,\nBC549,\nBC550
Wire Wire Line
	6250 2500 6550 2500
Wire Wire Line
	4250 2500 5800 2500
Wire Wire Line
	6150 3000 6150 2900
Wire Wire Line
	6150 2900 6250 2900
Wire Wire Line
	6250 2800 5800 2800
Wire Wire Line
	5800 2800 5800 2500
Connection ~ 5800 2500
Wire Wire Line
	5800 2500 5950 2500
$Comp
L Device:R R?
U 1 1 62E25A24
P 4650 3150
AR Path="/62D5014D/62E25A24" Ref="R?"  Part="1" 
AR Path="/62E25A24" Ref="R13"  Part="1" 
F 0 "R13" V 4550 3000 50  0000 C CNN
F 1 "2,7k" V 4550 3300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 4580 3150 50  0001 C CNN
F 3 "~" H 4650 3150 50  0001 C CNN
	1    4650 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 3150 5000 3150
Wire Wire Line
	3000 3050 3000 3600
Wire Wire Line
	3100 3050 3100 3550
Wire Wire Line
	3200 3050 3200 3150
Wire Wire Line
	4250 3150 3200 3150
Connection ~ 3200 3150
Wire Wire Line
	3200 3150 3200 3450
Text Notes 3300 2900 0    59   ~ 0
Fins de course
Wire Notes Line style solid
	5050 2650 5050 2700
Wire Notes Line style solid
	5150 2650 5150 2700
Wire Notes Line style solid
	5200 2700 5200 2800
Wire Notes Line style solid
	5100 2800 5100 2700
Wire Notes Line style solid
	5100 2600 5100 2650
Wire Notes Line style solid
	5000 2600 5200 2600
Wire Notes Line style solid
	5200 2600 5200 2650
Wire Notes Line style solid
	5000 2800 5000 2600
Text Notes 4350 2700 0    50   ~ 0
Cellule photo
Text Notes 5250 2800 0    50   ~ 0
Commande\n  marche
$Comp
L Connector:Screw_Terminal_01x03 J5
U 1 1 632B2DF6
P 5100 2850
F 0 "J5" V 5000 2700 50  0000 R CNN
F 1 "Screw_Terminal_01x03" V 4900 2700 50  0000 R CNN
F 2 "Connector_Phoenix_MSTB:PhoenixContact_MSTBVA_2,5_3-G-5,08_1x03_P5.08mm_Vertical" H 5100 2850 50  0001 C CNN
F 3 "~" H 5100 2850 50  0001 C CNN
	1    5100 2850
	0    -1   -1   0   
$EndComp
Wire Notes Line style solid
	2950 2650 2950 2700
Wire Notes Line style solid
	3050 2650 3050 2700
Wire Notes Line style solid
	3100 2700 3100 2800
Wire Notes Line style solid
	3000 2800 3000 2700
Wire Notes Line style solid
	3000 2600 3000 2650
Wire Notes Line style solid
	3000 2600 3200 2600
Wire Notes Line style solid
	3100 2600 3100 2650
Wire Notes Line style solid
	3200 2800 3200 2600
$Comp
L power:GND #PWR0101
U 1 1 62EBA9FB
P 6100 6850
F 0 "#PWR0101" H 6100 6600 50  0001 C CNN
F 1 "GND" H 5900 6800 50  0000 C CNN
F 2 "" H 6100 6850 50  0001 C CNN
F 3 "" H 6100 6850 50  0001 C CNN
	1    6100 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 6500 6100 6850
Connection ~ 6100 6500
$Comp
L power:+5V #PWR0102
U 1 1 62EBC822
P 1800 5800
F 0 "#PWR0102" H 1800 5650 50  0001 C CNN
F 1 "+5V" H 1950 5850 50  0000 C CNN
F 2 "" H 1800 5800 50  0001 C CNN
F 3 "" H 1800 5800 50  0001 C CNN
	1    1800 5800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 62EBD3C2
P 10300 2700
F 0 "#PWR0103" H 10300 2550 50  0001 C CNN
F 1 "+5V" V 10400 2800 50  0000 C CNN
F 2 "" H 10300 2700 50  0001 C CNN
F 3 "" H 10300 2700 50  0001 C CNN
	1    10300 2700
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 62EBE166
P 10400 5350
F 0 "#PWR0104" H 10400 5200 50  0001 C CNN
F 1 "+5V" H 10250 5400 50  0000 C CNN
F 2 "" H 10400 5350 50  0001 C CNN
F 3 "" H 10400 5350 50  0001 C CNN
	1    10400 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 5350 10400 5400
Connection ~ 10400 5400
Wire Wire Line
	10400 5400 10550 5400
$Comp
L power:+5V #PWR0105
U 1 1 62ED5F3F
P 4400 3350
F 0 "#PWR0105" H 4400 3200 50  0001 C CNN
F 1 "+5V" H 4250 3400 50  0000 C CNN
F 2 "" H 4400 3350 50  0001 C CNN
F 3 "" H 4400 3350 50  0001 C CNN
	1    4400 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 1600 10300 1600
Wire Wire Line
	10300 1600 10300 1450
Connection ~ 10400 1600
$Comp
L power:+5V #PWR0106
U 1 1 62EED862
P 10300 1450
F 0 "#PWR0106" H 10300 1300 50  0001 C CNN
F 1 "+5V" H 10315 1623 50  0000 C CNN
F 2 "" H 10300 1450 50  0001 C CNN
F 3 "" H 10300 1450 50  0001 C CNN
	1    10300 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 2700 10300 2700
Wire Wire Line
	5050 1550 5350 1550
Connection ~ 4100 900 
Text Notes 7100 1100 0    50   ~ 0
Harpons
$Comp
L Connector:Conn_01x01_Male J9
U 1 1 62CD72A3
P 7350 1000
F 0 "J9" H 7300 1000 50  0000 R CNN
F 1 "Conn_01x01_Male" H 7600 1250 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 7350 1000 50  0001 C CNN
F 3 "~" H 7350 1000 50  0001 C CNN
	1    7350 1000
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J8
U 1 1 62CD651F
P 7350 900
F 0 "J8" H 7300 900 50  0000 R CNN
F 1 "Conn_01x01_Male" H 7600 1350 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 7350 900 50  0001 C CNN
F 3 "~" H 7350 900 50  0001 C CNN
	1    7350 900 
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR022
U 1 1 62C27742
P 7000 1100
F 0 "#PWR022" H 7000 850 50  0001 C CNN
F 1 "GND" H 7005 927 50  0000 C CNN
F 2 "" H 7000 1100 50  0001 C CNN
F 3 "" H 7000 1100 50  0001 C CNN
	1    7000 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1000 7000 1100
Wire Wire Line
	7150 1000 7000 1000
Text Notes 7000 800  0    59   ~ 0
Alimentation\nmodule IBT_2
Wire Wire Line
	4100 900  7150 900 
Wire Wire Line
	2850 900  4100 900 
Wire Notes Line
	7950 550  11100 550 
Wire Notes Line
	7950 550  7950 2450
Text Label 8100 1300 0    50   ~ 0
PRIS
Text Label 8100 1100 0    50   ~ 0
PLIS
$Comp
L Device:R R26
U 1 1 6310F759
P 9000 1600
F 0 "R26" H 9150 1550 50  0000 C CNN
F 1 "5k" H 9100 1650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 8930 1600 50  0001 C CNN
F 3 "~" H 9000 1600 50  0001 C CNN
	1    9000 1600
	-1   0    0    1   
$EndComp
$Comp
L Device:R R32
U 1 1 631278AE
P 9000 2000
F 0 "R32" H 9150 1950 50  0000 C CNN
F 1 "1k" H 9100 2050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 8930 2000 50  0001 C CNN
F 3 "~" H 9000 2000 50  0001 C CNN
	1    9000 2000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R18
U 1 1 631C9841
P 8300 1600
F 0 "R18" H 8450 1550 50  0000 C CNN
F 1 "5k" H 8400 1650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 8230 1600 50  0001 C CNN
F 3 "~" H 8300 1600 50  0001 C CNN
	1    8300 1600
	-1   0    0    1   
$EndComp
$Comp
L Device:R R24
U 1 1 631C9848
P 8300 2000
F 0 "R24" H 8450 1950 50  0000 C CNN
F 1 "1k" H 8400 2050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 8230 2000 50  0001 C CNN
F 3 "~" H 8300 2000 50  0001 C CNN
	1    8300 2000
	-1   0    0    1   
$EndComp
Wire Wire Line
	8300 1750 8300 1800
Connection ~ 8300 1800
Wire Wire Line
	8300 1800 8300 1850
$Comp
L power:GND #PWR023
U 1 1 6327580F
P 8300 2300
F 0 "#PWR023" H 8300 2050 50  0001 C CNN
F 1 "GND" H 8150 2350 50  0000 C CNN
F 2 "" H 8300 2300 50  0001 C CNN
F 3 "" H 8300 2300 50  0001 C CNN
	1    8300 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 1300 8100 1300
Wire Wire Line
	8300 1300 8300 1450
Wire Wire Line
	8100 1100 9000 1100
Wire Wire Line
	8650 1800 8650 1900
Wire Wire Line
	8300 1800 8650 1800
Wire Wire Line
	8300 2150 8300 2250
Wire Wire Line
	8650 2200 8650 2250
Wire Wire Line
	8650 2250 8300 2250
Connection ~ 8300 2250
Wire Wire Line
	8300 2250 8300 2300
Wire Wire Line
	8650 2250 9000 2250
Connection ~ 8650 2250
Wire Wire Line
	9000 2150 9000 2250
Wire Wire Line
	9000 1750 9000 1800
Wire Wire Line
	9000 1800 9200 1800
Wire Wire Line
	9200 1800 9200 1600
Connection ~ 9000 1800
Wire Wire Line
	9000 1800 9000 1850
Wire Wire Line
	9000 2250 9350 2250
Connection ~ 9000 2250
Wire Wire Line
	9000 1100 9000 1450
Wire Wire Line
	10050 1350 9950 1350
Wire Wire Line
	10050 1800 10050 1350
Wire Wire Line
	9650 1350 8650 1350
Wire Wire Line
	8650 1350 8650 1800
Connection ~ 8650 1800
Wire Wire Line
	10050 1800 10700 1800
Wire Wire Line
	9200 1600 9350 1600
Wire Wire Line
	9350 2200 9350 2250
Wire Wire Line
	9350 1900 9350 1600
Connection ~ 9350 1600
Wire Wire Line
	9350 1600 9650 1600
$EndSCHEMATC
