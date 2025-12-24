// -*- coding: utf-8 -*-
#include "text.hpp"
#include <iostream>

void out() {
    auto n = randomLength();
    auto v = randomTriplet(n);

    for (std::size_t i = 0; i + 2 < v.size(); i += 3) {
        auto s = fractionTripletToSpace(v[i], v[i+1], v[i+2]);
        std::cout
            << "⇒ (" << s[0] << "," << s[1] << "," << s[2]
            << ") → (" << s[3] << "," << s[4] << "," << s[5]
            << ")\n";
    }
}

// --- UTF-8 text blocks preserved from your program ---

void endtext1() {
    std::cout <<
"══════════════════════════════════════════════\n"
"🔢  GANZE ZAHL – Einheit im Raum\n"
"══════════════════════════════════════════════\n"
"① 🧱 Struktur  → Baustein / Element\n"
"② 🧮 Algebra   → Zähl- oder Ordnungsobjekt\n"
"③ 🏗️ Architektur → Raster / Modul / Achse\n"
"④ 📐 Geometrie → Volumen- oder Flächeneinheit\n"
"⑤ 🧭 Hierarchie → Rangordnung (oben / unten)\n"
"══════════════════════════════════════════════\n";
}

void endtext2() {
    int a = 2, b = 5;
    double r = static_cast<double>(a) / b;

    std::cout <<
"\n══════════════════════════════════════════════\n"
"🔁  RATIONALE ZAHL – Relation im Raum\n"
"══════════════════════════════════════════════\n"
"📌 Wert: r = " << a << "/" << b << " = " << r << "\n\n"
"🧠 Bedeutung:\n"
"① 💱 Währungen  → Wechselkurs / Verhältnis\n"
"② 🧭 Geometrie → Richtungswinkel / Steigung\n"
"③ 🤝 Diplomatie → Macht- oder Abhängigkeitsverhältnis\n";
}
