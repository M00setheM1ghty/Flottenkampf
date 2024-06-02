#include "Kreuzer.h"

Kreuzer::~Kreuzer()
{

}

void Kreuzer::attack(Schiff* target)
{
    int randomNumber = rand() % 10 + 1;
    if (determineAttackSuccess(randomNumber) == SUCCESS)
    {
        if(checkShipAbility(randomNumber)==1 && target != nullptr) attack(target);
        target->huelle_ -= schaden_;
        std::cout << "Kreuzer trifft und macht" << schaden_ << "schaden!" << std::endl;
    } else {
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
