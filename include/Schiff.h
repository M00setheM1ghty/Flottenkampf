#ifndef SCHIFF_H
#define SCHIFF_H

#include "DefaultSchiffWerte.h"
#include <iostream>
#include <cassert>

class Schiff
{
    public:
        int groesse_;
        int huelle_;
        int schaden_;
        int erfahrungspunkte_ = 0;
        schifftyp type_;
        position schiffPosition_;
    public:
        Schiff(int groesse, int huelle, int schaden, schifftyp type_) : groesse_(groesse), huelle_(huelle), schaden_(schaden), type_(type_){};
        virtual ~Schiff();
        virtual void attack(Schiff* target,float damageFactorDistance) = 0;
        virtual angriffsErfolg determineAttackSuccess(int randomNumber) = 0;
        virtual int checkShipAbility(int randomNumber) = 0;
        virtual void specialAbilityOne() = 0;
        virtual void specialAbilityTwo() = 0;
        void moveShip();
    protected:

    private:
};

#endif // SCHIFF_H
