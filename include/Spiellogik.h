#ifndef SPIELLOGIK_H
#define SPIELLOGIK_H

#include <array>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Schiff.h"
#include "Jaeger.h"
#include "Kreuzer.h"
#include "Zerstoerer.h"


class Spiellogik
{
    public:
        Spiellogik();
        ~Spiellogik();

        // spiel setup functions
        void spielSetup();
        void spielAttackRound();
        schifftyp findShipType(const std::string& input);
        void addShipToTeam(schifftyp shiptype, teams team);
        void chooseShipsForTeams();
        void addShipsToTeams();
        // attack cycle functions
        void executeRound();
        void chooseAttackerAndTarget(teams team);
        int checkChosenShipInput(int input);
        angriffsErfolg determineAttackSuccess(int shipSize);
        void executeAttack();
        // print functions
        void printShips();
        void printChosenShips();
        void printTeams(teams team);
    public:
        std::array<Schiff*,MAX_TEAM_SIZE> shipsTeamA;
        std::array<Schiff*,MAX_TEAM_SIZE> shipsTeamB;
        std::array<schifftyp, MAX_TEAM_SIZE> chosenShipsTeamA;
        std::array<schifftyp, MAX_TEAM_SIZE> chosenShipsTeamB;
        std::array<int,2> currentShipsForCombat; // AttackerShip=0,ShipToAttack=1 -> contains placement of chosen ship in shipsTeam array
        int currentShipAmountTeamA;
        int currentShipAmountTeamB;
        teams currentAttacker;

    protected:

    private:

};

#endif // SPIELLOGIK_H
