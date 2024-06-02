#include "Jaeger.h"


Jaeger::~Jaeger()
{
    //dtor
}

void Jaeger::attack(Schiff* target)
{
    int randomNumber = rand() % 10 + 1; int damageMultiplicator = 1;
    if (determineAttackSuccess(randomNumber) == SUCCESS)
    {
        damageMultiplicator = checkShipAbility(randomNumber);
        target->huelle_ -= (damageMultiplicator * schaden_);
        std::cout << "Jaeger trifft und macht" << damageMultiplicator*schaden_ << "schaden!" << std::endl;
    } else {
        std::cout << "Jaeger verfehlt Ziel!" << std::endl;
    }
}

angriffsErfolg Jaeger::determineAttackSuccess(int randomNumber)
{
    return randomNumber < groesse_ ? SUCCESS : FAILURE;
}

int Jaeger::checkShipAbility(int randomNumber)
{
    if(randomNumber==1 || randomNumber==2)
    {
        return 2;
    }else
    {
        return 1;
    }
}
