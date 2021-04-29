#define echoPin 2
#define trigPin 3
#define servoPin 4

#include <Servo.h>
Servo servo;




void setup() {
  // put your setup code here, to run once:
pinMode(echoPin,INPUT);
pinMode(trigPin,OUTPUT);
servo.attach(4); 
}

void loop() {
  // put your main code here, to run repeatedly:
controlServo(DistanceF());
}

void controlServo(int distance){
  if(distance<=5){
    delay(750);
    servo.write(120);
    delay(3000);
    servo.write(0);
  }
}

int DistanceF(){
   long duration,distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH);
  distance=duration/58.2;
  Serial.println(distance);
  return distance;
}
