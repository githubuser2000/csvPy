#pragma once
#include "rational.h"
#include <array>
#include <vector>

using Space = std::array<double, 6>;

std::pair<double,double> convertOne(const Rational& r);
Space fractionTripletToSpace(const Rational& a,
                             const Rational& b,
                             const Rational& c);
std::vector<Space> fractionsToSpaces(const std::vector<Rational>& v);
