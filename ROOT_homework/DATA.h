#ifndef __DATA_H__
#define __DATA_H__

#include <TObject.h>

class DATA : public TObject {
public:
    DATA();                    // Default constructor
    DATA(Float_t px, Float_t py, Float_t pz); // Parameterized constructor
    virtual ~DATA();           // Destructor

    Float_t px;  // x component of momentum
    Float_t py;  // y component of momentum
    Float_t pz;  // z component of momentum

    Float_t Magnitude() const; // Function to calculate magnitude of momentum

    ClassDef(DATA, 1);
};

#endif // __DATA_H__