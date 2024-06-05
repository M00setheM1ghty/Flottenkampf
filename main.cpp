#include <iostream>
#include <assert.h>
#include <array>
#include <cstdlib>
#include <ctime>

#include "DefaultSchiffWerte.h"
#include "Jaeger.h"
#include "Schiff.h"
#include "Spiellogik.h"
#include "Team.h"

#define USE_DOCTEST_MAIN 0

#if USE_DOCTEST_MAIN
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#endif

#if !USE_DOCTEST_MAIN
int main()
{

    Spiellogik spiel;
    spiel.createTeams();
    spiel.displayTeams();
}
#endif

