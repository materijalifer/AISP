Spremiti sve ove datoteke u isti folder!

Ve�ina primjera koristi "asp_massh.h" header. On slu�i za neke formatirane ispise da ne gubim vrijeme tijekom masovnih
na tipkanje ogrmonih printfova.

Za kompajliranje garantiram da radi s mingwom na ovaj na�in:

g++ -Wall <ime programa>

Neki �e izbaciti neka upozorenja, ali to je uredu.

hash_input_generator.c ispisuje N random primjera koji se mogu koristiti za primjer 09. Koristiti ovako:

g++ -Wall hash_input_generator.c
a 100 > test.txt

Na taj na�in �e se stvoriti datoteka test.txt koja ima 100 zapisa u sebi.

Have fun!