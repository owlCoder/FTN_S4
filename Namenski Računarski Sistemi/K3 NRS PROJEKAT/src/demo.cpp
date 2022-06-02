/*
    Napisati program koji prati stanje pwm signala na pinu 26 i
    ispisuje njegovu dužinu trajanja. Za generisanje signala koristiti funkciju
    pwmSin() sa parametrima 26, 2000 i 0.0. Nakon toga, izračunati i ispisati
    period oscilovanja signala. Period oscilovanja signala ispisati kao vreme
    proteklo izmedju dva maksimuma u signalu.
*/
#include<arduinoPlatform.h>
#include<tasks.h>
#include<interrupts.h>
#include<stdio.h>
#include<serial.h>
#include <pwm.h>
#include<data.h>

extern serial Serial;

int myPIN = 26;
int oldState, periodTime, startTime, elapsedTime;

void brojevi(int id, void * tptr)
{
    // promenljiva za preskakanje prvog intervala, koji nije potpun
    static int first = true;
    int newState = digitalRead(myPIN);
    if (oldState == 1  && newState == 0)
    {
        elapsedTime = millis() - startTime;
    }
    else if (oldState == 0 && newState ==1)
    {
        int time = millis();
        periodTime = time - startTime;
        startTime = time;

        if (!first)
        {
            Serial.print(elapsedTime);
            Serial.print(' ');
            Serial.println(periodTime);
        }
        first = false;
    }
    oldState = newState;
}

void setup()
{
    Serial.begin(9600);
    pwmSin(myPIN, 2000, 0.0);
    oldState = digitalRead(myPIN);
    startTime = millis();
    elapsedTime = 0;
    periodTime = 0;

    createTask(brojevi, 1, TASK_ENABLE, NULL);
}

void loop()
{

}

