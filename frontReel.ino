#include "CytronMotorDriver.h"

CytronMD motor(PWM_DIR, 3, 4); // PWM = Pin 3, DIR = Pin 4.

int ledred = 7;
int ledgreen = 5;
int button = 2;

int readValue = 0;
int potValue = 0;
int buttonstate = 0;

void setup()
{
    Serial.begin(9600);

    pinMode(ledred, OUTPUT);
    pinMode(ledgreen, OUTPUT);
}

void loop()
{
    readValue = analogRead(A0);
    potValue = map(readValue, 0, 1024, 0, 255);
    Serial.println(potValue);

    buttonstate = digitalRead(button);
    if (buttonstate == HIGH)
    {

        digitalWrite(ledgreen, HIGH);
        digitalWrite(ledred, LOW);
        motor.setSpeed(potValue);
    }
    else
    {

        digitalWrite(ledred, HIGH);
        digitalWrite(ledgreen, LOW);
        motor.setSpeed(LOW);
    }
}
