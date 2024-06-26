#ifndef ZERSTOERER_H
#define ZERSTOERER_H

#include "Schiff.h"

class Zerstoerer : public Schiff
{
    public:
        Zerstoerer(int groesse, int huelle, int schaden) : Schiff(groesse, huelle, schaden, ZERSTOERER){};
        virtual ~Zerstoerer();
        void attack(Schiff* target, float damageFactorDistance) override;
        angriffsErfolg determineAttackSuccess(int randomNumber) override;
        int checkShipAbility(int randomNumber) override;
        void specialAbilityOne() override;
        void specialAbilityTwo() override;
    private:
};

#endif // ZERSTOERER_H
