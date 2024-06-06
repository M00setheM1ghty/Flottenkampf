#ifndef SPIELLOGIK_H
#define SPIELLOGIK_H

#include <array>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "Schiff.h"
#include "Jaeger.h"
#include "Kreuzer.h"
#include "Zerstoerer.h"
#include "Team.h"
#include "DefaultSchiffWerte.h"
#include "Welt.h"


class Spiellogik
{
    public:
        Spiellogik();
        ~Spiellogik();
        void createTeams();
        void displayTeams() const;
        void initAllTeamsPositions();
        void executeAttack();
        void executeGame();

    public:

    private:
        Welt welt;
        std::vector<std::unique_ptr<Team>> teams;
        int currentAttackerIndex = 0;

};

#endif // SPIELLOGIK_H
