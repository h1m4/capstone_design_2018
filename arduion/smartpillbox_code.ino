#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3); 

int sw=8,led=5, buz=11;
int led2=6;
int led3=7;

//

void setup(){

  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(buz,OUTPUT);
  pinMode(sw,INPUT);

  Serial.begin(9600);

  mySerial.begin(9600);

}

//

void loop(){

  if(mySerial.available()){

    char r=mySerial.read();

    Serial.write(r);

    if(r=='1'){ // 1.아두이노에서 블루투스 신호를 받으면

      digitalWrite(led,HIGH); // 2.피에조에서 소리가 나오고,LED에서 불이 켜지고  

      digitalWrite(buz,HIGH);

    }
if(r=='2'){ // 1.아두이노에서 블루투스 신호를 받으면

      digitalWrite(led2,HIGH); // 2.피에조에서 소리가 나오고,LED에서 불이 켜지고  

      digitalWrite(buz,HIGH);

    }
    if(r=='3'){ // 1.아두이노에서 블루투스 신호를 받으면

      digitalWrite(led3,HIGH); // 2.피에조에서 소리가 나오고,LED에서 불이 켜지고  

      digitalWrite(buz,HIGH);

    }
  }

  //

  if(Serial.available()){

    mySerial.write(Serial.read());

  }

  //

  if(digitalRead(sw)){ // 3.스위치를 누르면 소리와 불이 꺼지는

    digitalWrite(led,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(buz,LOW);

  }

}
