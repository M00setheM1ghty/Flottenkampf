#ifndef SPIELLOGIK_H
#define SPIELLOGIK_H

#include <array>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>
#include "Schiff.h"
#include "Jaeger.h"
#include "Kreuzer.h"
#include "Zerstoerer.h"
#include "Team.h"
#include "DefaultSchiffWerte.h"
#include "Welt.h"

class Welt;

class Spiellogik
{
    public:
        Spiellogik();
        ~Spiellogik();
        float checkDistance(Schiff* attacker, Schiff* victim);
        void createTeams();
        void displayTeams() const;
        void initAllTeamsPositions();
        void executeAttack();
        void executeGame(Welt& welt);
    private:

    public:

    private:
        std::vector<std::unique_ptr<Team>> teams;
        int currentAttackerIndex = 0;

};

#endif // SPIELLOGIK_H
