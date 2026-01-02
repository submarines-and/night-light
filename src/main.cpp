#include <Arduino.h>

#ifdef ESP8266
#define MOTION_INPUT_PIN A0
#define LIGHT_OUTPUT_PIN D6
#else
#define MOTION_INPUT_PIN PB0
#define LIGHT_OUTPUT_PIN PB3
#endif

void setup()
{
    Serial.begin(115200);
    pinMode(LIGHT_OUTPUT_PIN, OUTPUT);
}

void loop()
{
    int lightValue = analogRead(MOTION_INPUT_PIN);

    // log in debug
#ifdef ESP8266
    Serial.println(lightValue);
#endif

    if (lightValue > 25 && lightValue < 500) {
        digitalWrite(LIGHT_OUTPUT_PIN, HIGH);
        delay(20 * 1000); // on duration
    }
    else {
        digitalWrite(LIGHT_OUTPUT_PIN, LOW);
    }
}