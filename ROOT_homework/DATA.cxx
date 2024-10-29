#include "DATA.h"
#include <cmath>

ClassImp(DATA);

DATA::DATA() : px(0), py(0), pz(0) {}  // Default zero

DATA::DATA(Double_t x, Double_t y, Double_t z) : px(x), py(y), pz(z) {}  // Parameterized constructor

Double_t DATA::Magnitude() {
    return std::sqrt(px * px + py * py + pz * pz);  // Calculates magnitude
}