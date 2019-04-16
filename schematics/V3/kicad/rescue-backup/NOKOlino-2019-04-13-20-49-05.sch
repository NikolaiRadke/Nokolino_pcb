EESchema Schematic File Version 2
LIBS:NOKOlino-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:switches
LIBS:NOKOlino
LIBS:NOKO_2
LIBS:NOKOlino-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "NOKOlino Leiterplatte"
Date "2018-01-15"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L SW_Push SW1
U 1 1 5A5C9A74
P 3650 3500
F 0 "SW1" H 3700 3600 50  0000 L CNN
F 1 "SW1" H 3650 3450 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h13mm" H 3650 3700 50  0001 C CNN
F 3 "" H 3650 3700 50  0001 C CNN
	1    3650 3500
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW2
U 1 1 5A5C9B65
P 3650 4000
F 0 "SW2" H 3700 4100 50  0000 L CNN
F 1 "SW2" H 3650 3950 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h13mm" H 3650 4200 50  0001 C CNN
F 3 "" H 3650 4200 50  0001 C CNN
	1    3650 4000
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW3
U 1 1 5A5C9BA0
P 3650 4500
F 0 "SW3" H 3700 4600 50  0000 L CNN
F 1 "SW3" H 3650 4450 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h13mm" H 3650 4700 50  0001 C CNN
F 3 "" H 3650 4700 50  0001 C CNN
	1    3650 4500
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW4
U 1 1 5A5C9BD0
P 3650 5000
F 0 "SW4" H 3700 5100 50  0000 L CNN
F 1 "SW4" H 3650 4950 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h13mm" H 3650 5200 50  0001 C CNN
F 3 "" H 3650 5200 50  0001 C CNN
	1    3650 5000
	1    0    0    -1  
$EndComp
$Comp
L ATTINY85-20PU U2
U 1 1 5A5C9C69
P 6600 4800
F 0 "U2" H 5450 5200 50  0000 C CNN
F 1 "ATTINY85-20PU" H 7600 4400 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 7600 4800 50  0001 C CIN
F 3 "" H 6600 4800 50  0001 C CNN
	1    6600 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5A5CBB7E
P 8150 5450
F 0 "#PWR01" H 8150 5200 50  0001 C CNN
F 1 "GND" H 8150 5300 50  0000 C CNN
F 2 "" H 8150 5450 50  0001 C CNN
F 3 "" H 8150 5450 50  0001 C CNN
	1    8150 5450
	-1   0    0    -1  
$EndComp
NoConn ~ 5250 5050
$Comp
L JQ6500 M1
U 1 1 5A5CC541
P 5850 3600
F 0 "M1" H 5800 3650 50  0000 L CNN
F 1 "JQ6500" H 5700 3550 50  0000 L CNN
F 2 "NOKOlino:JQ6500-16p" H 5888 3450 50  0001 C CNN
F 3 "" H 5850 3600 50  0001 C CNN
	1    5850 3600
	1    0    0    -1  
$EndComp
$Comp
L TP4056 U1
U 1 1 5A5CC850
P 1950 4250
F 0 "U1" H 1950 4150 60  0000 C CNN
F 1 "TP4056" H 1950 4300 60  0000 C CNN
F 2 "NOKOlino:TP4056-Protect" H 1900 4150 60  0001 C CNN
F 3 "" H 1900 4150 60  0001 C CNN
	1    1950 4250
	1    0    0    -1  
$EndComp
Text GLabel 2750 3800 1    60   Input ~ 0
VCC
$Comp
L GND #PWR02
U 1 1 5A5CD6BD
P 3300 5400
F 0 "#PWR02" H 3300 5150 50  0001 C CNN
F 1 "GND" H 3300 5250 50  0000 C CNN
F 2 "" H 3300 5400 50  0001 C CNN
F 3 "" H 3300 5400 50  0001 C CNN
	1    3300 5400
	1    0    0    -1  
$EndComp
Text GLabel 8150 4350 1    60   Input ~ 0
VCC
Wire Wire Line
	3300 3500 3450 3500
Wire Wire Line
	3850 4000 4000 4000
Wire Wire Line
	4000 4500 3850 4500
Wire Wire Line
	4000 5000 3850 5000
Wire Wire Line
	3300 5000 3450 5000
