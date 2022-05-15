#ifndef SLOG_H_INCLUDED
#define SLOG_H_INCLUDED

typedef struct Slog
{
    string datum;
    string vreme;
    int broj;

    Slog() : datum{"_._._."}, vreme{"/:/"}, broj(-1) {};
    Slog(string d, string v, int b) : datum{d}, vreme{v}, broj{b} {};
} Slog;

#endif // SLOG_H_INCLUDED
