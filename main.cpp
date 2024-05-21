#include <iostream>
#include <assert.h>

#include "DefaultSchiffWerte.h"
#include "Jaeger.h"
#include "Schiff.h"

int main()
{
    Jaeger schiff1(JaegerWerte.groesse, JaegerWerte.huelle, JaegerWerte.schaden);
    std::cout << schiff1.groesse_ << " " << schiff1.huelle_ << " " << schiff1.schaden_ << std::endl;
}
