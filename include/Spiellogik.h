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


class Spiellogik
{
    public:
        Spiellogik();
        ~Spiellogik();
        void createTeams();
        void displayTeams() const;
        void executeRound();

    private:


    public:

    private:
        std::vector<std::unique_ptr<Team>> teams;
        int currentAttackerIndex = 0;

    protected:

    private:

};

#endif // SPIELLOGIK_H
