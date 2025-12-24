#include "mode_toggle.h"
#include "bitmask.h"
#include <iostream>
#include <set>

void mode_toggle() {
    std::set<int> selected;

    while (true) {
        system("clear");
        for (int i = 3; i <= 9; ++i)
            std::cout << "[" << (selected.count(i) ? 'x' : ' ') << "] " << i << "\n";

        std::cout << "\n3-9 toggle | q = fertig: ";
        char c;
        std::cin >> c;

        if (c == 'q') break;
        if (c >= '3' && c <= '9') {
            int v = c - '0';
            if (selected.count(v)) selected.erase(v);
            else selected.insert(v);
        }
    }

    std::cout << "\nAuswahl: ";
    for (int n : selected) std::cout << n << " ";
    std::cout << "\nBitmaske: " << toBitmask(selected) << "\n";
}
