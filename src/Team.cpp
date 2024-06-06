#include "Team.h"

Team::Team(std::string teamname)
{
    teamName = teamname;
    chooseShipsForTeams();
    addShipsToTeams();
}

Team::~Team()
{
    for(Schiff* ship : shipsOfTeam_)
    {
        delete ship;
    }
}

//////////// Team Setup Functions

void Team::chooseShipsForTeams() {
    std::string input; schifftyp shiptype; int shipAmount = 0;

    std::cout << "Suche " << MAX_TEAM_SIZE << " Schiffe für die Flotte aus:" << std::endl;
    while(shipAmount < MAX_TEAM_SIZE)
    {
        std::cout << "Optionen: JAEGER, ZERSTOERER, KREUZER" << std::endl;
        std::cin >> input;
        shiptype = findShipType(input);
        if(shiptype == INVALID)
        {
            std::cout << "Bitte eine valide Option eingeben!" << std::endl;
        } else
        {
            chosenShips_.push_back(shiptype);
            ++shipAmount;
        }
    }
}

schifftyp Team::findShipType(const std::string& input)
{
    if (input == "JAEGER") return JAEGER;
    if (input == "ZERSTOERER") return ZERSTOERER;
    if (input == "KREUZER") return KREUZER;
    return INVALID;
}

void Team::createShipForTeam(schifftyp shiptype) {
    Schiff* newShip = nullptr;

    // Determine ship type and create the corresponding ship
    switch(shiptype) {
        case JAEGER:
            newShip = new Jaeger(JaegerWerte.groesse, JaegerWerte.huelle, JaegerWerte.schaden);
            break;
        case ZERSTOERER:
            newShip = new Zerstoerer(ZerstoererWerte.groesse, ZerstoererWerte.huelle, ZerstoererWerte.schaden);
            break;
        case KREUZER:
            newShip = new Kreuzer(KreuzerWerte.groesse, KreuzerWerte.huelle, KreuzerWerte.schaden);
            break;
        default:
            std::cout << "Schiff wurde nicht hinzugefügt" << std::endl;
            return;
    }
    // Add the ship to the team
    if(shipsOfTeam_.size() < MAX_TEAM_SIZE)
    {
        shipsOfTeam_.push_back(newShip);
    } else
    {
        std::cout << "Team A is full, cannot add more ships" << std::endl;
        delete newShip;
    }
}

void Team::addShipsToTeams()
{
    for(schifftyp ship : chosenShips_)
    {
        createShipForTeam(ship);
    }
}

void Team::displayTeam() const {
        std::cout << "Team name: " << teamName << std::endl;
        for(Schiff* ships : shipsOfTeam_)
        {
            if(ships == nullptr)
            {
                std::cout << "/Destroyed Ship/" << std::endl;
            } else
            {
                std::cout << "Schifftyp: " << ships->type_ << " Huelle: " << ships->huelle_ << " Schaden: " << ships->schaden_
                << " Groesse: " << ships->groesse_ << " Erfahrungspunkte: " << ships->erfahrungspunkte_ << std::endl;
            }
        }
    }

// fighting functions //
void Team::checkForDestroyedShipAndRemove()
{
    for(Schiff*& ship : shipsOfTeam_)
    {
        if(ship && ship->huelle_ <= 0)
        {
            delete ship;
            ship = nullptr;
        }
    }
    for (const auto& ship : shipsOfTeam_) {
        assert(ship == nullptr || ship->huelle_ > 0);
    }
}

bool Team::checkForGameEnd()
{
    for(Schiff* ship : shipsOfTeam_)
    {
        if(ship != nullptr)
        {
            return false;
        }
    }
    std::cout << "Team " << teamName << " has no more ships and loses!" << std::endl;
    return true;
}


// getter setter //

const std::vector<Schiff*>& Team::getShipsOfTeam() const
{
    return shipsOfTeam_;
}

Schiff* Team::getShipByIndex(int index) const
{
    return shipsOfTeam_.at(index);
}
