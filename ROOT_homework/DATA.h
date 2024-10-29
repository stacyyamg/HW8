#ifndef DATA_H
#define DATA_H

#include <TObject.h>

class DATA : public TObject {
public:
    DATA(); // Default constructor

    Double_t px, py, pz; // Momentum components

    Double_t Magnitude(); // Function to calculate magnitude

private:
    ClassDef(DATA, 1);
};

#endif // DATA_H