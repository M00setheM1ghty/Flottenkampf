#include "Spiellogik.h"



Spiellogik::Spiellogik()
{
    shipsTeamA.fill(nullptr);
    shipsTeamB.fill(nullptr);
    currentShipAmountTeamA = 0;
    currentShipAmountTeamB = 0;
}

Spiellogik::~Spiellogik()
{
    for(Schiff* ship : shipsTeamA)
    {
        delete ship;
    }
    for(Schiff* ship : shipsTeamB)
    {
        delete ship;
    }
}

void Spiellogik::spielSetup()
{
    chooseShipsForTeams();
    addShipsToTeams();
}

void Spiellogik::spielAttackRound()
{

}


/////////////////// HELPER FUNCTIONS SPIEL SETUP

schifftyp Spiellogik::findShipType(const std::string& input)
{
    if (input == "JAEGER") return JAEGER;
    if (input == "ZERSTOERER") return ZERSTOERER;
    if (input == "KREUZER") return KREUZER;
    return INVALID;
}

void Spiellogik::addShipToTeam(schifftyp shiptype, teams team) {
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

    // Add the ship to the appropriate team
    if (team == TeamA) {
        if (currentShipAmountTeamA < MAX_TEAM_SIZE) {
            shipsTeamA[currentShipAmountTeamA] = newShip;
            ++currentShipAmountTeamA;
        } else {
            std::cout << "Team A is full, cannot add more ships" << std::endl;
            delete newShip;
        }
    } else if (team == TeamB) {
        if (currentShipAmountTeamB < MAX_TEAM_SIZE) {
            shipsTeamB[currentShipAmountTeamB] = newShip;
            ++currentShipAmountTeamB;
        } else {
            std::cout << "Team B is full, cannot add more ships" << std::endl;
            delete newShip;
        }
    } else {
        std::cout << "Invalid team, cannot add ship" << std::endl;
        delete newShip;
    }
}


void Spiellogik::addShipsToTeams()
{
    teams teamB = TeamB;
    teams teamA = TeamA;

    for(schifftyp ship : chosenShipsTeamA)
    {
        addShipToTeam(ship,teamA);
    }
    for(schifftyp ship : chosenShipsTeamB)
    {
        addShipToTeam(ship,teamB);
    }
}

void Spiellogik::chooseShipsForTeams() {
    std::string input;
    schifftyp shiptype;
    int shipAmountA = 0;
    int shipAmountB = 0;

    std::cout << "Suche " << MAX_TEAM_SIZE << " Schiffe für Flotte A aus:" << std::endl;
    while(shipAmountA < MAX_TEAM_SIZE)
    {
        std::cout << "Optionen: JAEGER, ZERSTOERER, KREUZER" << std::endl;
        std::cin >> input;
        shiptype = findShipType(input);
        if(shiptype == INVALID)
        {
            std::cout << "Bitte eine valide Option eingeben!" << std::endl;
        } else
        {
            chosenShipsTeamA[shipAmountA] = shiptype;
            ++shipAmountA;
        }
    }

    std::cout << "Suche " << MAX_TEAM_SIZE << " Schiffe für Flotte B aus:" << std::endl;
    while(shipAmountB < MAX_TEAM_SIZE)
    { // Loop until MAX_TEAM_SIZE ships are chosen
        std::cout << "Optionen: JAEGER, ZERSTOERER, KREUZER" << std::endl;
        std::cin >> input;
        shiptype = findShipType(input);
        if(shiptype == INVALID)
        {
            std::cout << "Bitte eine valide Option eingeben!" << std::endl;
        } else
        {
            chosenShipsTeamB[shipAmountB] = shiptype;
            ++shipAmountB;
        }
    }
}

////////////////// HELPER FUNCTIONS SPIEL ATTACK CYCLE
void Spiellogik::executeRound()
{
    chooseAttackerAndTarget(TeamA);
    chooseAttackerAndTarget(TeamB);
}

