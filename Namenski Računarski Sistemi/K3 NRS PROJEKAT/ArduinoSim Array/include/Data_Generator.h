#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include "Data.h"
#include <array>

class Data_Generator
{
    private:
        Slog slogovi[25];
        int itBr = 0;

    public:
        Data_Generator();
        virtual ~Data_Generator();
        void generisiSlogIDodajUListu(vector<bool> &opcije, vector<long> &params);
        void ukloniSlogIzListe();
        bool available() const;
        char* read();
        char* readAll();
        void obrisiSveSlogove();
};

#endif // DATA_GENERATOR_H
