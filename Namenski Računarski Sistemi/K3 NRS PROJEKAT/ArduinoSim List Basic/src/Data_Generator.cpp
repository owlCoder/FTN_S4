#include "Data_Generator.h"

void Data_Generator::add(vector<bool> &opcije,
        vector<long> &params)
{
    Data *novi = new Data;
    novi -> generisiSlog(opcije[0], opcije[1], opcije[2], params[0], params[1], params[2], params[3]);
    slogovi.push_back(*novi);
}

bool Data_Generator::available() const
{
    return slogovi.size() >= 1 ? true : false;
}

char* Data_Generator::read()
{
    char *procitano = NULL;

    if(available())
    {
        auto it = slogovi.begin();
        procitano = it -> serijalizacijaSloga();
        slogovi.erase(it);

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
            procitanoStr += "-----------------------------------------------------------------------------";
        }

        char *procitano = new char[procitanoStr.length()];
        strcpy(procitano, procitanoStr.c_str());

        return procitano;
    }
    else
        return (char *)"[READ ALL ]: LISTA JE PRAZNA!";
}

void Data_Generator::clear()
{
    slogovi.clear();
}
