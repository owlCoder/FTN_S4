#ifndef AMBULANTA_H_INCLUDED
#define AMBULANTA_H_INCLUDED

#include "student.h"
#include <mutex>
#include <condition_variable>

using namespace std;

class Studentska_ambulanta {
private:
    Student &student;
    int brojSlobodnihMesta[2];
    condition_variable ambulantaSlobodna[2];
    mutex m;
public:
    Studentska_ambulanta(Student &st, int muskih, int zenskih) : student(st) {
        brojSlobodnihMesta[0] = muskih;
        brojSlobodnihMesta[1] = zenskih;
    }

    // Metoda koju poziva nit koja simulira studenta u ambulanti kada student pokusava da udje u nju.
    // Ukoliko je ambulanta zauzeta, izvrsenje ove metode ce cekati da se ona oslobodi.
    //
    // rbr - Redni broj studenta
    // p   - Pol studenta
    //
    // Potrebno je pozvati metodu student.ceka kada student ne moze da stupi u ambulantu.
    // Potrebno je pozvati metodu student.ulazi kada student udje u ambulantu.
    void udji(int rbr, Pol p) {
        unique_lock<mutex> l(m);

        /// SACEKATI DOK SE NE POJAVI PRVO SLOBODNO MESTO
        while(brojSlobodnihMesta[p] == 0)
        {
            ambulantaSlobodna[p].wait(l);
            student.ceka(rbr, p);
        }

        student.ulazi(rbr, p);
        brojSlobodnihMesta[p]--;
    }

    // Metoda koju poziva nit koja simulira studenta u ambulanti nakon sto je student pregledan i izlazi iz nje.
    //
    // rbr - Redni broj studenta
    // p   - Pol studenta
    void izadji(int rbr, Pol p) {
        unique_lock<mutex> l(m);
        brojSlobodnihMesta[p]++;
        ambulantaSlobodna[p].notify_one();
    }
};

#endif // AMBULANTA_H_INCLUDED
