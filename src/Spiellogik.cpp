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
