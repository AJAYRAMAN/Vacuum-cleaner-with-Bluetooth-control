int rmotor1=3;//right +
int rmotor2=4;//right -
int lmotor1=5;//left -
int lmotor2=6;//left +
int v1=7;//vacuum +
int v2=8;//vacuum -
int m1=9;//mop +
int m2=10;//mop -
int inbyte=0;
int ren=11;//right motor enable
int len=12;//left motor enable
int ven=A0;//vacuum enable
int men=A1;//mop enable
int echo=A2;
int trigger=A3;
float duration;
float distance;
void setup() {
 // put your setup code here, to run once:
pinMode(rmotor1, OUTPUT);//configuring each pins with its function
pinMode(rmotor2, OUTPUT);pinMode(lmotor1, OUTPUT);
pinMode(lmotor2, OUTPUT);
pinMode(v1, OUTPUT);
pinMode(v2, OUTPUT);
pinMode(m1, OUTPUT);
pinMode(m2, OUTPUT);
pinMode(echo,INPUT);
 pinMode(trigger,OUTPUT);
digitalWrite(rmotor1, LOW); //set both motors off for start-up
digitalWrite(rmotor2, LOW);
digitalWrite(lmotor1, LOW);
digitalWrite(lmotor2, LOW);
digitalWrite(v1, LOW);
digitalWrite(v2, LOW);
digitalWrite(m1, LOW);
digitalWrite(m2, LOW);
digitalWrite(ren, HIGH);//enabling all motors
digitalWrite(len, HIGH);
digitalWrite(ven, HIGH);
digitalWrite(men, HIGH);
Serial.begin(9600);
}
void loop() {
 // put your main code here, to run repeatedly:
 digitalWrite(trigger, LOW);
 delayMicroseconds(2);
 digitalWrite(trigger, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger, LOW);
 duration=pulseIn(echo,HIGH);
 distance=(duration*0.034)/2;
 if(distance<10)//stoping the robot when obstacle is less than 10cm
 {
 digitalWrite(rmotor1, LOW);
digitalWrite(rmotor2, LOW);
digitalWrite(lmotor1, LOW);
digitalWrite(lmotor2, LOW);
digitalWrite(lmotor2, LOW);
digitalWrite(v1, LOW);
digitalWrite(v2, LOW);
digitalWrite(m1, LOW);
digitalWrite(m2, LOW);
 }
else if (Serial.available() > 0)
{
inbyte = Serial.read();
}
switch(inbyte)
{
case 'S': // control to stop the robot
digitalWrite(rmotor1, LOW);
digitalWrite(rmotor2, LOW);
digitalWrite(lmotor1, LOW);
digitalWrite(lmotor2, LOW);
digitalWrite(lmotor2, LOW);
digitalWrite(v1, LOW);
digitalWrite(v2, LOW);
digitalWrite(m1, LOW);
digitalWrite(m2, LOW);
inbyte='*';
break;
case 'R': //control for right
digitalWrite(rmotor1, LOW);
digitalWrite(rmotor2, LOW);
digitalWrite(lmotor1, LOW);
digitalWrite(lmotor2, HIGH);
inbyte='*';
break;
case 'L': //control for left
digitalWrite(rmotor1, HIGH);
digitalWrite(rmotor2, LOW);
digitalWrite(lmotor1, LOW);
digitalWrite(lmotor2, LOW);
inbyte='*';
break;
case 'F': //control for forward
digitalWrite(rmotor1, HIGH);
digitalWrite(rmotor2, LOW);
digitalWrite(lmotor1, LOW);
digitalWrite(lmotor2, HIGH);
inbyte='*';
break;
case 'B': //control for backward
digitalWrite(rmotor1, LOW);
digitalWrite(rmotor2, HIGH);
digitalWrite(lmotor1, HIGH);
digitalWrite(lmotor2, LOW);
inbyte='*';
break;
case 'V'://vacuum on
digitalWrite(v1, HIGH);
digitalWrite(v2, LOW);
inbyte='*';
break;
case 'v'://vacuum off
digitalWrite(v1, LOW);
digitalWrite(v2, LOW);
inbyte='*';
break;
case 'M'://mop on
digitalWrite(m1, HIGH);
digitalWrite(m2, LOW);
inbyte='*';
break;
case 'm'://mop off
digitalWrite(m1, LOW);
digitalWrite(m2, LOW);
inbyte='*';
break;
}}
