#include "Arduino.h"
#include "Servo.h"

Servo myservo;

int pos = 90;

int sensorPin = A1; 
int sensorValue; 

//Ultrasonic
const int trigPin = 9; 
const int echoPin = 10;
float duration, distance; 

void setup() {
  Serial.begin(9600);
  myservo.attach(2);
  
  //Ultrasonic
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  

}

void loop() {
  
  //Ultrasonic
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration*.0343)/2; 
  
  sensorValue = analogRead(sensorPin); 
//  Serial.println("Distance : ");
//  Serial.println(distance);
  Serial.println("Analog Value : ");
  Serial.println(sensorValue);
  
  if (distance < 5){
    if (sensorValue < 850){
      for (pos = 90; pos <= 180; pos += 1) { 
      myservo.write(pos);              
      delay(15);                       
    }
    delay(2000);
    
      for (pos = 180; pos >= 90; pos -= 1) { 
      myservo.write(pos);
      delay(15);
      }
    }
  
    else {
      for (pos = 90; pos >= 0; pos -= 1) { 
      myservo.write(pos);              
      delay(15);                       
    }
    delay(2000);
  
      for (pos = 0; pos <= 90; pos += 1) { 
      myservo.write(pos);
      delay(15);
      } 
      }
  }
  else {
    delay(3000);
    }


}
