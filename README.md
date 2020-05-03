# 2-oji_uzduotis

ANTROJI OOP UŽDUOTIS - programa, apskaičiuojanti studentų metinį vidurkį

## PROGRAMOS VEIKIMO EIGA

1. Vartotojas pasirenka, ar generuos 5 failus ar tęs paprastą programos darbą:
   *  't' arba 'n'
2. Vartotojas pasirenka, ar duomenis ves pats ar skaitys iš failo:
   *  'i' arba 'f'
3. Pasirenkama, ar bus skaičiuojama namų darbų mediana ar vidurkis :
   *  'v' arba 'm'
   
Jeigu vartotojas paririnkęs, jog duomenis ves ranka:

4. Įvedamas studentų kiekis
   * skaičius
5. Pasirenkama, ar pažymiai bus vedami ranka ar generuojami atsitiktinai: 
   *  'r' arba 'g'
6. Vedamas vardas bei pavardė
7. Įvedamas egzamino balas

8. Vyksta skaičiavimas pagal formulę:
    * Galutinis rezultatas = (vidurkis arba mediana) * 0.4 + (egzamino balas) * 0.6;
    
## Kaip paleisti programą?

1. Atsisiųsti norimą release
2. Atsisiusti ir isidiegti C++ kompiliatorių (pvz GNU)
2. Atsidaryti terminalą toje atsisiųsto failo vietoje ir įrašyti komandą "make" (nuo v0.3)
3. Rašyti ./main arba main.exe (jei Windows)

# v1.2

- Pridėti operatoriai +, =, <, >, ==
- Pridetas destruktorius
- Pridetas copy konstruktorius
- Igyvendinta RULE OF 3

# v1.1 

- Pridėti konstruktoriai
- Ištaisytos smulkios klaidos
- Pratestuotas programos veikimo laikas su skirtingais optimizavimo lygiais

## v1.1 analizė

Spartos analizė atlikta su vektoriais.

### Be optimizacijos
|Be optimizacijos  |1 000000 |10 000000  |
|------------------|----------|------------|
|Nuskaitymas  |4|40|
|Perrašymas |0.41|5.2|

### -O1
| -O1  |1 000000 |10 000000  |
|------------------|----------|------------|
|Nuskaitymas  |1.8|18|
|Perrašymas |0.2|2.7|

### -O2
| -O2  |1 000000 |10 000000  |
|------------------|----------|------------|
|Nuskaitymas  |1.9|18.5|
|Perrašymas |0.17|2.5|

### -O3
| -O3  |1 000000 |10 000000  |
|------------------|----------|------------|
|Nuskaitymas  |1.9|18.3|
|Perrašymas |0.18|2.5|

## Išvados:
Pridėjus -O1 programos nuskaitymo bei perrašymo greitis sumažėjo beveik lygiai dvigubai. Taikant -O2 bei -O3 skirtumo nuo pirmo optimizacijos lygio nebuvo.
 
# Pradinė užduoties repozitorija

# <br />[v1.0](https://github.com/Definitelynotaspruce/2-oji_uzduotis) 





