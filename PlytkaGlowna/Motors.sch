EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x08 J4
U 1 1 60A3290A
P 3800 4300
F 0 "J4" H 3880 4292 50  0000 L CNN
F 1 "Conn_01x08" H 3880 4201 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 3800 4300 50  0001 C CNN
F 3 "~" H 3800 4300 50  0001 C CNN
	1    3800 4300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J5
U 1 1 60A344BE
P 4650 4400
F 0 "J5" H 4730 4392 50  0000 L CNN
F 1 "Conn_01x08" H 4730 4301 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 4650 4400 50  0001 C CNN
F 3 "~" H 4650 4400 50  0001 C CNN
	1    4650 4400
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 60A346CB
P 2750 4550
F 0 "#PWR0117" H 2750 4300 50  0001 C CNN
F 1 "GND" H 2755 4377 50  0000 C CNN
F 2 "" H 2750 4550 50  0001 C CNN
F 3 "" H 2750 4550 50  0001 C CNN
	1    2750 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 4000 2750 4000
Wire Wire Line
	2750 4000 2750 4450
Wire Wire Line
	3600 4700 3200 4700
Wire Wire Line
	2900 4700 2900 4450
Wire Wire Line
	2900 4450 2750 4450
Connection ~ 2750 4450
Wire Wire Line
	2750 4450 2750 4550
Wire Wire Line
	4850 4700 4850 4900
Wire Wire Line
	4850 4900 3200 4900
Wire Wire Line
	3200 4900 3200 4700
Connection ~ 3200 4700
Wire Wire Line
	3200 4700 2900 4700
Text GLabel 4850 4600 2    47   Input ~ 0
PWM2
Text GLabel 4850 4000 2    47   Input ~ 0
PWM1
Text GLabel 4850 4100 2    47   Input ~ 0
AIN2
Text GLabel 4850 4200 2    47   Input ~ 0
AIN1
Text GLabel 4850 4400 2    47   Input ~ 0
BIN1
Text GLabel 4850 4500 2    47   Input ~ 0
BIN2
Text GLabel 3600 4600 0    47   Input ~ 0
VMOT
Text GLabel 3600 4200 0    47   Input ~ 0
AO1
Text GLabel 3600 4300 0    47   Input ~ 0
AO2
Text GLabel 3600 4400 0    47   Input ~ 0
BO2
Text GLabel 3600 4500 0    47   Input ~ 0
BO1
$Comp
L power:+3.3V #PWR0118
U 1 1 60A36A05
P 3300 3800
F 0 "#PWR0118" H 3300 3650 50  0001 C CNN
F 1 "+3.3V" H 3315 3973 50  0000 C CNN
F 2 "" H 3300 3800 50  0001 C CNN
F 3 "" H 3300 3800 50  0001 C CNN
	1    3300 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3800 3300 3900
Wire Wire Line
	3300 4100 3600 4100
Wire Wire Line
	4850 4300 5250 4300
Wire Wire Line
	5250 4300 5250 3900
Wire Wire Line
	5250 3900 3300 3900
Connection ~ 3300 3900
Wire Wire Line
	3300 3900 3300 4100
Text Notes 2500 3200 0    118  ~ 24
Driver IC for Dual DC motor\n
Text GLabel 5700 3150 0    47   Output ~ 0
VMOT
Text GLabel 5950 3150 2    47   Input ~ 0
7,4V
Wire Wire Line
	5950 3150 5700 3150
Text GLabel 5950 3300 2    47   Output ~ 0
AIN2
Text GLabel 5950 3450 2    47   Output ~ 0
AIN1
Text GLabel 5950 3600 2    47   Output ~ 0
BIN1
Text GLabel 5950 3750 2    47   Output ~ 0
BIN2
Text GLabel 5850 3450 0    47   Input ~ 0
DIRECTION11
Text GLabel 5850 3300 0    47   Input ~ 0
DIRECTION12
Text GLabel 5850 3600 0    47   Input ~ 0
DIRECTION21
Text GLabel 5850 3750 0    47   Input ~ 0
DIRECTION22
Wire Wire Line
	5850 3750 5950 3750
