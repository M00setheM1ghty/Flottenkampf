#include "Welt.h"

Welt::Welt()
{

}

Welt::~Welt()
{
    //dtor
}

void Welt::initWorld()
{
    for (int y = 0; y < MAX_MAP_LENGTH; ++y) {
        for (int x = 0; x < MAX_MAP_LENGTH; ++x) {
            spielfeld.push_back({x, y});
        }
    }
}

void Welt::printWorld(const std::vector<std::unique_ptr<Team>>& teams) const {
    for (int y = 0; y < MAX_MAP_LENGTH; ++y) {
        for (int x = 0; x < MAX_MAP_LENGTH; ++x) {
            bool shipFound = false;
            for (const auto& team : teams) {
                for (const auto& ship : team->shipsOfTeam_) {
                    if (ship == nullptr) {
                        continue;
                    } else if (ship->schiffPosition_.xCord == x && ship->schiffPosition_.yCord == y) {
                        std::cout << "S ";
                        shipFound = true;
                        break;
                    }
                }
                if (shipFound) {
                    break;
                }
            }
            if (!shipFound) {
                std::cout << "X ";
            }
        }
        std::cout << std::endl;
    }
}

