/*  Napisati program koji koristeći task blink_task1() pali i gasi led
diodu LD1 na pinu 26 na svakih 100 milisekundi. Nakon toga:
• Napisati task prekidac1() koji se pali na svakih 50 ms i proverava stanje
prekidača SW1 na pinu 2. Ukoliko je prekidač upravo upaljen, omogućiti
korišćenje taska blink_task1, a ukoliko je upravo ugašen, onemogućiti ga
• Napisati task prekidac2() koji se pali na svakih 50 ms i proverava stanje
prekidača SW2 na pinu 7. Ukoliko je prekidač upravo upaljen, promeniti vreme
blinkanja taska blink_task1 na 1000 ms, a ukoliko je upravo ugašen na 100ms
*/