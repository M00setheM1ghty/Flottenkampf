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
        std::cout << "Jaeger trifft und macht " << damageMultiplicator*schaden_ << " schaden!" << std::endl;
        erfahrungspunkte_ += (schaden_/10);
        std::cout << "Jaeger bekommt " << (schaden_/10) << " Erfahrungspunkte" << std::endl;
    } else {
        std::cout << "Jaeger verfehlt Ziel!" << std::endl;
    }
    specialAbilityOne();
    specialAbilityTwo();
}

void Jaeger::specialAbilityOne()
{
    if(erfahrungspunkte_ > 2 && erfahrungspunkte_ < 10)
    {
        erfahrungspunkte_+=1;
        std::cout << "JAEGER bekommt 2 Erfahrungspunkte durch SA1!" << std::endl;
    }
}

void Jaeger::specialAbilityTwo()
{
    if(erfahrungspunkte_ >= 10)
    {
        huelle_ += 10;
        std::cout << "JAEGER bekommt 10 Huellenpunktedurch SA2!" << std::endl;
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
