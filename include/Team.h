#ifndef TEAM_H
#define TEAM_H

#include <array>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <vector>
#include <memory>
#include "Schiff.h"
#include "Jaeger.h"
#include "Kreuzer.h"
#include "Zerstoerer.h"
#include "DefaultSchiffWerte.h"

class Team
{
    public:
        Team(std::string teamname);
        ~Team();
        // setup team
        void chooseShipsForTeams();
        schifftyp findShipType(const std::string& input);
        void createShipForTeam(schifftyp shiptype);
        void addShipsToTeams();
        // fighting functions

        // print functions
        void printTeam() const;
        void displayTeam() const;
        //getter setter
        const std::vector<Schiff*>& getShipsOfTeam() const;
        Schiff* getShipByIndex(int index) const;


    public:
        std::vector<Schiff*> shipsOfTeam_;
        std::vector<schifftyp> chosenShips_;
        std::string teamName;


    protected:

    private:
};

#endif // TEAM_H
