#ifndef WELT_H
#define WELT_H

#include <vector>
#include "Schiff.h"
#include "DefaultSchiffWerte.h"
#include "Spiellogik.h"

class Welt
{
    public:
        Welt();
        ~Welt();
    public:

    private:


    private:
        std::vector<position> spielfeld;
};

#endif // WELT_H
