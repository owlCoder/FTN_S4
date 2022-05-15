#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include "Data.h"
#include <vector>

class Data_Generator
{
    private:
        vector<Data> slogovi;

    public:
        Data_Generator();
        virtual ~Data_Generator();
        void generisiSlogIDodajUListu(vector<bool> &opcije, vector<long> &params);
        void ukloniSlogIzListe();
        bool available() const;
        char* read();
        char* readAll();
        void obrisiSveSlogove();
        void obrisiNSlogova(const int);
        void obrisiKtiSlogIzListe(const int);
        char* procitajKtiSlogIzListe(const int);

};

#endif // DATA_GENERATOR_H
