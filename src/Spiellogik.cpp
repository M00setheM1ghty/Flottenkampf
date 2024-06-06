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
            currentAttackerIndexInt = rand() % MAX_TEAM_SIZE;
            indexToBeAttackedInt = rand() % MAX_TEAM_SIZE;

            // Get the attacker and victim ships
            attacker = teams[currentAttackerIndex]->getShipsOfTeam()[currentAttackerIndexInt];
            victim = teams[targetIndex]->getShipsOfTeam()[indexToBeAttackedInt];
        } while(attacker == nullptr || victim == nullptr);

        assert(attacker != nullptr && "Attacker pointer should not be nullptr after the loop");
        assert(victim != nullptr && "Victim pointer should not be nullptr after the loop");

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
            std::cout << std::endl;
            executeAttack();
            std::cout << std::endl;
            team->checkForDestroyedShipAndRemove();
            if(team->checkForGameEnd())
            {
                endOfGame = true;
                break;
            }
            std::cout << std::endl;
            displayTeams();
            std::cout << std::endl;
        }
    }
    assert(endOfGame && "Game should end when one team has no ships left");
}

void Spiellogik::initAllTeamsPositions()
{
    for(const auto& team : teams)
    {
        team->initTeamPositions();
    }
}
