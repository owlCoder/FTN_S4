#include "Data_Generator.h"

Data_Generator::Data_Generator()  {}

Data_Generator::~Data_Generator() {}

void Data_Generator::generisiSlogIDodajUListu(vector<bool> &opcije,
        vector<long> &params)
{
    if(itBr < 25)
    {
        Data novi;
        novi.generisiSlog(opcije[0], opcije[1], opcije[2], params[0], params[1], params[2], params[3]);
        slogovi[itBr++] = (Slog) {novi.getSlogDatum(), novi.getSlogVreme(), novi.getSlogBroj()};
    }
}

bool Data_Generator::available() const
{
    return itBr >= 1 ? true : false;
}

char* Data_Generator::read()
{
    char *procitano = NULL;

    if(available())
    {
        Data d;
        itBr--;
        d.setGenerisaniSlog(slogovi[itBr].datum, slogovi[itBr].vreme, slogovi[itBr].broj);
        procitano = d.serijalizacijaSloga();

        return procitano;
    }
    else
        return (char *)"[READ ONE]: LISTA JE PRAZNA!";
}

char* Data_Generator::readAll()
{
    if(available())
    {
        string procitanoStr = "";

        while(available())
        {
            string str = string(read());
            procitanoStr += str;
            procitanoStr += "----------------------------------------------------------------------------------";
        }

        char *procitano = new char[procitanoStr.length()];
        strcpy(procitano, procitanoStr.c_str());

        return procitano;
    }
    else
        return (char *)"[READ ALL ]: LISTA JE PRAZNA!";
}

void Data_Generator::obrisiSveSlogove()
{
    itBr = 0;
}
