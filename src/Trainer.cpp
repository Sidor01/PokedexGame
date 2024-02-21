#include "Trainer.h"
#include "MyException.h"

Trainer::Trainer(int value) {
    teamSize = value;
    team = new Pokemon[value];
}

Trainer::~Trainer()
{
    delete[] team;
}
int Trainer::getTeamSize()
{
    return teamSize;
}
FireTrainer::FireTrainer(int value) : Trainer(value)
{
    fireTeam = new Pokemon[value];
}
GrassTrainer::GrassTrainer(int value) : Trainer(value)
{
    grassTeam = new Pokemon[value];
}
WaterTrainer::WaterTrainer(int value) : Trainer(value)
{
    waterTeam = new Pokemon[value];
}

FireTrainer::~FireTrainer()
{
    delete[] fireTeam;
}
GrassTrainer::~GrassTrainer()
{
    delete[] grassTeam;
}
WaterTrainer::~WaterTrainer()
{
    delete[] waterTeam;
}
Pokemon *Trainer::getTeam()
{
    return team;
}
Pokemon *FireTrainer::getTeam()
{
    return fireTeam;
}
Pokemon *WaterTrainer::getTeam()
{
    return waterTeam;
}
Pokemon *GrassTrainer::getTeam() {
    return grassTeam;
}
void Trainer::setTeam() {

    int teamSize = getTeamSize();

    try {
        if (teamSize == 6) {
            try {

                int eeveeIndex = pokemonCollection.findPokemon("Eevee");
                int flareonIndex = pokemonCollection.findPokemon("Flareon");
                int jolteonIndex = pokemonCollection.findPokemon("Jolteon");
                int vaporeonIndex = pokemonCollection.findPokemon("Vaporeon");
                int abraIndex = pokemonCollection.findPokemon("Abra");
                int kadabraIndex = pokemonCollection.findPokemon("Kadabra");

                if (eeveeIndex != -1 && flareonIndex != -1 && jolteonIndex != -1 && vaporeonIndex != -1 &&
                    abraIndex != -1 && kadabraIndex != -1) {

                    team[0] = pokemonCollection.getPokemonCollection()[eeveeIndex];
                    team[1] = pokemonCollection.getPokemonCollection()[flareonIndex];
                    team[2] = pokemonCollection.getPokemonCollection()[jolteonIndex];
                    team[3] = pokemonCollection.getPokemonCollection()[vaporeonIndex];
                    team[4] = pokemonCollection.getPokemonCollection()[abraIndex];
                    team[5] = pokemonCollection.getPokemonCollection()[kadabraIndex];

                } else {
                    throw MyException("Error: One or more Pokemon not found in the Pokedex.");
                }
            } catch (MyException &a) {
                cerr << a.what() << endl;
                QCoreApplication::quit();
            }

        }

        else if (teamSize == 3) {
            try {

                int eeveeIndex = pokemonCollection.findPokemon("Eevee");
                int flareonIndex = pokemonCollection.findPokemon("Flareon");
                int jolteonIndex = pokemonCollection.findPokemon("Jolteon");

                if (eeveeIndex != -1 && flareonIndex != -1 && jolteonIndex != -1) {

                    team[0] = pokemonCollection.getPokemonCollection()[eeveeIndex];
                    team[1] = pokemonCollection.getPokemonCollection()[flareonIndex];
                    team[2] = pokemonCollection.getPokemonCollection()[jolteonIndex];

                } else {
                    throw MyException("Error: One or more Pokemon not found in the Pokedex.");
                }
            } catch (MyException &a) {
                cerr << a.what() << endl;
                QCoreApplication::quit();
            }
        } else
            throw MyException("Error: Wrong team value");
    } catch (MyException &a) {
        cerr << a.what() << endl;
        QCoreApplication::quit();
    }
}
void FireTrainer::setTeam() {

    int teamSize = getTeamSize();
    try {
        if (teamSize == 6) {
            try {

                int charmanderIndex = pokemonCollection.findPokemon("Charmander");
                int charmeleonIndex = pokemonCollection.findPokemon("Charmeleon");
                int charizardIndex = pokemonCollection.findPokemon("Charizard");
                int ponytaIndex = pokemonCollection.findPokemon("Ponyta");
                int rapidashIndex = pokemonCollection.findPokemon("Rapidash");
                int snorlaxIndex = pokemonCollection.findPokemon("Snorlax");

                if (charmanderIndex != -1 && charmeleonIndex != -1 && charizardIndex != -1 &&
                    ponytaIndex != -1 && rapidashIndex != -1 && snorlaxIndex != -1) {

                    fireTeam[0] = pokemonCollection.getPokemonCollection()[charmanderIndex];
                    fireTeam[1] = pokemonCollection.getPokemonCollection()[charmeleonIndex];
                    fireTeam[2] = pokemonCollection.getPokemonCollection()[charizardIndex];
                    fireTeam[3] = pokemonCollection.getPokemonCollection()[ponytaIndex];
                    fireTeam[4] = pokemonCollection.getPokemonCollection()[rapidashIndex];
                    fireTeam[5] = pokemonCollection.getPokemonCollection()[snorlaxIndex];

                } else {
                    throw MyException("Error: One or more Fire-type Pokemon not found in the Pokedex.");
                }
            } catch (MyException &a) {
                cerr << a.what() << endl;
                QCoreApplication::quit();
            }
        } else if (teamSize == 3) {
            try {

                int charmanderIndex = pokemonCollection.findPokemon("Charmander");
                int charmeleonIndex = pokemonCollection.findPokemon("Charmeleon");
                int charizardIndex = pokemonCollection.findPokemon("Charizard");

                if (charmanderIndex != -1 && charmeleonIndex != -1 && charizardIndex != -1) {

                    fireTeam[0] = pokemonCollection.getPokemonCollection()[charmanderIndex];
                    fireTeam[1] = pokemonCollection.getPokemonCollection()[charmeleonIndex];
                    fireTeam[2] = pokemonCollection.getPokemonCollection()[charizardIndex];

                } else {
                    throw MyException("Error: One or more Fire-type Pokemon not found in the Pokedex.");
                }
            } catch (MyException &a) {
                cerr << a.what() << endl;
                QCoreApplication::quit();
            }
        } else
            throw MyException("Error: Wrong team value");
    } catch (MyException &a) {
        cerr << a.what() << endl;
        QCoreApplication::quit();
    }
}
void WaterTrainer::setTeam() {

    int teamSize = getTeamSize();
    try {
        if (teamSize == 6) {
            try {

                int squirtleIndex = pokemonCollection.findPokemon("Squirtle");
                int wartortleIndex = pokemonCollection.findPokemon("Wartortle");
                int blastoiseIndex = pokemonCollection.findPokemon("Blastoise");
                int laprasIndex = pokemonCollection.findPokemon("Lapras");
                int mrMimeIndex = pokemonCollection.findPokemon("Mr.Mime");
                int snorlaxIndex = pokemonCollection.findPokemon("Snorlax");

                if (squirtleIndex != -1 && wartortleIndex != -1 && blastoiseIndex != -1 &&
                    laprasIndex != -1 && mrMimeIndex != -1 && snorlaxIndex != -1) {

                    waterTeam[0] = pokemonCollection.getPokemonCollection()[squirtleIndex];
                    waterTeam[1] = pokemonCollection.getPokemonCollection()[wartortleIndex];
                    waterTeam[2] = pokemonCollection.getPokemonCollection()[blastoiseIndex];
                    waterTeam[3] = pokemonCollection.getPokemonCollection()[laprasIndex];
                    waterTeam[4] = pokemonCollection.getPokemonCollection()[mrMimeIndex];
                    waterTeam[5] = pokemonCollection.getPokemonCollection()[snorlaxIndex];

                } else {
                    throw MyException("Error: One or more Water-type Pokemon not found in the Pokedex.");
                }
            } catch (MyException &a) {
                cerr << a.what() << endl;
                QCoreApplication::quit();
            }
        } else if (teamSize == 3) {
            try {

                int squirtleIndex = pokemonCollection.findPokemon("Squirtle");
                int wartortleIndex = pokemonCollection.findPokemon("Wartortle");
                int blastoiseIndex = pokemonCollection.findPokemon("Blastoise");

                if (squirtleIndex != -1 && wartortleIndex != -1 && blastoiseIndex != -1) {
                    waterTeam[0] = pokemonCollection.getPokemonCollection()[squirtleIndex];
                    waterTeam[1] = pokemonCollection.getPokemonCollection()[wartortleIndex];
                    waterTeam[2] = pokemonCollection.getPokemonCollection()[blastoiseIndex];

                } else {
                    throw MyException("Error: One or more Water-type Pokemon not found in the Pokedex.");
                }
            } catch (MyException &a) {
                cerr << a.what() << endl;
                QCoreApplication::quit();
            }
        } else
            throw MyException("Error: Wrong team value");
    } catch (MyException &a) {
        cerr << a.what() << endl;
        QCoreApplication::quit();
    }
}
void GrassTrainer::setTeam() {

    int teamSize = getTeamSize();
    try {
        if (teamSize == 6) {
            try {
                int bulbasaurIndex = pokemonCollection.findPokemon("Bulbasaur");
                int ivysaurIndex = pokemonCollection.findPokemon("Ivysaur");
                int venusaurIndex = pokemonCollection.findPokemon("Venusaur");
                int magnemiteIndex = pokemonCollection.findPokemon("Magnemite");
                int magnezoneIndex = pokemonCollection.findPokemon("Magnezone");
                int snorlaxIndex = pokemonCollection.findPokemon("Snorlax");
                if (bulbasaurIndex != -1 && ivysaurIndex != -1 && venusaurIndex != -1 &&
                    magnemiteIndex != -1 && magnezoneIndex != -1 && snorlaxIndex != -1) {

                    grassTeam[0] = pokemonCollection.getPokemonCollection()[bulbasaurIndex];
                    grassTeam[1] = pokemonCollection.getPokemonCollection()[ivysaurIndex];
                    grassTeam[2] = pokemonCollection.getPokemonCollection()[venusaurIndex];
                    grassTeam[3] = pokemonCollection.getPokemonCollection()[magnemiteIndex];
                    grassTeam[4] = pokemonCollection.getPokemonCollection()[magnezoneIndex];
                    grassTeam[5] = pokemonCollection.getPokemonCollection()[snorlaxIndex];
                } else {
                    throw MyException("Error: One or more Grass-type Pokemon not found in the Pokedex.");
                }
            } catch (MyException &a) {
                cerr << a.what() << endl;
                QCoreApplication::quit();
            }
        } else if (teamSize == 3) {
            try {
                int bulbasaurIndex = pokemonCollection.findPokemon("Bulbasaur");
                int ivysaurIndex = pokemonCollection.findPokemon("Ivysaur");
                int venusaurIndex = pokemonCollection.findPokemon("Venusaur");

                if (bulbasaurIndex != -1 && ivysaurIndex != -1 && venusaurIndex != -1) {
                    grassTeam[0] = pokemonCollection.getPokemonCollection()[bulbasaurIndex];
                    grassTeam[1] = pokemonCollection.getPokemonCollection()[ivysaurIndex];
                    grassTeam[2] = pokemonCollection.getPokemonCollection()[venusaurIndex];

                } else {
                    throw MyException("Error: One or more Grass-type Pokemon not found in the Pokedex.");
                }
            } catch (MyException &a) {
                cerr << a.what() << endl;
                QCoreApplication::quit();
            }
        } else
            throw MyException("Error: Wrong team value");
    } catch (MyException &a) {
        cerr << a.what() << endl;
        QCoreApplication::quit();
    }
}
