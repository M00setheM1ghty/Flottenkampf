#include "Schiff.h"

Schiff::~Schiff()
{
    //dtor
}

void Schiff::moveShip()
{
    bool validMove = false;
    while (!validMove) {
        int moveDirection = rand() % 4;
        switch(moveDirection)
        {
            case 0:
                if (schiffPosition_.yCord > 0) {
                    --schiffPosition_.yCord;
                    validMove = true;
                }
                break;
            case 1:
                if (schiffPosition_.xCord < 4) {
                    ++schiffPosition_.xCord;
                    validMove = true;
                }
                break;
            case 2:
                if (schiffPosition_.yCord < 4) {
                    ++schiffPosition_.yCord;
                    validMove = true;
                }
                break;
            case 3:
                if (schiffPosition_.xCord > 0) {
                    --schiffPosition_.xCord;
                    validMove = true;
                }
                break;
            default:
                std::cout << "Kein legaler Zug!" << std::endl;
        }
    }
    assert(schiffPosition_.xCord >= 0 && schiffPosition_.xCord < 5 && "xCord is out of bounds");
    assert(schiffPosition_.yCord >= 0 && schiffPosition_.yCord < 5 && "yCord is out of bounds");
}
