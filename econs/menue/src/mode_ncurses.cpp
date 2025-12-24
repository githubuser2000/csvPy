#include "mode_ncurses.h"
#include "bitmask.h"

#ifdef USE_NCURSES
#include <ncurses.h>
#include <set>
#include <iostream>

void mode_ncurses() {
    initscr();
    noecho();
    keypad(stdscr, true);
    curs_set(0);

    std::set<int> selected;
    int cursor = 0;

    while (true) {
        clear();
        for (int i = 0; i < 7; ++i) {
            int v = i + 3;
            if (i == cursor) attron(A_REVERSE);
            printw("[%c] %d\n", selected.count(v) ? 'x' : ' ', v);
            if (i == cursor) attroff(A_REVERSE);
        }
        refresh();

        int ch = getch();
        if (ch == KEY_UP && cursor > 0) cursor--;
        else if (ch == KEY_DOWN && cursor < 6) cursor++;
        else if (ch == ' ') {
            int v = cursor + 3;
            if (selected.count(v))
                selected.erase(v);
            else
                selected.insert(v);
            }
        else if (ch == 10) break;
        else if (ch == 27) { selected.clear(); break; }
    }

    endwin();

    std::cout << "Auswahl: ";
    for (int n : selected) std::cout << n << " ";
    std::cout << "\nBitmaske: " << toBitmask(selected) << "\n";
}
#endif
