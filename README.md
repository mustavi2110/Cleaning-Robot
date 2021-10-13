# Cleaning_Robot
Cleaning robot is a compact robotics
system which provides floor cleaning service in room and big offices reducing human labor. Our
robot is designed to clean floors with vacuum cleaner. The purpose of this project is to design
and implement a vacuum robot autonomous and manual via mobile application.
Components: <br>
The following parts and tools are required for building this project:<br>
Parts:<br>
● 2x 200rpm Geared motors
● 2x Wheels for motors
● 1x Arduino UNO
● 1x GSM Modulo
● 1x L293D motor driver board
● 1x 12V Lipo 1100 MAA rechargeable battery
● 1x Lipo charger
● 2x TIP122 NPN power transistors
● 1x n-channel MOSFET
● Vacuum cleaner
● Male-male/ female-female/ male-female jumper wires
● Male/female headers
● Bread board
● Plywood base
<br>
Tools:
<br>
● Soldering iron solder
● Soldering paste
● Soldering Led
● Soldering stand
● Hot glue gun and glue sticks
● Pliers
● Paper cutter
● Tape
<br>
Procedure In Details:<br>
● The GSM module was connected to the arduino through tx and rx pin of GSM module
with pin 10 and 11 of arduino. As SoftwareSerial.h library allow to connect except the tx
and rx of arduino. <br>
● The input pins of the motor driver were connected with the arduino and the output pins
were connected to the dc gear motors. EN1 and EN2 pins were connected with the
arduino PWM pins 5 and 6 respectively. IN1, IN2, IN3 and IN4 were connected with
arduino pin 2, 3, 4 and 7 respectively.<br>
● The output pins of motor driver OUT1 and OUT2 were connected to the terminals of the
left hand side motor and the OUT3 and OUT4 were connected to the terminals of right
hand side motor.<br>
● To control the vacuum cleaner, a n-channel MOSFET was connected with the arduino
microcontroller. The gate of the MOSFET was connected with pin 13 of the arduino. The
vacuum cleaner was connected with the drain terminal and a free-wheeling diode
connected parallel to the vacuum cleaner.<br>
● Then the arduino, GSM module, motor driver and MOSFET was energized with external
power supply and the robot is driven by two high speed motors with gears.<br>
● To receive the serial data from the GSM module SoftwareSerial.h library was used. The
message from the GSM was received byte wise and stored in a sting.<br>
● As per the information stored in the string, the motor was driven sending information
from arduino through the motor driver to the motor.<br>
● The vacuum cleaner was controlled by sending instructions from arduino to the
MOSFET. Then the vacuum cleaner was driven by the MOSFET with high current.<br>
● A arduino program was implemented to receive the message using GSM module and to
control the robot car as per the information of the message.<br>
● The cleaning performance of our robot was tested on a smooth floor where there was
floor some dry waste and the floor was efficiently cleaned within some moments.<br>
● It should be noted that the robot was built to stay very close to ground to enable more
suction and detect small obstacle. Any obstacle that could not be detected must be
higher than 1.5cm which is essentially not a threat to the robot navigation.<br>
● To control the car , we need to send message .Here are the instructions:<br>
● F: Forward
● B : Backward
● S: Stop
● L: Left
● R: Right
● C: Clean
<br>
After configuring the buttons if we press specific buttons the robot will move.<br>
● Forward: Pressing ‘F’ button will make the robot go forward direction. The left and right
motors will get HIGH on their positive connected pins and move forward. The negative
pins will get LOW voltage. <br>
● Backward: Pressing ‘B’ button will make the robot go on Reverse direction. The left and
right motors will get LOW on their positive connected pins and HIGH on negative pins
which will make them go on reverse direction.<br>
● Stop: If we press the stop button the robot will stop moving. The motors will get LOW on
their pins and the motors will stop.<br>
● Left: After pressing the ‘L’ button the robot will go on the left side with the right side
motors moving on forward direction and left side motor won’t move. For this, Left motors
will get LOW on their pins while right motor will get HIGH on positive pin.<br>
● Right: After pressing the ‘R’ button the robot will go on the right side with the left side
motors moving on forward direction and right side motor won’t move. For this, right
motors will get LOW on their pins while left motor will get HIGH on positive pin.<br>
● Clean:After Pressing the ‘C’ button the robot will start cleaning the floor with vacuum .
For this, we will make the vacuum pin HIGH .
