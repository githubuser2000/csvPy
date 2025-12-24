#include "mode_text.h"
#include "bitmask.h"
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

//#include <notMain567a>
//#include <notMain678en>
//#include <notMain678de>
#include <notMain567a.h>
//#include <notMain567a.h>  // nur Header

// Hier die modularisierten Funktionen der *6* Programme einbinden

void mode_text() {
    std::set<int> allowed = {3,4,5,6,7,8,9};
    std::set<int> selected;

    std::cout << "Eingabe (z.B. 3 5 7): ";
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    int n;
    while (iss >> n)
        if (allowed.count(n)) selected.insert(n);

    std::cout << "Auswahl: ";
    for (int x : selected) std::cout << x << " ";
    std::cout << "\nBitmaske: " << toBitmask(selected) << "\n";

    std::vector<int> selVec(selected.begin(), selected.end());
    std::sort(selVec.begin(), selVec.end());




    auswahl(selVec, selected);

}


// Vorwärtsdeklaration der externen Funktion
void start567a();

// Auswahl-Funktion
void auswahl(const std::vector<int>& selVec, const std::set<int>& b) {
    // Vector → Set
    std::set<int> a(selVec.begin(), selVec.end());

    // Schnittmenge bestimmen
    std::set<int> intersection;
    std::set_intersection(
        a.begin(), a.end(),
        b.begin(), b.end(),
        std::inserter(intersection, intersection.begin())
    );

    std::cout << "Schnittmenge Größe = " << intersection.size() << "\n";

    if (intersection.size() == 3)
        std::cout << "Treffer: Schnittmenge hat genau 3 Elemente\n";

    // Spezielle Kombinationen prüfen
    if (selVec == std::vector<int>{5,6,7}) {
        std::cout << "Starte 567/src/main.cpp Logik...\n";
        start567a();
    } else if (selVec == std::vector<int>{6,7,8}) {
        std::cout << "Starte econ567/src/main.cpp Logik...\n";
        start567a();
    }
}

// Beispiel-Aufruffunktion
void aufruf() {
    std::vector<int> auswahlVec = {5,6,7};   // hier die vom User gewählte Auswahl
    std::set<int> vergleichsMenge = {5,6,7,8}; // die Menge für Schnittmenge

    auswahl(auswahlVec, vergleichsMenge);
}
