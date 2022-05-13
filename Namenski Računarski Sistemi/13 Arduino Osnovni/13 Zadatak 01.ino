/*
	Napisati program koji pri pritisku dugmeta BTN1 (pin 4) pali
	lampicu LD2 (pin 27), a pri puštanju dugmeta BTN1, gasi lampicu LD2.
	
	- Paljenje i gašenje lampice realizovati preko preko interapta povezanih na
	dugme BTN1.
	
	- Kako dugmadi nisu podrzana u interaptima, kreirati kompletan handler za
	dugme BTN1, koji podrazumeva i funkcije attachInterrupt1() i
	deattachInterrupt1() slične postojećim funkcijama.
*/
int oldState1, oldState2, blink1_id;
int PIN_SW1 = 2;
int PIN_SW2 = 7;
int PIN_LED1a = 26;

void blink_task1(int id, void * tptr)
{
  digitalWrite(PIN_LED1a, !digitalRead(PIN_LED1a)); 
}

void prekidac1(int id, void * tptr)
{
    int newState = digitalRead(PIN_SW1);
	if (oldState1 == 1  && newState == 0) {
        setTaskState(blink1_id, TASK_DISABLE);
	} else if (oldState1 == 0 && newState ==1) {
        setTaskState(blink1_id, TASK_ENABLE);
	}
	oldState1 = newState;
}

void prekidac2(int id, void * tptr)
{
    int newState = digitalRead(PIN_SW2);
	if (oldState2 == 1  && newState == 0) {
        setTaskPeriod(blink1_id, 100);
	} else if (oldState2 == 0 && newState ==1) {
        setTaskPeriod(blink1_id, 1000);
	}
	oldState2 = newState;
}

void setup()
{
    pinMode(PIN_LED1a, OUTPUT);
    oldState1 = digitalRead(PIN_SW1);
    oldState2 = digitalRead(PIN_SW2);
    if (oldState1==1)
        blink1_id = createTask(blink_task1, 100, TASK_ENABLE, NULL);
    else
        blink1_id = createTask(blink_task1, 100, TASK_DISABLE, NULL);
    createTask(prekidac1, 50, TASK_ENABLE, NULL);
    createTask(prekidac2, 50, TASK_ENABLE, NULL);
}

void loop()
{

}

