#include "DATA.h"
#include <cmath>

ClassImp(DATA);

DATA::DATA() : 
px(0), py(0), pz(0) 
{
}

DATA::DATA(Float_t x, Float_t y, Float_t z) : 
px(x), py(y), pz(z) 
{
}

DATA::~DATA() 
{
}

Float_t DATA::Magnitude() const {
    return std::sqrt(px * px + py * py + pz * pz);
}