#ifndef ZERSTOERER_H
#define ZERSTOERER_H

#include "Schiff.h"

class Zerstoerer : public Schiff
{
    public:
        Zerstoerer(int groesse, int huelle, int schaden) : Schiff(groesse, huelle, schaden){};

    protected:

    private:
};

#endif // ZERSTOERER_H
