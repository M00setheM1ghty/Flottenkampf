#ifndef KREUZER_H
#define KREUZER_H

#include "Schiff.h"

class Kreuzer : public Schiff
{
    public:
        Kreuzer(int groesse, int huelle, int schaden) : Schiff(groesse, huelle, schaden, KREUZER){};

    protected:

    private:
};

#endif // KREUZER_H
