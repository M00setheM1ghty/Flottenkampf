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
        erfahrungspunkte_ += (schaden_/10);
        std::cout << "Jaeger bekommt " << (schaden_/10) << " Erfahrungspunkte" << std::endl;
    } else {
        std::cout << "Zerstoerer verfehlt Ziel!" << std::endl;
    }
    specialAbilityOne();
    specialAbilityTwo();
}

void Zerstoerer::specialAbilityOne()
{
    if(erfahrungspunkte_ > 2 && erfahrungspunkte_ <= 7)
    {
        erfahrungspunkte_ += 2;
        std::cout << "Zerstoerer bekommt extra Erfahrungspunkt durch SA1." << std::endl;
    }
}

void Zerstoerer::specialAbilityTwo()
{
    if(erfahrungspunkte_ > 7)
    {
        groesse_ = 9;
        schaden_ = 100;
        std::cout << "Zerstoerer neuer Schadenswert: 100. Neuer Groessenwert: 9, SA2." << std::endl;
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
