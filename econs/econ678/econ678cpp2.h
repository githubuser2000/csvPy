#ifndef MYMATHUTILS_H
#define MYMATHUTILS_H

#include <vector>
#include <array>
#include <random>
#include <cmath>
#include <iostream>

// Struktur für rationale Zahlen
struct Rational {
    int num;
    int den;

    double toDouble() const;
};

// Typ für 6-dimensionale Räume
using Space = std::array<int, 6>;

// Funktionsdeklarationen
void endtext1();
void endtext2();
void out();

#endif // MYMATHUTILS_H
