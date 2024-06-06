#include "Kreuzer.h"

Kreuzer::~Kreuzer()
{

}

void Kreuzer::attack(Schiff* target,float damageFactorDistance)
{
    int randomNumber = rand() % 10 + 1;
    while (determineAttackSuccess(randomNumber) == SUCCESS && checkShipAbility(randomNumber) == 1 && target->huelle_ > 0)
    {
        target->huelle_ -= (schaden_*damageFactorDistance);
        std::cout << "Kreuzer trifft und macht " << schaden_*damageFactorDistance << " Schaden!" << std::endl;
        randomNumber = rand() % 10 + 1; // Generate a new random number for the next attack attempt
    }

    if (determineAttackSuccess(randomNumber) == FAILURE)
    {
        std::cout << "Kreuzer verfehlt Ziel!" << std::endl;
        erfahrungspunkte_ += 2;
        std::cout << "Kreuzer bekommt 2 Erfahrungspunkte" << std::endl;
    }
    specialAbilityOne();
    specialAbilityTwo();
}

void Kreuzer::specialAbilityOne()
{
    if(erfahrungspunkte_ >= 3 && erfahrungspunkte_ < 6)
    {
        groesse_ = 7;
        std::cout << "KREUZER verändert Groesse zu 7 durch SA1!" << std::endl;
    }
}

void Kreuzer::specialAbilityTwo()
{
    if(erfahrungspunkte_ >=6)
    {
        schaden_ +=5 ;
        huelle_-=20;
        std::cout << "KREUZER erhöht Schaden um 5, aber verliert 20 Huellenpunkte durch SA2!" << std::endl;
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
