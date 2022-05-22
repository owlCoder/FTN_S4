#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <tasks.h>
#include <arduinoPlatform.h>
#include <serial.h>
#include <list>

using namespace std;

#define START_GENERATION 1
#define STOP_GENERATION  0

enum generation_type {SAME, RANDOM, SIN};

typedef struct dataGenStruct
{
    generation_type gt;
    int start, end;
    float error;
} dataGenStruct;

typedef struct slog
{
    char datum[15], vreme[15];
    int broj;
} Slog;

void getDateTime(char [], char []);
void generateOne(int, void *);

void startStopDataGeneration(bool, generation_type, int, int, float, long);
void generateSameNumber(int, int, float);
void generateRandomNumber(int, int, float);
void generateSinNumber(int, int, float);

bool available();
char *read();
char *readAll();
void clear();

double fmod(double, double);
double sine(double);

#endif // DATA_H_INCLUDED
