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

 **1 strategija:** Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Rezultatai nelabai pasikeitė naudojant vienodus konteinerius (pasikeitė bet nereikšmingai - 2 sekundėmis greičiau):  
**Deque Studentų rūšiavimas į dvi grupes/kategorijas:**  
1000 - 4 ms  
10 000 - 38 ms  
100 000 - 422 ms (0.4 s)  
1000 000 - 4325 ms (4.3 s)  
10 000 000 - 42557 ms (42 s)  
 
**List Studentų rūšiavimas į dvi grupes/kategorijas:**    
1000 - 3 ms  
10 000 - 48 ms  
100 000 - 398 ms  
1000 000 - 4425 ms (4.4 s)  
10 000 000 - 41576 ms (41 s)

**Vector Studentų rūšiavimas į dvi grupes/kategorijas:**  
1000 - 8 ms  
10 000 - 101 ms  
100 000 - 1054 ms (1 s)  
1000 000 - 9645 ms (9.6 s)  
10 000 000 - 97564 ms (98 s)  
 
**2 strategija:** Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai.  
Rezultatai: 
Naudotas algoritmas trynimui iš studentų konteinerio ir kopijavimui į lopukų konteinerį:  
list<Student> lopukai;

    auto i = std::begin(students);
    while (i != std::end(students)) {
        if (i->getFinalGrade() < 5) {
            lopukai.push_back(i->getStudent());
            i = students.erase(i);
        }
        else {
            ++i; }

    }

Algoritmas greičiausiai dirbo su list konteineriais - 5 kartu greičiau už deque ir 10 kartų greičiau už vector. Konteineriai pagal greituma:  
1. list  
2. deque  
3. vector  

Trinant:
deque:
studentų rūšiąvimas į dvi grupes/kategorijas:
1000 - 20 ms
10 000 - 402 ms
100 000 - 17423 ms (17 s)
1000 000 - 38486 ms (38 s)

list:
studentų rūšiąvimas į dvi grupes/kategorijas:
1000 - 4 ms
10 000 - 58 ms
100 000 - 566 ms (0.5 s)
1000 000 - 5780 ms 5.7 s)

vector:
studentų rūšiąvimas į dvi grupes/kategorijas:
1000 - 101 ms
10 000 - 10015 ms
100 000 - 145462 ms (145 s)
1000 000 - 2687462 ms (268 s)
