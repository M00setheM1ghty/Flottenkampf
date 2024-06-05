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


void Spiellogik::executeAttack()
{
    int targetIndex = (currentAttackerIndex + 1) % teams.size();
    if(teams.size() == MAX_TEAM_AMOUNT)
    {
        int currentAttackerIndexInt; int indexToBeAttackedInt;
        Schiff* attacker = nullptr; Schiff* victim = nullptr;

        do {
            // Generate indices from 0-2
            currentAttackerIndexInt = rand() % teams[currentAttackerIndex]->getShipsOfTeam().size();
            indexToBeAttackedInt = rand() % teams[targetIndex]->getShipsOfTeam().size();

            // Get the attacker and victim ships
            attacker = teams[currentAttackerIndex]->getShipsOfTeam()[currentAttackerIndexInt];
            victim = teams[targetIndex]->getShipsOfTeam()[indexToBeAttackedInt];
        } while(attacker == nullptr || victim == nullptr);

        attacker->attack(victim);
    }
    currentAttackerIndex = targetIndex;
}

void Spiellogik::executeGame()
{
    bool endOfGame = false;
    createTeams();
    displayTeams();

    while(!endOfGame)
    {
        for(const auto& team : teams)
        {
            executeAttack();
            team->checkForDestroyedShipAndRemove();
            endOfGame = team->checkForGameEnd();
            if(endOfGame) return;
        }
    }
}
