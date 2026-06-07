#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 2;
const int tempPin = A0;
const int redLED = 3;
const int greenLED = 5;

Servo gate;

bool doorOpen = false;
bool doorMoving = false;
bool readyToOpen = true;

long doorTimer = 0;
long lastPrint = 0;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  gate.attach(servoPin);
  gate.write(0);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float distance = pulseIn(echoPin, HIGH) * 0.034 / 2;

  if (distance > 20) {
    readyToOpen = true;
  }

  if (distance > 0 && distance <= 20 && readyToOpen && !doorOpen && !doorMoving) {
    gate.write(90);
    doorMoving = true;
    doorOpen = true;
    readyToOpen = false;
    doorTimer = millis();
  }

  if (doorOpen && millis() - doorTimer >= 3000 && !doorMoving) {
    gate.write(0);
    doorMoving = true;
    doorTimer = millis();
  }

  if (doorMoving && millis() - doorTimer >= 600) {
    doorMoving = false;
    doorOpen = gate.read() == 90;
  }
if(distance < 20)
{
  doorOpen = true;
}
  float temperature =
    (analogRead(tempPin) * 5.0 / 1023.0 - 0.5) * 100;

  digitalWrite(greenLED, temperature < 28);
  digitalWrite(redLED, temperature >= 28);

  if (millis() - lastPrint >= 1000) {
    lastPrint = millis();

    String doorState =
      doorMoving ? "MOVING" :
      doorOpen ? "OPEN" : "CLOSED";

    Serial.println(
      "Distance: " + String(distance) + " cm | " +
      "Temp: " + String(temperature) + " C | " +
      "Door: " + doorState + " | " +
      "Status: " + String(temperature < 28 ? "SAFE" : "CRITICAL")
    );
  }
}
