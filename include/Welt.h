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
        void initWorld();
        void printWorld(const std::vector<std::unique_ptr<Team>>& teams) const;
    public:

    private:


    private:
        std::vector<position> spielfeld;

};

#endif // WELT_H
