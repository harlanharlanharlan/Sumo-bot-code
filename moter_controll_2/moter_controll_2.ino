int x;
int y;
int b;
#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
void setup() {
  delay(3000);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  while (! Serial) {
    delay(1);
  }
  lox.begin();
}
void loop() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);
  b = measure.RangeMilliMeter;
  if ((x < 500)||(b < 50)) {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if ((y < 500)||(b < 50)) {
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  }
  x = analogRead(3);
  y = analogRead(2);
  Serial.println(b);
  Serial.println(x);
  Serial.println(y);
  delay(10);
}
