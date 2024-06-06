#ifndef JAEGER_H
#define JAEGER_H

#include "Schiff.h"

class Jaeger : public Schiff
{
    public:
        Jaeger(int groesse, int huelle, int schaden) : Schiff(groesse, huelle, schaden,JAEGER){};
        virtual ~Jaeger();
        void attack(Schiff* target) override;
        angriffsErfolg determineAttackSuccess(int randomNumber) override;
        int checkShipAbility(int randomNumber) override;
        void specialAbilityOne() override;
        void specialAbilityTwo() override;

    protected:

    private:
};

#endif // JAEGER_H
