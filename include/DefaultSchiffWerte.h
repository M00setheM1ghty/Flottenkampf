
#ifndef DEFAULTSCHIFFWERTE_H
#define DEFAULTSCHIFFWERTE_H

#include <string>


struct SchiffWerte {
    int huelle;
    int groesse;
    int schaden;
    std::string spezialAngriffStandard;
};

const SchiffWerte JaegerWerte = {75, 4, 30, "kritischerTreffer"};
const SchiffWerte ZerstoererWerte = {150, 6, 60, "zielsuchend"};
const SchiffWerte KreuzerWerte = {250, 8, 50, "bombardment"};


struct position
{
    int xCord;
    int yCord;
};

enum schifftyp
{
    JAEGER = 0,
    ZERSTOERER = 1,
    KREUZER = 2,
    INVALID = 3
};

enum teams
{
    TeamA = 100,
    TeamB = 200
};

enum angriffsErfolg
{
    FAILURE = 0,
    SUCCESS
};


static const int MAX_TEAM_SIZE = 3;
static const int MAX_TEAM_AMOUNT = 2;
static const int MAX_MAP_LENGTH = 5;
#endif // DEFAULTSCHIFFWERTE_H

