
#ifndef DEFAULTSCHIFFWERTE_H
#define DEFAULTSCHIFFWERTE_H

struct SchiffWerte {
    int huelle;
    int groesse;
    int schaden;
};

const SchiffWerte JaegerWerte = {75, 4, 30};
const SchiffWerte ZerstoererWerte = {150, 6, 60};
const SchiffWerte KreuzerWerte = {250, 8, 50};

enum schiffnamen
{
    JAEGER = 0,
    ZERSTOERER = 1,
    KREUZER = 2
};

static const int MAX_TEAM_SIZE = 3;
#endif // DEFAULTSCHIFFWERTE_H

