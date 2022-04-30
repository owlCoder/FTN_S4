/* Napisati task prekidac() koji proverava stanje prekidača na
određenom pinu.
• Ukoliko je prekidač upravo upaljen, startovati odredjenu funkciju bez
parametara, a ukoliko je upravo ugašen startovati drugu funkciju
• Task preko parametra prima pokazivač na strukturu koja u sebi sadrži pin
prekidača, njegovo staro stanje, kao i dva pokazivača na funkcije koje treba da
se startuju prilikom paljenja/gašenja prekidača
• Koristeći dati task, omogućiti uvećanje globalnog brojača br na uzlaznoj ivici
signala prekidača SW1 na pinu 2. Task startovati na svakih 50ms
• Koristeći dati task, omogućiti ispis globalnog brojača br na serijski monitor na
silaznoj liniji prekidača SW2 na pinu 7 . Task startovati na svakih 50ms
*/