void Spiellogik::chooseAttackerAndTarget(teams team)
{
    std::string attackerShip; std::string shipToAttack; int inputAttackerShip; int inputShipToAttack;
    do {
        std::cout << "Wähle eines deiner Schiffe für die Attacke (0,1,2): " << std::endl;
        if(team == TeamA)
        {
            printTeams(TeamA);
        }
        if(team == TeamB)
        {
            printTeams(TeamB);
        }
        std::getline(std::cin, attackerShip); std::cout << std::endl;
        try {
            inputAttackerShip = std::stoi(attackerShip);
        } catch (const std::invalid_argument& e) {
            std::cout << "Ungültige Eingabe. Bitte eine Zahl eingeben." << std::endl;
            inputAttackerShip = -1; // Reset input
        } catch (const std::out_of_range& e) {
            std::cout << "Zahl außerhalb des gültigen Bereichs. Bitte 0, 1 oder 2 eingeben." << std::endl;
            inputAttackerShip = -1; // Reset input
        }
    }while(!checkChosenShipInput(inputAttackerShip));

    do {
        std::cout << "Wähle eine gegnerisches Schiff um es anzugreifen (0,1,2): " << std::endl;
        if(team == TeamA)
        {
            printTeams(TeamB);
        }
        if(team == TeamB)
        {
            printTeams(TeamA);
        }
        std::getline(std::cin, shipToAttack); std::cout << std::endl;
        try {
            inputShipToAttack = std::stoi(shipToAttack);
        } catch (const std::invalid_argument& e) {
            std::cout << "Ungültige Eingabe. Bitte eine Zahl eingeben." << std::endl;
            inputShipToAttack = -1; // Reset input
        } catch (const std::out_of_range& e) {
            std::cout << "Zahl außerhalb des gültigen Bereichs. Bitte 0, 1 oder 2 eingeben." << std::endl;
            inputShipToAttack = -1; // Reset input
        }
    } while(!checkChosenShipInput(inputShipToAttack));

    currentShipsForCombat={inputAttackerShip,inputShipToAttack};
}

int Spiellogik::checkChosenShipInput(int input)
{
    if(input < 0 || input > 2)
    {
        std::cout << "Auswahl muss 0,1 oder 2 sein!" << std::endl;
        return 0;
    }
    return 1;
}


////////////////// PRINT FUNCTIONS
void Spiellogik::printShips()
{
    for(Schiff* ship : shipsTeamA)
    {
        std::cout << ship->groesse_ << ship->huelle_ << ship->schaden_ << ship->type_ << std::endl;
    }
    for(Schiff* ship : shipsTeamB)
    {
        std::cout << ship->groesse_ << ship->huelle_ << ship->schaden_ << ship->type_ << std::endl;
    }
}

void Spiellogik::printChosenShips()
{
    for(schifftyp ship : chosenShipsTeamA)
    {
        std::cout << ship << std::endl;
    }
    for(schifftyp ship : chosenShipsTeamB)
    {
        std::cout << ship << std::endl;
    }
}

void Spiellogik::printTeams(teams team)
{
    //get ship types for printing
    int amountA=0; int amountB=0;
    std::array<std::string,MAX_TEAM_SIZE> TeamA_names;
    std::array<std::string,MAX_TEAM_SIZE> TeamB_names;
    for(Schiff* ship : shipsTeamA)
    {
        switch(ship->type_)
        {
        case 0:
            TeamA_names[amountA]="JAEGER";
            break;
        case 1:
            TeamA_names[amountA]="ZERSTOERER";
            break;
        case 2:
            TeamA_names[amountA]="KREUZER";
            break;
        default:
            std::cout << "Typ existiert nicht!";
            break;
        }
        ++amountA;
    }
    for(Schiff* ship : shipsTeamB)
    {
        switch(ship->type_)
        {
        case 0:
            TeamB_names[amountB]="JAEGER";
            break;
        case 1:
            TeamB_names[amountB]="ZERSTOERER";
            break;
        case 2:
            TeamB_names[amountB]="KREUZER";
            break;
        default:
            std::cout << "Typ existiert nicht!";
        }
        ++amountB;
    }
    if(team == TeamA)
    {
        //print team info
        int counterA = 0;
        std::cout << "Team A: " << std::endl;
        for(const std::string& shipName : TeamA_names)
        {
            std::cout << counterA << ": " << shipName << " / ";
            ++counterA;
        }
        std::cout << std::endl;
    }
    if(team == TeamB)
    {
        int counterB = 0;
        std::cout << "Team B: " << std::endl;
        for(const std::string& shipName : TeamB_names)
        {
            std::cout << counterB << ": " << shipName << " / ";
            ++counterB;
        }
        std::cout << std::endl;
    }

}



