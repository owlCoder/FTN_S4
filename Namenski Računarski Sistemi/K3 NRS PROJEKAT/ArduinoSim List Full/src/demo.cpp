#include <arduinoPlatform.h>
#include <tasks.h>
#include <interrupts.h>
#include <stdio.h>
#include <serial.h>
#include <cstring>
#include <Data_Generator.h>

extern serial Serial;

void setup()
{
    /// PRIMER KORISCENJA MODULA POZVATI ********!
    Serial.begin(9600);

    Data_Generator dg;

    vector<bool> opcije(3);
    vector<long> params(3);

    opcije[0] = true;
    opcije[1] = false;
    opcije[2] = false;

    params[1] = 15;
    params[2] = 5; // kao 5 %

    for(int i = 0; i < 5; i++)
    {
        params[0] = i + 1;
        dg.generisiSlogIDodajUListu(opcije, params);
    }


    char *d = dg.readAll();
    Serial.writeln(d);
    // delete []d;

    char *r = dg.readAll();
    Serial.writeln(r);
    // delete []r;
}

void loop()
{

}
