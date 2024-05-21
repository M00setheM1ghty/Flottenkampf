#ifndef JAEGER_H
#define JAEGER_H

#include "Schiff.h"

class Jaeger : public Schiff
{
    public:
        Jaeger(int groesse, int huelle, int schaden) : Schiff(groesse, huelle, schaden){};
        virtual ~Jaeger();

    protected:

    private:
};

#endif // JAEGER_H
