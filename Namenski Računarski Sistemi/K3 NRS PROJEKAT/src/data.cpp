#include "data.h"

list<Slog *> slogovi;
int genOneId = -1;
int sameNum  = -1;
int cnt      =  1;
int err      =  0;

void getDateTime(char *datum, char *vreme)
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       d[20];
    char       v[15];

    tstruct = *localtime(&now);
    strftime(d, sizeof(d), "%d.%m.%Y.", &tstruct);
    strftime(v, sizeof(v), "%X",        &tstruct);

    strcpy(datum, d);
    strcpy(vreme, v);

}
void startStopDataGeneration(bool gen, generation_type gt, int start, int end, float error, long taskDiffer_t)
{
    srand(time(NULL));
    dataGenStruct dg;
    dg.gt = gt;
    dg.start = start, dg.end = end;
    dg.error = error;

    if(gen == START_GENERATION)
    {
        if(genOneId == -1)
            genOneId = createTask(generateOne, taskDiffer_t, TASK_ENABLE, &dg);
        else
            setTaskState(genOneId, TASK_ENABLE);
    }
    else
    {
        setTaskState(genOneId, TASK_DISABLE);
    }
}

void generateOne(int id, void *tptr)
{
    dataGenStruct *dg = (dataGenStruct *) tptr;

    if(dg -> gt == SAME)
        generateSameNumber(dg -> start, dg -> end, dg -> error);
    else if(dg -> gt == RANDOM)
        generateRandomNumber(dg -> start, dg -> end, dg -> error);
    else if(dg -> gt == SIN)
        generateSinNumber(dg -> start, dg -> end, dg -> error);
}

void generateSameNumber(int start, int end, float error)
{
    if(sameNum == -1)
    {
        srand(time(NULL));

        err = (error > 0.5) ? rand() % (end / 5) : rand() % 2;
        Slog *novi = new Slog;

        getDateTime(novi -> datum, novi -> vreme);
        novi -> broj = rand() % end;

        if(error >= 0.5)
        {
            sameNum = novi -> broj;
            novi -> broj += err;
        }
        else if(error < 0.5 && (rand() % 2))
        {
            sameNum = novi -> broj;
            novi -> broj -= err;
        }
        else
        {
            sameNum = novi -> broj;
        }

        if(novi -> broj < start || novi -> broj > end)
            novi -> broj = start + end / 2;

        slogovi.push_back(novi);
    }
    else
    {
        Slog *novi = new Slog;

        getDateTime(novi -> datum, novi -> vreme);
        novi -> broj = sameNum;

        slogovi.push_back(novi);
    }
}

void generateRandomNumber(int start, int end, float error)
{
    Slog *novi = new Slog;

    getDateTime(novi -> datum, novi -> vreme);
    novi -> broj = rand() % end;

    err = (error > 0.5) ? rand() % (end / 5) : rand() % 2;

    if(error >= 0.5)
        novi -> broj += err;
    else if(error < 0.5 && (rand() % 2))
        novi -> broj -= err;

    if(novi -> broj < start || novi -> broj > end)
        novi -> broj = start + end / 2;

    slogovi.push_back(novi);
}

void generateSinNumber(int start, int end, float error)
{
    Slog *novi = new Slog;

    getDateTime(novi -> datum, novi -> vreme);
    novi -> broj = sine(cnt);
    cnt++;

    if(cnt > end || cnt < start)
        cnt = start;

    err = (error > 0.5) ? rand() % (end / 5) : rand() % 2;

    if(error >= 0.5)
        novi -> broj += err;
    else if(error < 0.5 && (rand() % 2))
        novi -> broj -= err;

    if( (novi -> broj < start && novi -> broj < -start)
            || (novi -> broj > end && novi -> broj < -end))
        novi -> broj = -sine(start + end / 2 - cnt);

    slogovi.push_back(novi);
}

bool available()
{
    auto it = slogovi.cbegin();
    int  i = 0;

    while(it != slogovi.cend())
    {
        it++;
        i++;
    }

    return (i >= 1 ? true : false);
}

char *read()
{
    if(available())
    {
        auto it = slogovi.begin();
        string gen = "";
        gen +=       string((*it) -> datum);
        gen +=       + " ";
        gen +=       string((*it) -> vreme);
        gen +=        " ";
        gen +=       to_string((*it) -> broj);

        char *str = new char[gen.length()];
        strcpy(str, gen.c_str());

        slogovi.remove(*it);
        delete *it;

        return str;
    }
    else
        return NULL;
}

char *readAll()
{
    if(available())
    {
        string tmp = "";
        while(available())
        {
            char *r = read();
            tmp += string(r);
            tmp += " ";
            delete[] r;
        }

        char *str = new char[tmp.length()];
        strcpy(str, tmp.c_str());

        return str;
    }
    else
        return NULL;

}

void clear()
{
    auto it = slogovi.begin();

    while(it != slogovi.cend())
    {
        slogovi.remove(*it);
        delete *it;
        it++;
    }
}

/// Funkcije sinusoide
double fmod(double a, double b)
{
    double frac = a / b;
    int floor = frac > 0 ? (int)frac : (int)(frac - 0.9999999999999999);
    return (a - b * floor);
}

double sine(double n)
{
    double result = n;
    n = fmod(n, 2 * M_PI);

    if (n < 0)
        n = 2 * M_PI - n;

    char sign = 1;
    if (n > M_PI)
    {
        n -= M_PI;
        sign = -1;
    }

    return sign * result;
}