Wire Wire Line
	3300 4500 3450 4500
Wire Wire Line
	3300 4000 3450 4000
Wire Wire Line
	3300 3500 3300 5400
Connection ~ 3300 4500
Connection ~ 3300 4000
Wire Wire Line
	4000 3500 4000 5000
Connection ~ 4000 4000
Connection ~ 4000 4500
Wire Wire Line
	7950 5050 8150 5050
Wire Wire Line
	8150 5050 8150 5450
Wire Wire Line
	2550 4000 3000 4000
Wire Wire Line
	2750 4000 2750 3800
Connection ~ 3300 5000
Wire Wire Line
	8150 4350 8150 4550
Wire Wire Line
	8150 4550 7950 4550
Wire Wire Line
	6500 3950 6600 3950
Wire Wire Line
	6600 3950 6600 4200
Wire Wire Line
	6600 4200 5150 4200
Wire Wire Line
	5150 4200 5150 4650
Wire Wire Line
	5150 4650 5250 4650
Wire Wire Line
	5200 3950 5050 3950
Wire Wire Line
	5050 3950 5050 4950
Wire Wire Line
	5050 4950 5250 4950
Wire Wire Line
	3850 3500 4100 3500
Wire Wire Line
	4100 3500 4100 4750
Connection ~ 4000 3500
$Comp
L GND #PWR03
U 1 1 5A5CE080
P 6750 3850
F 0 "#PWR03" H 6750 3600 50  0001 C CNN
F 1 "GND" H 6750 3700 50  0000 C CNN
F 2 "" H 6750 3850 50  0001 C CNN
F 3 "" H 6750 3850 50  0001 C CNN
	1    6750 3850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6500 3750 6750 3750
Wire Wire Line
	6750 3750 6750 3850
Text GLabel 6750 3000 1    60   Input ~ 0
VCC
Wire Wire Line
	6500 3650 6750 3650
Wire Wire Line
	6750 3650 6750 3000
$Comp
L GND #PWR04
U 1 1 5A5CE16D
P 4900 3950
F 0 "#PWR04" H 4900 3700 50  0001 C CNN
F 1 "GND" H 4900 3800 50  0000 C CNN
F 2 "" H 4900 3950 50  0001 C CNN
F 3 "" H 4900 3950 50  0001 C CNN
	1    4900 3950
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5200 3750 4900 3750
Wire Wire Line
	4900 3650 4900 3950
$Comp
L Speaker LS1
U 1 1 5A5CE1F7
P 7250 3250
F 0 "LS1" H 7300 3475 50  0000 R CNN
F 1 "Speaker" H 7300 3400 50  0000 R CNN
F 2 "NOKOlino:K20.40" H 7250 3050 50  0001 C CNN
F 3 "" H 7240 3200 50  0001 C CNN
	1    7250 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3250 7050 3250
Wire Wire Line
	6500 3350 7050 3350
NoConn ~ 5250 4550
$Comp
L PWR_FLAG #FLG05
U 1 1 5A5CDD3D
P 3000 3900
F 0 "#FLG05" H 3000 3975 50  0001 C CNN
F 1 "PWR_FLAG" H 3000 4050 50  0000 C CNN
F 2 "" H 3000 3900 50  0001 C CNN
F 3 "" H 3000 3900 50  0001 C CNN
	1    3000 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 4000 3000 3900
Connection ~ 2750 4000
NoConn ~ 6500 3450
NoConn ~ 6500 3550
NoConn ~ 6500 3850
NoConn ~ 5200 3250
NoConn ~ 5200 3350
NoConn ~ 5200 3450
NoConn ~ 5200 3550
NoConn ~ 5200 3650
NoConn ~ 5200 3850
Text GLabel 5750 2800 1    60   Input ~ 0
D+
Text GLabel 5950 2800 1    60   Input ~ 0
D-
Wire Wire Line
	5750 2800 5750 2900
Wire Wire Line
	5950 2800 5950 2900
$Comp
L CONN_01X08 J1
U 1 1 5AE8A061
P 1000 2750
F 0 "J1" H 1000 3200 50  0000 C CNN
F 1 "CONN_01X08" V 1100 2750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 1000 2750 50  0001 C CNN
F 3 "" H 1000 2750 50  0001 C CNN
	1    1000 2750
	-1   0    0    1   
