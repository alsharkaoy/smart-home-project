#include <LiquidCrystal.h>
#include <Servo.h>
Servo myServo;
LiquidCrystal lcd(13,12,11,10,9,8);
const int trigPin = 7;
const int echoPin = 6;
long duration;
float value;
float time,distance;
int tmp = A1;
int sensorpin=A1;
int ledpin=4;
int sensorvalue=0;
unsigned long res1=0;
float value1=0.0;
  int button1=A2;
  int button2=A3;
  int button3=A4;

void setup() {
lcd.begin(16,2); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
  pinMode(tmp,INPUT);
  Serial.begin(9600);
  myServo.attach(5);
  myServo.write(0);
    pinMode(4, OUTPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
pinMode(A3,INPUT);
  pinMode(A4,INPUT);
}
void loop() {
  digitalWrite(7,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(7,LOW);
  time=pulseIn(6,HIGH);
  
  distance=(time*.0343)/2;
  lcd.setCursor(0,0);
  lcd.print("distance:");
  lcd.print(distance);
  Serial.println(distance);
  value = analogRead(tmp);
  float mv=value/1023.0;
  mv=mv*5;
  mv=mv-0.5;
  mv=mv*1000;
  float cl=mv/10;
   lcd.setCursor(0,1);
   lcd.print("Tmp:");
   lcd.print(cl);
   delay(1000);
  
 sensorvalue= analogRead(A1);
  value1=(sensorvalue/1023.0)*5.0;
  res1=(1000*value1)/(5-value1);
  
  Serial.println(res1);
  delay(10);
  if (res1>=1000){
    digitalWrite(4,HIGH);
  }
  else
  {
    digitalWrite(4,LOW);
  }
  if (button1==HIGH){
    myServo.write (180);
  }
}