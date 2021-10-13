#include<SoftwareSerial.h>
#define Tx 11
#define Rx 12
//--------------------------- Left motor config ----------------
#define left_Enable  5
#define left_pos  2
#define left_neg  3
//--------------------------- Right motor config ----------------
#define right_Enable  6
#define right_pos  4
#define right_neg  7
#define vacume  13              // Vacume
//---------------------------------Duty Cycles for Left and Right Motors-----------------
int leftDuty = 255;
int rightDuty = 255;

SoftwareSerial sms =  SoftwareSerial(Rx, Tx);
char c;
String message = "";

void setup() {
    pinMode(vacume, OUTPUT);
    pinMode(Rx, INPUT);
    pinMode(Tx, OUTPUT);
    sms.begin(9600);
    
    pinMode(left_Enable, OUTPUT);     pinMode(right_Enable, OUTPUT);
    pinMode(left_pos, OUTPUT);        pinMode(right_pos, OUTPUT);
    pinMode(left_neg, OUTPUT);        pinMode(right_neg, OUTPUT);
}

void loop() {
    forward();
    delay(2000);
    sweep();
    STOP();

    
    message = "";
    while(sms.available())
    {
      c = sms.read();
      message += c;
    }
    if (message == "")
      goto skip;

  skip:
  {
    
  }
}
void forward(){
  analogWrite(left_Enable, leftDuty);     analogWrite(right_Enable, rightDuty);
  digitalWrite(left_pos, HIGH);           digitalWrite(right_pos, HIGH);
  digitalWrite(left_neg, LOW);            digitalWrite(right_neg, LOW);
}
void backward(){
  analogWrite(left_Enable, leftDuty);       analogWrite(right_Enable, rightDuty);
  digitalWrite(left_pos, LOW);              digitalWrite(right_pos, LOW);
  digitalWrite(left_neg, HIGH);             digitalWrite(right_neg, HIGH);
}
void sweep(){
  forward();
  digitalWrite(vacume, HIGH);
  delay(2000);
  turnRight();    turnRight();
  delay(2000);
  turnLeft();     turnLeft();
  delay(2000);
  digitalWrite(vacume, LOW);
}
void turnLeft(){
  analogWrite(left_Enable, 0);        analogWrite(right_Enable, rightDuty);
                                      digitalWrite(right_pos, HIGH);
                                      digitalWrite(right_neg, LOW);
  delay(100);
  forward();
}
void turnRight(){
  analogWrite(left_Enable, leftDuty);   analogWrite(right_Enable, 0);
  digitalWrite(left_pos, HIGH);
  digitalWrite(left_neg, LOW);
  delay(100);
  forward();
}
void STOP(){
  analogWrite(left_Enable, 0);      analogWrite(right_Enable, 0);
  digitalWrite(vacume, LOW);
}
