#pragma once
#include <vector>

struct Rational {
    int num;
    int den;
    double toDouble() const;
};

int randInt(int a, int b);
int randomLength(int minLen = 4, int maxLen = 12);
Rational randomRational();
std::vector<Rational> randomFractionList();
