#include <Arduino.h>

#ifdef ESP8266
#define MOTION_INPUT_PIN A0
#define LIGHT_OUTPUT_PIN D6
#else
#define MOTION_INPUT_PIN A3
#define LIGHT_OUTPUT_PIN PB1
#endif

void setup()
{

// debug mode
#ifdef ESP8266
    Serial.begin(115200);
#endif

    pinMode(LIGHT_OUTPUT_PIN, OUTPUT);
}

void loop()
{
    int lightValue = analogRead(MOTION_INPUT_PIN);

// debug log
#ifdef ESP8266
    Serial.println(lightValue);
#endif

    // when motion sensor has not triggered, value floats between 0 and 15-ish so check for a minimum value as "activity registered"
    // then set a arbitrary max cap, for when it should be active
    if (lightValue > 25 && lightValue < 500) {
        digitalWrite(LIGHT_OUTPUT_PIN, HIGH);
        delay(20 * 1000); // on duration
    }
    else {
        digitalWrite(LIGHT_OUTPUT_PIN, LOW);
    }
}