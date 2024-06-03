#include "Kreuzer.h"

Kreuzer::~Kreuzer()
{

}

void Kreuzer::attack(Schiff* target)
{
    int randomNumber = rand() % 10 + 1;
    while (determineAttackSuccess(randomNumber) == SUCCESS && checkShipAbility(randomNumber) == 1 && target->huelle_ > 0)
    {
        target->huelle_ -= schaden_;
        std::cout << "Kreuzer trifft und macht " << schaden_ << " Schaden!" << std::endl;
        randomNumber = rand() % 10 + 1; // Generate a new random number for the next attack attempt
    }

    if (determineAttackSuccess(randomNumber) == FAILURE)
    {
        std::cout << "Kreuzer verfehlt Ziel!" << std::endl;
    }
}

angriffsErfolg Kreuzer::determineAttackSuccess(int randomNumber)
{
    return randomNumber < groesse_ ? SUCCESS : FAILURE;
}

int Kreuzer::checkShipAbility(int randomNumber)
{
    return 1;
}
