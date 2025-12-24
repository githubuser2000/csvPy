#include "mode_text.h"
#include "bitmask.h"
#include <iostream>
#include <set>
#include <sstream>
#include <string>

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
}
