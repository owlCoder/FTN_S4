/*
 * PROJECT:     ArduinoSimulator
 * VERSION:     1.02
 * MODULE :     Data
 * VERSION:     1.0
 * PURPOSE:     Rad sa slogom
 */

#ifndef Data_H
#define Data_H

#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <string>
#include <serial.h>
#include <cmath>
#include <list>

#define RAD M_PI/180

using namespace std;

#include "Slog.h"

extern serial Serial;
enum TIP {ISTI, NASUMICAN, SINUSOIDA};
enum VERZIJA {OBICAN, DODATNO};

class Data
{
    private:
        Slog generisaniSlog;
        static int brojacPoziva;
        char *serijalizovanSlog;
        static int sameNum;
        static bool first;

    public:
        Data();
        virtual ~Data();
        void setGenerisaniSlog(string, string, int);
        Slog getGenerisaniSlog() const;
        void generisiSlog(bool, bool, bool, long, long, long, float);
        void trenutniDatumIVreme(string []);
        friend string writeSlogToSerial(const Data &, VERZIJA);
        void azurirajBrojUSlogu(const bool, const bool, const bool, const long, const long, const float);
        int generisiBroj(TIP, long, long, float) const;
        char *serijalizacijaSloga();
        void resetujSlog();
};

#endif // Data_H
