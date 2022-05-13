/*
	- Kreirati funkciju enableInterrupt1() koja omogućuje korišćenje interapta za
	dugme BTN1
	
	- Kreirati funkciju disableInterrupt1() koja onemogućuje korišćenje
	interapta za dugme BTN1
	
	- Kreirati funkciju getInterrupatEnable1() koja vraća da li je omogućen
	prekid na dugmetu BTN1
	
	- Proširiti funkconalnost handler-a da podržava i dugme BTN2
	
	- Omogućiti da pri paljenju/gašenju dugmeta BTN2 bude
	omogućeno/onemogućeno korišćenje interapta na dugmetu BTN1
*/
int oldState, oldTime, brojac;
int PIN_BTN1 = 4;

void dugme1(int id, void * tptr)
{
    int newState = digitalRead(PIN_BTN1);
	if (oldState == 1  && newState == 0) {
        if (millis()-oldTime>=2000) {
            brojac++;
            Serial.println(brojac);
		}
	} else if (oldState == 0 && newState ==1) {
        oldTime = millis();
	}
	oldState = newState;
}

void setup()
{
    Serial.begin(9600);
    oldState = digitalRead(PIN_BTN1);
    oldTime = millis();
    brojac = 0;
    createTask(dugme1, 50, TASK_ENABLE, NULL);
}

void loop()
{

}