$EndComp
Text GLabel 1850 3750 1    39   Input ~ 0
Akku+
Wire Wire Line
	1850 3850 1850 3750
Text GLabel 2050 3750 1    39   Input ~ 0
Akku-
Wire Wire Line
	2050 3850 2050 3750
Text GLabel 1300 3100 2    39   Input ~ 0
Akku+
Text GLabel 1300 3000 2    39   Input ~ 0
Akku-
Wire Wire Line
	1200 3000 1300 3000
Wire Wire Line
	1200 3100 1300 3100
Text GLabel 1300 2800 2    39   Input ~ 0
USB+
Wire Wire Line
	1200 2800 1300 2800
Text GLabel 1300 2700 2    39   Input ~ 0
D-
Text GLabel 1300 2600 2    39   Input ~ 0
D+
Wire Wire Line
	1200 2600 1300 2600
Wire Wire Line
	1200 2700 1300 2700
Text GLabel 1250 4000 0    39   Input ~ 0
USB+
Text GLabel 1250 4500 0    39   Input ~ 0
USB-
Wire Wire Line
	1250 4000 1350 4000
Wire Wire Line
	1250 4500 1350 4500
Text GLabel 1300 2900 2    39   Input ~ 0
USB-
Wire Wire Line
	1200 2900 1300 2900
Text GLabel 1300 2400 2    39   Input ~ 0
SW5
Wire Wire Line
	1200 2400 1300 2400
Text GLabel 2750 4500 2    39   Input ~ 0
SW5
$Comp
L GND #PWR06
U 1 1 5AE8B492
P 1650 2550
F 0 "#PWR06" H 1650 2300 50  0001 C CNN
F 1 "GND" H 1650 2400 50  0000 C CNN
F 2 "" H 1650 2550 50  0001 C CNN
F 3 "" H 1650 2550 50  0001 C CNN
	1    1650 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2500 1650 2500
Wire Wire Line
	1650 2500 1650 2550
Wire Wire Line
	2550 4500 2750 4500
$Comp
L PWR_FLAG #FLG07
U 1 1 5AE8BA19
P 4900 3650
F 0 "#FLG07" H 4900 3725 50  0001 C CNN
F 1 "PWR_FLAG" H 4900 3800 50  0000 C CNN
F 2 "" H 4900 3650 50  0001 C CNN
F 3 "" H 4900 3650 50  0001 C CNN
	1    4900 3650
	1    0    0    -1  
$EndComp
Connection ~ 4900 3750
Wire Wire Line
	4100 4750 5250 4750
$Comp
L R R1
U 1 1 5B8E9345
P 4325 5925
F 0 "R1" V 4405 5925 50  0000 C CNN
F 1 "220k" V 4325 5925 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4255 5925 50  0001 C CNN
F 3 "" H 4325 5925 50  0001 C CNN
	1    4325 5925
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5B8E9388
P 4325 6175
F 0 "#PWR08" H 4325 5925 50  0001 C CNN
F 1 "GND" H 4325 6025 50  0000 C CNN
F 2 "" H 4325 6175 50  0001 C CNN
F 3 "" H 4325 6175 50  0001 C CNN
	1    4325 6175
	1    0    0    -1  
$EndComp
Wire Wire Line
	4325 6075 4325 6175
$Comp
L Q_Photo_NPN Q1
U 1 1 5B8E9428
P 4225 5425
F 0 "Q1" H 4425 5475 50  0000 L CNN
F 1 "Q_Photo_NPN" H 4425 5375 50  0000 L CNN
F 2 "Connectors_JST:JST_XH_B02B-XH-A_02x2.50mm_Straight" H 4425 5525 50  0001 C CNN
F 3 "" H 4225 5425 50  0001 C CNN
	1    4225 5425
	1    0    0    -1  
$EndComp
Text GLabel 4325 5125 1    60   Input ~ 0
VCC
Wire Wire Line
	4325 5125 4325 5225
Wire Wire Line
	4325 5625 4325 5775
Wire Wire Line
	5250 4850 4750 4850
Wire Wire Line
	4750 4850 4750 5700
Wire Wire Line
	4750 5700 4325 5700
Connection ~ 4325 5700
$EndSCHEMATC
