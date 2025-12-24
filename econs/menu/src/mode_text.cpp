#include "mode_text.h"
#include "bitmask.h"
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
//#include <notMain567a>
//#include <notMain678en>
//#include <notMain678de>
//#include "../../567/src/notMain567a.cpp"
#include "notMain567a.h"  // nur Header

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

    // Spezielle Kombinationen prüfen
    if (selVec == std::vector<int>{5,6,7}) {
        std::cout << "Starte 567/src/main.cpp Logik...\n";
        start567a();
    } else if (selVec == std::vector<int>{6,7,8}) {
        std::cout << "Starte econ567/src/main.cpp Logik...\n";
        start567a();
    }
}
