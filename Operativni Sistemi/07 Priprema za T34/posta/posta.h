#ifndef POSTA_H_INCLUDED
#define POSTA_H_INCLUDED

#include "povratna.h"
#include "klijent.h"
#include <mutex>
#include <condition_variable>

using namespace std;
using namespace chrono;

class Posta {
private:
    Klijent &klijent;
    int uplaceno[2];
    bool salterZauzet[2];
    condition_variable red;
    mutex m;

public:
    Posta(Klijent &kl) : klijent(kl) {
        uplaceno[0] = 0;
        uplaceno[1] = 0;
        salterZauzet[0] = false;
        salterZauzet[1] = false;
    }

    // Metoda koju poziva nit koja simulira klijenta kada on uplacuje neki iznos.
    // Metoda je blokirajuca - ako je salter zauzet, metoda ce stajati blokirana dok se on ne oslobodi.
    //
    // rbr   - Redni broj klijenta
    // svota - Svota koju klijent zeli da uplati
    //
    // Potrebno je pozvati metodu klijent.ceka kada su salteri zauzeti i klijent mora da ceka.
    // Potrebno je pozvati metodu klijent.uplacuje kada klijent stupi na salter i vrsi svoje placanje.
    // Potrebno je pozvati metodu klijent.napusta kada klijent zavrsi placanje i napusta salter.
    void uplati(int rbr, int svota) {
        unique_lock<mutex> l(m);

        while(salterZauzet[0] && salterZauzet[1]) /// AKO SU OBA SALTERA ZAUZETA
        {
            klijent.ceka(rbr, svota);
            red.wait(l);
        }

        int salter = salterZauzet[0] ? 1 : 0; /// iz bool u int
        salterZauzet[salter] = true;

        klijent.uplacuje(rbr, salter, svota);

        l.unlock();
        this_thread::sleep_for(seconds(svota));
        l.lock();

        uplaceno[salter] += svota;
        salterZauzet[salter] = false;
        klijent.napusta(rbr, salter, uplaceno[salter]);
        red.notify_one();
    }
};

#endif // POSTA_H_INCLUDED
