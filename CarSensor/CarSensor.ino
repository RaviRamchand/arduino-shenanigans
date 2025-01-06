#include <Servo.h>
Servo servo;

//Ultrasonic sensor and Servo pin declaration
int trigPin = 13;
int echoPin = 12;
int servoPin = 8;

float distance;
long duration;

void setup() {
  //pin and servo set up
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo.attach(servoPin);

  servo.write(0);

  Serial.begin(9600);
}

void loop() {

  // Ultrasonic Sensor logic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;

  //If car is within range rotate servo to 90 to open the 'gate'
  if (distance > 4 && distance < 10) {
    servo.write(90);
    Serial.println(distance);

  } else {
    servo.write(0);
  }
}
