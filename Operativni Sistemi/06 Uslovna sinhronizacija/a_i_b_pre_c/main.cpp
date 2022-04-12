// Napraviti konkurentni program sa tri niti.
// Nit a ispisuje: Ja sam nit a.
// Nit b ispisuje: Ja sam nit b.
// Nit c ispisuje: Ja sam nit c.
//
// Obezbediti da se niti a i b, uvek izvrse pre niti c.
//
// Implementirati oznacene metode u klasi Koordinator u fajlu koordinator.h

#include <iostream>
#include <thread>
#include <mutex>

#include "koordinator.h"

using namespace std;

mutex term_mx;                          //Globalni mutex terminala da bi se sprecila stetna preplitanja na terminalu.

void a(Koordinator& k) {                //Nit a. Prosledjuje se referenca na Koordinator, kako bi sve niti radile na istom k.
    {
        unique_lock<mutex> lock(term_mx);
        cout << "Ja sam nit a." << endl;
    }
    k.zavrsio();
}

void b(Koordinator& k) {                //Nit b. Prosledjuje se referenca na Koordinator, kako bi sve niti radile na istom k.
    {
        unique_lock<mutex> lock(term_mx);
        cout << "Ja sam nit b." << endl;
    }
    k.zavrsio();
}

void c(Koordinator& k) {                //Nit c. Prosledjuje se referenca na Koordinator, kako bi sve niti radile na istom k.
    k.cekam();
    unique_lock<mutex> lock(term_mx);
    cout << "Ja sam nit c." << endl;
}

int main() {
    Koordinator k(2);                   //Kreiranje objekta Koordinatora koji se prosledjuje nitima po referenci.
    thread ta(a, ref(k));
    thread tb(b, ref(k));
    thread tc(c, ref(k));
    ta.join();
    tb.join();
    tc.join();
}
