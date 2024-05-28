#ifndef SCHIFF_H
#define SCHIFF_H

#include "DefaultSchiffWerte.h"

class Schiff
{
    public:
        int groesse_;
        int huelle_;
        int schaden_;
        int erfahrungspunkte_ = 0;
        schifftyp type_;
    public:
        Schiff(int groesse, int huelle, int schaden, schifftyp type_) : groesse_(groesse), huelle_(huelle), schaden_(schaden), type_(type_){};
        virtual ~Schiff();
    protected:

    private:
};

#endif // SCHIFF_H
