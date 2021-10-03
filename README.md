# sisteminis-programavimas
## Versija: V0.1
Išpildyti visi reikalavimai nurodyti V0.1 versijoje (pavyzdys kaip naudotis nurodyta žemiau):
* Aplikacija priima studento duomenis iš failo arba komandinės eilutės (vartotojas pasirenka) ir apskaičiuoja studento galutinį balą pagal vidurkį arba medianą.
* Jei vartotojas parienka nuskaityti studentų duomenis iš failo - daugiau vartotojo nieko nėra klausiama, viskas apskaičiuojama iš failo "kursiokai.txt"
* Jei vartotojas pasirenka pats suvesti duomenis - vartotojo klausiama ar balai turi būti sugeneruojami automatiškai ar vartotojas nori juos pats suvesti.
* Po šio pasirinkimo vartotojo yra prašoma įvesti varda, pavarde, suvesti savarankiško darbo balus (neprašo jei pasirinkta generuoti) ir įvesti egzamino rezultata (neprašo jei pasirinkta generuoti).
* Vartotojas taip pat yra klausiamas ar galutinis rezultatas turi būti paskaičiuojamas pagal vidurkį ar pagal medianą (pasirinkus, atitinkamai išspauzdina rezultatą).
* Viską suvedus, sistema paskaišiuoja kiekvieno studento/ų galutinį balą, išrušiuoja studentus pagal vardą ir išspauzdina suformatuota lentelę su duomenimis kaip nurodyta pavyzdyje.
* Studentu sąrašui ir namų darbų balams caupti naudotas vector. Išimčių valdymas naudotas dalybai iš 0. Sukurtos atskiri antraštiniai failai studentų apdorojimui iš failo (StudentFileProcessor), studentų apdorojimui iš komandinės eilutės (StudentConsoleInputProcessor), atskiras failas tik main funkcijai (Balu tvarkykle) ir atskirta Student klasė. Taip pat sukurtas atskira failas (GeneralUtils) kuriami kaupiami metodai kurie bus naudojami tiek studentu apdorojimui iš failo tiek apdorojimui iš komandinės eilutės (reusability).

### Pavyzdys
 Apdoroti studentus is failo? y - TAIP, n -NE:n  
 Ar balai turi buti sugeneruoti? y - taip, n - ne:n  
 Skaiciuoti vidurki = 0, skaiciuoti mediana = 1:1  
 Iveskite studentu skaiciu, kuriuos noresite suvesti:3  
 Iveskite varda:Jonas  
 Iveskite pavarde:Jonaitis  
 Iveskite namu darbu balus (pvz: 10 8 5):8 9 4  
 Iveskite egzamino rezultata:5  
 Iveskite varda:Petras    
 Iveskite pavarde:Petraitis  
 Iveskite namu darbu balus (pvz: 10 8 5):7 9 6 3  
 Iveskite egzamino rezultata:4  
 Iveskite varda:Zilvinas Nezalias  
 Iveskite pavarde: Iveskite namu darbu balus (pvz: 10 8 5):7 5 6 9  
 Iveskite egzamino rezultata:8  
 
 *Pavyzdyje github keičia formatavimą*
 
Pavarde   Vardas    Galutinis (med.)  
\----------------------------------  
Jonas     Jonaitis  6.20  
Petras    Petraitis 4.80  
Zilvinas  Nezalias  7.20  

## Versija: V0.2

### Pridėtas studentų failo generavimas, studentų skirstymas pagal vidurkį ir studentų išvedimas į atskirus failus pagal vidurkį. Taip pat pridėtos funkcijų trukmės matuoklės.     Naudota:     
 auto start = high_resolution_clock::now();  
 // vykdoma logika  
 auto stop = high_resolution_clock::now();  
 auto duration = duration_cast<milliseconds>(stop - start);  
 Išspauzdinamas apskaičiuotas laikas milisekundėmis.  
 
### Išmatuotas nurodytų funkcijų laikai su skirtingais studentų kiekiais faile. Rezultatai:  
**Failų kūrimas:**  
1000 - 25 ms  
10 000 - 248 ms  
100 000 - 2450 ms (2.4s)  
1000 000 - 24511 ms (24s)  
10 000 000 - 239026 ms (239s)  
**Duomenų nuskaitymas iš failų:**  
1000 - 34 ms  
10 000 - 343 ms  
100 000 - 3519 ms (3.5s)  
1000 000 - 33604 ms (33.6s)  
10 000 000 - 385461 ms (385s)  
**Studentų rūšiavimas į dvi grupes/kategorijas:**  
1000 - 7 ms  
10 000 - 98 ms  
100 000 - 1098 ms (1s)  
1000 000 - 9468 ms (9.4s)  
10 000 000 - 98456 ms (98s)  
**Surūšiuotų studentų išvedimas į du naujus failus:**  
1000 - 19 ms  
10 000 - 191 ms  
100 000 - 1934 ms (1.9s)  
1000 000 - 18679 ms (18.6s)  
10 000 000 - 195490 ms (195s)  

### Skirtingų konteinerių testavimo rezultatai:  
**vector:**  
**Duomenų nuskaitymas iš failų:**  
1000 - 34 ms  
10 000 - 343 ms  
100 000 - 3519 ms (3.5s)  
1000 000 - 33604 ms (33.6s)  
10 000 000 - 385461 ms (385s)  
**Studentų rūšiavimas į dvi grupes/kategorijas:**  
1000 - 7 ms  
10 000 - 98 ms  
100 000 - 1098 ms (1s)  
1000 000 - 9468 ms (9.4s)  
10 000 000 - 98456 ms (98s)  

**list:**    
**Duomenų nuskaitymas iš failų:**  
1000 - 31 ms  
10 000 - 292 ms  
100 000 - 2901 ms (2.9s)  
1000 000 - 29421 ms (29.6s)  
10 000 000 - 275397 ms (275s)  
**Studentų rūšiavimas į dvi grupes/kategorijas:**    
1000 - 3 ms  
10 000 - 44 ms  
100 000 - 445 ms  
1000 000 - 4768 ms (4.7s)  
10 000 000 - 45687 ms (45s)  

**deque:**  
**Duomenų nuskaitymas iš failų:**    
1000 - 28 ms  
10 000 - 285 ms  
100 000 - 2850 ms (2.8s)  
1000 000 - 29409 ms (29.4s)  
10 000 000 - 286984 ms (286s)  
**Studentų rūšiavimas į dvi grupes/kategorijas:**  
1000 - 3 ms  
10 000 - 43 ms  
100 000 - 443 ms (0.4s)  
1000 000 - 4572 ms (4.5s)  
10 000 000 - 44548 ms (44s)  

Pastebėta, kad naudojant list arba deque, uskaitymas iš failų ir studentų rūšiavimas vyksta šiek tiek greičiau nei naudojant vector.  
Greičio skirtumo tarp list ir deque nepastebėta arba jis labai nežymus.
 
## Versija: V1.0  
Bus papildyta
