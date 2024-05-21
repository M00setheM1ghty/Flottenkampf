#ifndef SPIELLOGIK_H
#define SPIELLOGIK_H

#include <array>
#include
#include <iostream>
#include "DefaultSchiffWerte.h"

class Spiellogik
{
    public:
        Spiellogik();
        virtual ~Spiellogik();

        void spielSetupInput();
    public:
        std::array<int,MAX_TEAM_SIZE> schiffTeamA;
        std::array<int,MAX_TEAM_SIZE> schiffeTeamB;

    protected:

    private:

};

#endif // SPIELLOGIK_H
