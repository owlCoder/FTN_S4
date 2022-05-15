#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include "Data.h"
#include <vector>

class Data_Generator
{
    private:
        vector<Data> slogovi;

    public:
        Data_Generator() {}
        void add(vector<bool> &opcije, vector<long> &params);
        void remove();
        bool available() const;
        char* read();
        char* readAll();
        void clear();
};

#endif // DATA_GENERATOR_H
