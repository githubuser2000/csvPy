// encoding_switch.h

#ifdef ASCII_ONLY
    #define BOX_LINE "=============================================="
    #define ICON_INT "[INT]"
    #define ICON_REL "[RAT]"
#else
    #define BOX_LINE u8"¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿"
    #define ICON_INT u8"¿"
    #define ICON_REL u8"¿"
#endif

#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cmath>
#include <iostream>

struct Rational {
    int num;
    int den;

    double toDouble() const {
        return static_cast<double>(num) / static_cast<double>(den);
    }
};

using Space = std::array<int,6>;

// Zufalls-Engine
std::mt19937 rng(std::random_device{}());

int randInt(int a, int b) {
    std::uniform_int_distribution<int> dist(a,b);
    return dist(rng);
}

// zufällige Länge, 3¿20
int randomLength() {
    return randInt(3,20);
}

// zufälliges Rational oder Int
Rational randomRational() {
    int choose = randInt(0,1);
    if (choose == 0) {
        // Fraction
        int n = randInt(1,9);
        int d = randInt(1,9);
        return {n,d};
    } else {
        // Int
        int x = randInt(1,20);
        return {x,1};
    }
}

// zufällige Liste
std::vector<Rational> randomFractionList() {
    int len = randomLength();
    std::vector<Rational> v;
    v.reserve(len);
    for (int i=0; i<len; i++)
        v.push_back(randomRational());
    return v;
}

std::pair<int,int> convertOne(const Rational& r) {
    int val = static_cast<int>(std::floor(r.toDouble() * 10.0));
    int minv = val;
    int maxv = std::max(val * 2, val);
    return {minv,maxv};
}

Space fractionTripletToSpace(const Rational& a,
                             const Rational& b,
                             const Rational& c)
{
    auto [a1,a2] = convertOne(a);
    auto [b1,b2] = convertOne(b);
    auto [c1,c2] = convertOne(c);
    return {a1,a2, b1,b2, c1,c2};
}

std::vector<Space> fractionsToSpaces(const std::vector<Rational>& v) {
    std::vector<Space> out;
    for (size_t i=0; i+2 < v.size(); i+=3) {
        out.push_back(fractionTripletToSpace(v[i], v[i+1], v[i+2]));
    }
    return out;
}
void endtext1()
{
    int n = 3;

    std::cout << "\n";
    std::cout << "══════════════════════════════════════════════\n";
    std::cout << "🔢  GANZZAHL – Zustand im dimensionalen Raum\n";
    std::cout << "══════════════════════════════════════════════\n";
    std::cout << "📌 Wert: n = " << n << "\n\n";

    std::cout << "🧠 Bedeutung:\n";
    std::cout << "   ① 💰 Marktwirtschaft\n";
    std::cout << "      → absoluter Trieb- oder Wertzustand\n\n";

    std::cout << "   ② 💱 Währung\n";
    std::cout << "      → isolierte Währung\n";
    std::cout << "      → kein Umtauschverhältnis\n\n";

    std::cout << "   ③ 🏗️ Kommunismus-Zustände\n";
    std::cout << "      • Armut\n";
    std::cout << "      • Reparatur-Zustand\n";
    std::cout << "      • Gesundheits-/Krankheits-Zustand\n";
    std::cout << "      • Schwäche / Zentralität / Impulsivität\n\n";

    std::cout << "   ④ 📐 Geometrie\n";
    std::cout << "      → Volumen- oder Flächeneinheit\n\n";

    std::cout << "   ⑤ 🧭 Hierarchie\n";
    std::cout << "      → Rangordnung (oben / unten)\n";
    std::cout << "══════════════════════════════════════════════\n";
}
void endtext2()
{
    int a = 2;
    int b = 5;
    double r = static_cast<double>(a) / b;

    std::cout << "\n";
    std::cout << "══════════════════════════════════════════════\n";
    std::cout << "🔁  RATIONALE ZAHL – Relation im Raum\n";
    std::cout << "══════════════════════════════════════════════\n";
    std::cout << "📌 Wert: r = " << a << "/" << b << " = " << r << "\n\n";

    std::cout << "🧠 Bedeutung:\n";
    std::cout << "   ① 💱 Währungen\n";
    std::cout << "      → Wechselkurs / Verhältnis\n\n";

    std::cout << "   ② 🧭 Geometrie (2D)\n";
    std::cout << "      → Richtungswinkel\n";
    std::cout << "      → Steigung in einer Matrix\n\n";

    std::cout << "   ③ 🤝 Diplomatie\n";
    std::cout << "      → Macht-, Einfluss- oder Abhängigkeitsverhältnis\n\n";

    std::cout << "   ④ 🧑‍🤝‍🧑 Soziales System\n";
    std::cout << "      → Wer mit wem\n";
    std::cout << "      → Beziehungsstruktur\n";
    std::cout << "══════════════════════════════════════════════\n";
}
void out() {
  auto xs = randomFractionList();

    std::cout << "Liste:\n";
    for (auto& r : xs)
        std::cout << r.num << "/" << r.den << " ";
    std::cout << "\n\nSpaces:\n";

    auto spaces = fractionsToSpaces(xs);
    for (auto& s : spaces)
        std::cout << "("
                  << s[0] << "," << s[1] << "; "
                  << s[2] << "," << s[3] << "; "
                  << s[4] << "," << s[5] << ")\n";
   
}

int main() {
     out();
     endtext1();
     endtext2();
     out();
}



//:set encoding=utf-8
//:set fileencoding=utf-8
