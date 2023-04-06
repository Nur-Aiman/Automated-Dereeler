#include "CytronMotorDriver.h"

CytronMD motor(PWM_DIR, 3, 4); // PWM = Pin 3, DIR = Pin 4.

int ledred = 7;
int ledgreen = 5;
int button = 2;
int buttonstate = 0;

void setup()
{
    Serial.begin(9600);

    pinMode(ledred, OUTPUT);
    pinMode(ledgreen, OUTPUT);
}
void loop()
{
    buttonstate = digitalRead(button);
    if (buttonstate == HIGH)
    {

        digitalWrite(ledgreen, HIGH);
        digitalWrite(ledred, LOW);
        motor.setSpeed(255);
    }
    else
    {

        digitalWrite(ledred, HIGH);
        digitalWrite(ledgreen, LOW);
        motor.setSpeed(LOW);
    }
}
