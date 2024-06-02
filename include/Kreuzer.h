#ifndef KREUZER_H
#define KREUZER_H

#include "Schiff.h"

class Kreuzer : public Schiff
{
    public:
        Kreuzer(int groesse, int huelle, int schaden) : Schiff(groesse, huelle, schaden, KREUZER){};
        virtual ~Kreuzer();
        void attack(Schiff* target) override;
        angriffsErfolg determineAttackSuccess(int randomNumber) override;
        int checkShipAbility(int randomNumber) override;

    protected:

    private:
};

#endif // KREUZER_H