Wire Wire Line
	5950 3600 5850 3600
Wire Wire Line
	5850 3450 5950 3450
Wire Wire Line
	5950 3300 5850 3300
Text Notes 6700 3200 0    118  ~ 24
Motors\n
Text GLabel 6800 3500 0    47   Input ~ 0
AO1
Text GLabel 6800 3400 0    47   Input ~ 0
AO2
Text GLabel 8250 3350 0    47   Input ~ 0
BO2
Text GLabel 8250 3450 0    47   Input ~ 0
BO1
$Comp
L Connector_Generic:Conn_01x06 J6
U 1 1 60A54B54
P 7000 3600
F 0 "J6" H 7080 3592 50  0000 L CNN
F 1 "Conn_01x06" H 7080 3501 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 7000 3600 50  0001 C CNN
F 3 "~" H 7000 3600 50  0001 C CNN
	1    7000 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J7
U 1 1 60A553FF
P 8450 3550
F 0 "J7" H 8530 3542 50  0000 L CNN
F 1 "Conn_01x06" H 8530 3451 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 8450 3550 50  0001 C CNN
F 3 "~" H 8450 3550 50  0001 C CNN
	1    8450 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3600 6500 3600
$Comp
L power:GND #PWR0121
U 1 1 60A7144E
P 8050 4000
F 0 "#PWR0121" H 8050 3750 50  0001 C CNN
F 1 "GND" H 8055 3827 50  0000 C CNN
F 2 "" H 8050 4000 50  0001 C CNN
F 3 "" H 8050 4000 50  0001 C CNN
	1    8050 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3850 8050 3850
Wire Wire Line
	8050 3850 8050 4000
$Comp
L power:GND #PWR0122
U 1 1 60A71C58
P 6600 4000
F 0 "#PWR0122" H 6600 3750 50  0001 C CNN
F 1 "GND" H 6605 3827 50  0000 C CNN
F 2 "" H 6600 4000 50  0001 C CNN
F 3 "" H 6600 4000 50  0001 C CNN
	1    6600 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3900 6600 3900
Wire Wire Line
	6600 3900 6600 4000
Text GLabel 8050 4550 2    47   Output ~ 0
ENCODER22
Text GLabel 8050 4450 2    47   Output ~ 0
ENCODER21
Text GLabel 6700 4650 2    47   Output ~ 0
ENCODER11
Wire Notes Line
	6250 2800 6250 5150
Text GLabel 6700 4550 2    47   Output ~ 0
ENCODER12
Wire Wire Line
	8250 3650 7800 3650
Wire Wire Line
	7800 3650 7800 4450
Wire Wire Line
	7800 4450 8050 4450
Wire Wire Line
	8050 4550 7700 4550
Wire Wire Line
	7700 4550 7700 3750
Wire Wire Line
	7700 3750 8250 3750
Wire Wire Line
	6700 4550 6450 4550
Wire Wire Line
	6450 4550 6450 3800
Wire Wire Line
	6450 3800 6800 3800
Wire Wire Line
	6700 4650 6350 4650
Wire Wire Line
	6350 4650 6350 3700
Wire Wire Line
	6350 3700 6800 3700
Wire Notes Line
	9100 2800 9100 5150
Wire Notes Line
	2300 5150 9100 5150
Wire Notes Line
	2300 2800 9100 2800
Wire Notes Line
	2300 2800 2300 5150
$Comp
L power:+5V #PWR0119
U 1 1 60915818
P 6500 3600
F 0 "#PWR0119" H 6500 3450 50  0001 C CNN
F 1 "+5V" H 6515 3773 50  0000 C CNN
F 2 "" H 6500 3600 50  0001 C CNN
F 3 "" H 6500 3600 50  0001 C CNN
	1    6500 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3550 7950 3550
$Comp
L power:+5V #PWR0120
U 1 1 60916B6F
P 7950 3550
F 0 "#PWR0120" H 7950 3400 50  0001 C CNN
F 1 "+5V" H 7965 3723 50  0000 C CNN
F 2 "" H 7950 3550 50  0001 C CNN
F 3 "" H 7950 3550 50  0001 C CNN
	1    7950 3550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
