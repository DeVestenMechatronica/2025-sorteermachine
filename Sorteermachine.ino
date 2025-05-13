#include <Servo.h> 
 
Servo myservo;    // een variabele om de servo aan te sturen
int potpin = 0;   // analoge pin wordt gebruikt door de potmeter
int val;          // lees de variabele waarde van de potmeter
const int trigPin = 10;
const int echoPin = 12;
int led = 8;

float duration, distance;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myservo.attach(9);  // de servo is verbonden met pin 9 
}

void loop() {
  digitalWrite(led, LOW);
  myservo.write(60);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
 if (distance < 4 || distance > 5){
  myservo.write(60);
  delay(15);
  //myservo.write(0);
 }
 else {
  myservo.write(0);
  delay(5000);
 }
                            // wacht tot de servo er is gekomen 
}