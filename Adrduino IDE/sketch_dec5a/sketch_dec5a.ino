// Include necessary libraries
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <Arduino.h>

// Define the LM35 sensor pin
const int lm35Pin = A0;

// Define the onboard LED pin
const int ledPin = 13;

// Define temperature thresholds
const int lowerThreshold = 30;
const int higherThreshold = 30;

// Variables to store temperature readings
int temperature;

// Function to blink LED based on temperature
void blinkLED(int delayTime) {
    digitalWrite(ledPin, HIGH);
    delay(delayTime);
    digitalWrite(ledPin, LOW);
    delay(delayTime);
}

void setup() {
    // Set LED pin as OUTPUT
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Read temperature from LM35 sensor
    temperature = analogRead(lm35Pin);

    // Convert analog reading to temperature in degrees Celsius
    temperature = temperature * 0.48828125;

    // Check temperature and control LED blink
    if (temperature < lowerThreshold) {
        blinkLED(250);  // Blink every 250 milliseconds
    } else if (temperature > higherThreshold) {
        blinkLED(500);  // Blink every 500 milliseconds
    }
}
