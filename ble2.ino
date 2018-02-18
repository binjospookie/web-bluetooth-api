#include <SoftwareSerial.h>

int green_pin = 2;
int red_pin = 3;
int blue_pin = 4;
int BLINK_STEPS = 3;
int BLINK_DELAY = 100;

SoftwareSerial mySerial(7, 8); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(green_pin, OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
}

int code;

void loop() {
  if (mySerial.available()) {
    code = mySerial.read();

    shutDownAll();

    if (code > 0 && code < 5) {
     analogWrite(code, 200);
    }

    if (code == 1) {
      blinked();
    }
  }
}

void shutDownAll() {
  analogWrite(green_pin, 0);
  analogWrite(red_pin, 0);
  analogWrite(blue_pin, 0);
}

void blinked() {
  int steps = 0;

  while(steps <= BLINK_STEPS) {
   analogWrite(green_pin, 200);
   delay(BLINK_DELAY);
   analogWrite(green_pin, 0);
   delay(BLINK_DELAY);
   analogWrite(red_pin, 200);
   delay(BLINK_DELAY);
   analogWrite(red_pin, 0);
   delay(BLINK_DELAY);
   analogWrite(blue_pin, 200);
   delay(BLINK_DELAY);
   analogWrite(blue_pin, 0);
   delay(BLINK_DELAY);

   steps += 1;
  }
}
