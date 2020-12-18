int senpin=A7;
int buzzer=12;

long val=0;
long average = 0;
int threshold=66;

String answ;
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4); 


void setup() {
  pinMode(senpin,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  
}

void loop() {

if(mySerial.available()!=0){
answ=Serial.readStringUntil('\n');
threshold=answ.toInt();
}

sensor();

}
 

void sensor(){
   for (int i=0; i < 160; i++) {
 average = average + analogRead(senpin);
 }
 val = average/160;
 average=0;
 delay (10);

 Serial.print(val);
Serial.println(threshold);
 
 if (val>= threshold){
   mySerial.println(val);
  digitalWrite(buzzer,HIGH);
  delay (150);
   digitalWrite(buzzer,LOW);
    delay (150);
     digitalWrite(buzzer,HIGH);
  delay (200);
   digitalWrite(buzzer,LOW);
     delay (900);
}}
