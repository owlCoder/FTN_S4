#include "Data.h"

int Data::brojacPoziva = 0;
int Data::sameNum = -1;
bool Data::first = true;

Data::Data() : generisaniSlog(), serijalizovanSlog(NULL) { srand(time(NULL)); }

Data::~Data() { delete [] serijalizovanSlog; }

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
                        long  duzinaAmplitude = 1,
                        float procenatGreske = 0.0)
{
    string datumVreme[2];
    trenutniDatumIVreme(datumVreme);

    generisaniSlog.datum = datumVreme[0];
    generisaniSlog.vreme = datumVreme[1];
    azurirajBrojUSlogu(istiBroj, nasumicanBroj, sinusoida, pocetakIntervala, krajIntervala, procenatGreske);
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
            + to_string(d.getGenerisaniSlog().broj);
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
    static mt19937 rng(device());
    int genBroj = 0;

    if(tip == ISTI && first == false)
        genBroj = sameNum;
    else if(tip == ISTI && first == true)
    {
        genBroj = sameNum = rand() % k + 1;
        first = false;
    }
    else if(tip == NASUMICAN)
        genBroj = distribution(rng);
    else if(tip == SINUSOIDA)
        genBroj = 3276 * sin(1.8 * (++brojacPoziva) * RAD) - rand() % 5 - 1;

    if(procenatGreske > 0)
        genBroj += rand() % (int) (procenatGreske / 2) + 1;

    if(genBroj < p)
        genBroj = rand() % k + 1;
    else if(genBroj > k)
        genBroj = rand() % (k / 2) + 1;

    return genBroj;
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

void Data::resetujSlog()
{
    generisaniSlog.datum = "/././.";
    generisaniSlog.vreme = "/:/;";
    generisaniSlog.broj  = 0;
}
