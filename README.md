# sisteminis-programavimas
## Versija: V0.1
Išpildyti visi reikalavimai nurodyti V0.1 versijoje (pavyzdys kaip naudotis nurodyta žemiau):
* Aplikacija priima studento duomenis iš failo arba komandinės eilutės (vartotojas pasirenka) ir apskaičiuoja studento galutinį balą pagal vidurkį arba medianą.
* Jei vartotojas parienka nuskaityti studentų duomenis iš failo - daugiau vartotojo nieko nėra klausiama, viskas apskaičiuojama iš failo "kursiokai.txt"
* Jei vartotojas pasirenka pats suvesti duomenis - vartotojo klausiama ar balai turi būti sugeneruojami automatiškai ar vartotojas nori juos pats suvesti.
* Po šio pasirinkimo vartotojo yra prašoma įvesti varda, pavarde, suvesti savarankiško darbo balus (neprašo jei pasirinkta generuoti) ir įvesti egzamino rezultata (neprašo jei pasirinkta generuoti).
* Vartotojas taip pat yra klausiamas ar galutinis rezultatas turi būti paskaičiuojamas pagal vidurkį ar pagal medianą (pasirinkus, atitinkamai išspauzdina rezultatą).
* Viską suvedus, sistema paskaišiuoja kiekvieno studento/ų galutinį balą, išrušiuoja studentus pagal vardą ir išspauzdina suformatuota lentelę su duomenimis kaip nurodyta pavyzdyje.
* Studentu sąrašui ir namų darbų balams caupti naudotas vector. Išimčių valdymas naudotas dalybai iš 0. Sukurtos atskiri antraštiniai failai studentų apdorojimui iš failo, studentų apdorojimui iš komandinės eilutės, atskiras failas tik main funkcijai. Taip pat sukurtas atskiras GeneralUtils failas kuriami kaupiami metodai kurie bus naudojami tiek studentu apdorojimui iš failo tiek apdorojimui iš komandinės eilutės (reusability).

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

Pavarde   Vardas    Galutinis (med.)
------------------------------------------
Jonas     Jonaitis  6.20
Petras    Petraitis 4.80
Zilvinas  Nezalias  7.20

## Versija: V0.2
Bus papildyta
