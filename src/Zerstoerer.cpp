#include "Zerstoerer.h"

Zerstoerer::~Zerstoerer()
{

}

void Zerstoerer::attack(Schiff* target)
{
    int randomNumber = rand() % 10 + 1;
    if (determineAttackSuccess(randomNumber) == SUCCESS)
    {
        target->huelle_ -= schaden_;
        std::cout << "Zerstoerer trifft und macht" << schaden_ << "schaden!" << std::endl;
    } else {
        std::cout << "Zerstoerer verfehlt Ziel!" << std::endl;
    }
}

angriffsErfolg Zerstoerer::determineAttackSuccess(int randomNumber)
{
    return randomNumber < (groesse_+2) ? SUCCESS : FAILURE;
}

int Zerstoerer::checkShipAbility(int randomNumber)
{
    return 0; // not used but implemented for pure virtual function in schiff.h
}
