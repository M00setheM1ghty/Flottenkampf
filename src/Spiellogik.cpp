#include "Spiellogik.h"

Spiellogik::Spiellogik()
{

}

Spiellogik::~Spiellogik()
{

}

void Spiellogik::createTeams() {
    std::string teamName;
        for (int i = 0; i < MAX_TEAM_AMOUNT; ++i)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer
            std::cout << "Suche einen Namen für die Flotte " << i << " aus:" << std::endl;
            std::getline(std::cin,teamName);
            teams.push_back(std::make_unique<Team>(teamName));
        }
    }

void Spiellogik::displayTeams() const {
        for (const auto& team : teams) {
            team->displayTeam();
        }
    }

void Spiellogik::executeRound()
{
    std::string indexAttacker; std::string indexToBeAttacked; int indexAttackerInt; int indexToBeAttackedInt;
    while(indexAttackerInt < 0 || indexAttackerInt > MAX_TEAM_SIZE-1)
    {
        std::cout << "Choose one of your ships: (0,1,2)" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer
        std::getline(std::cin,indexAttacker); indexAttackerInt = std::stoi(indexAttacker);
    }
    while(indexToBeAttackedInt < 0 || indexToBeAttackedInt > MAX_TEAM_SIZE-1)
    {
        std::cout << "Choose an enemy ship: (0,1,2)" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer
        std::getline(std::cin,indexToBeAttacked); indexToBeAttackedInt = std::stoi(indexToBeAttacked);
    }
    int targetIndex = (currentAttackerIndex + 1) % teams.size();
    if(teams.size() == MAX_TEAM_SIZE)
    {
        Schiff* attacker = teams[currentAttackerIndex]->getShipsOfTeam()[indexAttackerInt];
        Schiff* victim = teams[targetIndex]->getShipsOfTeam()[indexToBeAttackedInt];
        attacker->attack(victim);
    }
    currentAttackerIndex = targetIndex;
}
