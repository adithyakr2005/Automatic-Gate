#include<Servo.h>
Servo s1;
int trig=7;
int echo=6;
long timeInMicro;
long distanceInCm;

void setup() 
{
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);
  s1.attach(9);
}
void loop()  
{
  s1.write(0);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  timeInMicro= pulseIn(echo,HIGH);
  distanceInCm = ((timeInMicro/29)/2);

  Serial.println(distanceInCm);
  delay(1000);
  if(distanceInCm<=5){
    s1.write(90);
    delay(5000);
  }
}