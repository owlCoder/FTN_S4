int br = 0;
int staroStanje = 0;
int startTime = millis();
int proteklo = 0;
int pritisakId;

void pritisakDugmeta(int id, void *tptr)
{
    int novoStanje = digitalRead(4);
    if(staroStanje == 1 && novoStanje == 0)
    {
        if(millis() - proteklo > 2000)
        {
            br += analogRead(A0);
            Serial.println(br);
        }
    }
    else if(staroStanje == 0 && novoStanje == 1)
    {
        proteklo = millis();
    }

    staroStanje = novoStanje;
}

void interapOn()
{
    int broj = analogRead(A0);
    broj = map(broj, 0, 1023, 0, 255);

    for(int i = 26; i <= 33; i++)
    {
        ///         II NACIN  /////// ///
        /// if(broj % 2 != 0)
        ///    digitalWrite(i, HIGH);
        /// else
        ///    digitalWrite(i, LOW);
        /// ///////////////////////// ///
        digitalWrite(i, broj % 2 != 0);
        broj /= 2;
    }
}

void serijskiMonitor(int id, void *tptr)
{
    if(Serial.available())
    {
        auto unos = Serial.readString().c_str();
        int broj = atoi(unos);

        if(broj < br)
        {
            setTaskState(pritisakId, TASK_DISABLE);
            Serial.println((char *)"Pritisak onemogucen!");
        }
    }
}

void setup()
{
    for(int i = 26; i <= 33; i++)
        pinMode(i, OUTPUT);

    Serial.begin(9600);

    pritisakId = createTask(pritisakDugmeta, 50, TASK_ENABLE, NULL);
    attachInterrupt(1, interapOn, RISING);
    createTask(serijskiMonitor, 50, TASK_ENABLE, NULL);
}

void loop()
{

}
