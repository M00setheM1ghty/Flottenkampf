#ifndef SPIELLOGIK_H
#define SPIELLOGIK_H

#include <array>
#include <string>
#include <iostream>
#include "Schiff.h"
#include "Jaeger.h"
#include "Kreuzer.h"
#include "Zerstoerer.h"


class Spiellogik
{
    public:
        Spiellogik();
        ~Spiellogik();

        // game functions
        void spielSetup();
        void spielAttackRound();
        schifftyp findShipType(const std::string& input);
        void addShipToTeam(schifftyp shiptype, teams team);
        void chooseShipsForTeams();
        void addShipsToTeams();
        // print functions
        void printShips();
        void printChosenShips();
        void printTeams();
    public:
        std::array<Schiff*,MAX_TEAM_SIZE> shipsTeamA;
        std::array<Schiff*,MAX_TEAM_SIZE> shipsTeamB;
        std::array<schifftyp, MAX_TEAM_SIZE> chosenShipsTeamA;
        std::array<schifftyp, MAX_TEAM_SIZE> chosenShipsTeamB;
        int currentShipAmountTeamA;
        int currentShipAmountTeamB;

    protected:

    private:

};

#endif // SPIELLOGIK_H
