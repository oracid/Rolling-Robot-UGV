// UGV-RollingRobot - 10/07/2022
void(* resetFunc) (void) = 0;             // soft reset function
#include <Servo.h>
Servo RF,RB,LF,LB;                        // servos
int Bp=A0, Speed=50;

void setup() {
  delay(500);                             // for reset consideration
  Serial.begin(9600);
  pinMode(Bp,INPUT_PULLUP);               // start/stop/reset button attachment
  RF.attach(2,500,2500);RF.write(90);     // right front servo initialization
  RB.attach(3,500,2500);RB.write(90);     // right back  servo initialization
  LF.attach(4,500,2500);LF.write(90);     // left  front servo initialization
  LB.attach(5,500,2500);LB.write(90);     // left  back  servo initialization
  Serial.print("\n\t To start, click on the Start button"); while(digitalRead(Bp)); delay(400); Serial.print("\n\t Started");
}

void loop() {
  if (! digitalRead(Bp)) resetFunc();
  Go( 15); delay(5000);                   // example of sequences
  Go( 20); delay(5000);
  Go( 75); delay(5000);
  Go(135); delay(3000);
  Go(315); delay(3000);
  Go( 45); delay(3000);
  Go(225); delay(3000);
}

void Go(int a){
  // Value of a
  // Forward  : from  15 to  44 turn right,  45 straight forward,   from  75 to  46 turn left
  // Backward : from 195 to 224 turn left,  225 straight Backward,  from 255 to 226 turn right
  // Left spin spot : 135  ,  Right spin spot : 315
  float S=sin(a*PI/180), C=cos(a*PI/180);  //Serial.print(String()+("\n\t a=")+a+("\t S=")+S+("\t C=")+C+("\t R=")+(90+(Speed*S))+("\t L=")+(90-(Speed*C)));
  RF.write(90+(Speed*S));  RB.write(90+(Speed*S));
  LF.write(90-(Speed*C));  LB.write(90-(Speed*C));
}
