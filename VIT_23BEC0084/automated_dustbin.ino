#include <Servo.h>
#include <Wire.h>

Servo servo_1;
int trigPin = 9;
int echoPin = 8;

long duration;
int distance;

void setup(){
  servo_1.attach(7, 500, 2500);
  servo_1.write(90);  //initially keeping the bin lid closed
  delay(2000);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if ( distance <= 25   ){  
    servo_1.write(0);  //when distance to bin is less than 25cm than bin opens lid
    delay(3000);
  }
  else{
      servo_1.write(90);  //when there is more than 25cm distance to the bin than bin lid closes
  }
}