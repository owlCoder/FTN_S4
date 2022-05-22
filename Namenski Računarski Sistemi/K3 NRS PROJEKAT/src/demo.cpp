#include<arduinoPlatform.h>
#include<tasks.h>
#include<interrupts.h>
#include<stdio.h>
#include<serial.h>
#include<pwm.h>
#include<data.h>

extern serial Serial;

char *r;

void broj(int id, void *tptr)
{
    if(available())
    {
        r = read();
        Serial.writeln(r);
        delete[] r;
    }
}

void brojevi(int id, void *tptr)
{
    if(available())
    {
        r = readAll();
        Serial.writeln(r);
        delete[] r;
    }
}

void setup()
{
    Serial.begin(9600);

    /// //////////////////////////////////////////////////////////////////////
    /// ////////// STARTOVANJE GENERATORA - GENERISE BROJEVE U POZADINI //////
    /// startStopDataGeneration(START_GENERATION ILI START_GENERATION,  //////
    ///                         TIP GENERISANJA (SAME, RANDOM, SIN),    //////
    ///                         POCETAK INTERVALA,                      //////
    ///                         KRAJ INTERVALA,                         //////
    ///                         PROCENAT GRESKE (OD 0.0 DO 1.0)         //////
    ///                         NA KOLIKO MS SE GENERISE SLOG           //////
    ///                                                                 //////
    ///     NAPOMENA: UGRADJENA JE MOGUCNOST "PAUZIRANJA" GENERATORA!   //////
    /// //////////////////////////////////////////////////////////////////////
    startStopDataGeneration(START_GENERATION, RANDOM, 1, 5, 0.0, 200);

    /// createTask(broj,   50, TASK_ENABLE,  NULL); /// read()
    createTask(brojevi,   500, TASK_ENABLE,  NULL); /// readAll();
}

void loop()
{

}
