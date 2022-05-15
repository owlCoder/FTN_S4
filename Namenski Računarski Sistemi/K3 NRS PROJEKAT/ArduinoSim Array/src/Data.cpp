#include "Data.h"

int Data::brojacPoziva = 0;

Data::Data() : generisaniSlog(), serijalizovanSlog(NULL) { srand(time(NULL)); }

Data::~Data() { }

void Data::setGenerisaniSlog(string d, string v, int b)
{
    generisaniSlog.datum = d;
    generisaniSlog.vreme = v;
    generisaniSlog.broj  = b;
}

Slog Data::getGenerisaniSlog() const
{
    return generisaniSlog;
}

void Data::trenutniDatumIVreme(string data[])
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       datum[20];
    char       vreme[15];

    tstruct = *localtime(&now);
    strftime(datum, sizeof(datum), "%d.%m.%Y.", &tstruct);
    strftime(vreme, sizeof(vreme), "%X",        &tstruct);

    data[0] = datum;
    data[1] = vreme;

    return;
}

void Data::generisiSlog(bool istiBroj = true,
                        bool nasumicanBroj = false,
                        bool sinusoida = false,
                        long pocetakIntervala = 0,
                        long krajIntervala = 1,
                        long duzinaAmplitude = 1,
                        float procenatGreske = 0.0)
{
    string datumVreme[2];
    trenutniDatumIVreme(datumVreme);

    generisaniSlog.datum = datumVreme[0];
    generisaniSlog.vreme = datumVreme[1];
    azurirajBrojUSlogu(istiBroj, nasumicanBroj, sinusoida, pocetakIntervala, krajIntervala, procenatGreske);
}

ostream &operator<<(ostream &out, const Data &d)
{
    out << "SLOG: " << d.generisaniSlog.datum << " "
        << d.generisaniSlog.vreme << " "
        << d.generisaniSlog.broj << endl;

    return out;
}

string writeSlogToSerial(const Data &d, VERZIJA ver = DODATNO)
{
    if(ver == DODATNO)
        return "SLOG: " + d.getGenerisaniSlog().datum + " "
            + d.getGenerisaniSlog().vreme + " "
            + to_string(d.getGenerisaniSlog().broj) + "\n";
    else
        return d.getGenerisaniSlog().datum + " "
            + d.getGenerisaniSlog().vreme + " "
            + to_string(d.getGenerisaniSlog().broj) + "\n";
}

void Data::resetujSlog()
{
    generisaniSlog.datum = "/././.";
    generisaniSlog.vreme = "/:/;";
    generisaniSlog.broj  = 0;
}

void Data::azurirajDatumUSlogu(const string datum)
{
    this -> generisaniSlog.datum = datum;
}

void Data::azurirajDatumUSlogu()
{
    string data[2];
    trenutniDatumIVreme(data);

    this -> generisaniSlog.datum = data[0];
}

void Data::azurirajVremeUSlogu(const string vreme)
{
    this -> generisaniSlog.vreme = vreme;
}

void Data::azurirajVremeUSlogu()
{
    string data[1];
    trenutniDatumIVreme(data);

    this -> generisaniSlog.vreme = data[1];
}

void Data::azurirajBrojUSlogu(const int broj = 1)
{
    this -> generisaniSlog.broj = broj;
}

void Data::azurirajBrojUSlogu(const bool istiBroj = true,
                              const bool nasumicanBroj = false,
                              const bool sinusoida = false,
                              const long pocetakIntervala = 0,
                              const long krajIntervala = 1,
                              const float procenatGreske = 0.0)
{
    if(istiBroj)
        generisaniSlog.broj  = generisiBroj(ISTI,      pocetakIntervala, krajIntervala, procenatGreske);
    else if(nasumicanBroj)
        generisaniSlog.broj  = generisiBroj(NASUMICAN, pocetakIntervala, krajIntervala, procenatGreske);
    else if(sinusoida)
        generisaniSlog.broj  = generisiBroj(SINUSOIDA, pocetakIntervala, krajIntervala, procenatGreske);
    else
        generisaniSlog.broj  = -1;
}

int Data::generisiBroj(TIP tip, long p, long k, float procenatGreske = 0.0) const
{
    uniform_int_distribution<int> distribution(p, k);
    static random_device device;
    default_random_engine generator;
    static mt19937 rng(device());
    int genBroj = 0;

    if(tip == ISTI)
        genBroj = distribution(generator);
    else if(tip == NASUMICAN)
    {
        genBroj = distribution(rng);
    }
    else if(tip == SINUSOIDA)
        genBroj = 3276 * sin(1.8 * (++brojacPoziva) * RAD) - rand() % 5 - 1;

    if(procenatGreske > 0)
        genBroj = rand() % (int) procenatGreske + 1;

    if(genBroj < p)
        genBroj = p + rand() % k;

    if(genBroj > k)
        genBroj = p + rand() % (k / 2);

    return genBroj;
}

string Data::getSlogDatum() const
{
    return generisaniSlog.datum;
}

string Data::getSlogVreme() const
{
    return generisaniSlog.vreme;
}

int Data::getSlogBroj() const
{
    return generisaniSlog.broj;
}

char *Data::serijalizacijaSloga()
{
    string slog = writeSlogToSerial(*this, OBICAN);
    serijalizovanSlog = new char[sizeof(Slog) + sizeof(char)];

    for(unsigned i = 0; i < slog.length(); i++)
        serijalizovanSlog[i] = slog[i];

    serijalizovanSlog[slog.length()] = 0;

    return serijalizovanSlog;
}
