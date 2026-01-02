#include <Arduino.h>

#ifdef ESP8266
#define MOTION_INPUT_PIN D5
#define LIGHT_OUTPUT_PIN D6
#else
#define MOTION_INPUT_PIN PB0
#define LIGHT_OUTPUT_PIN PB3
#endif

void setup()
{
    pinMode(MOTION_INPUT_PIN, INPUT);
    pinMode(LIGHT_OUTPUT_PIN, OUTPUT);
    digitalWrite(LIGHT_OUTPUT_PIN, LOW);
}

void loop()
{
    int isOn = digitalRead(MOTION_INPUT_PIN);
    if (isOn == HIGH) {
        digitalWrite(LIGHT_OUTPUT_PIN, HIGH);
        //  delay(5000);
    }
    else {
        digitalWrite(LIGHT_OUTPUT_PIN, LOW);
    }
}