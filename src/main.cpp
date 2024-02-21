#include "MainWindow.h"
#include "MyException.h"
#include "Pokedex.h"
#include "PokemonCollection.h"
#include <QApplication>
#include <QCoreApplication>
#include <QLabel>

using namespace std;
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    int argument;

    QStringList arguments = QCoreApplication::arguments();

    try {
        if (arguments.size() != 2) {
            throw MyException("Wrong amount of arguments");
        }

        QString firstArgument = arguments.at(1);
        argument = firstArgument.toInt();

        if (argument != 3 && argument != 6) {
            throw MyException("Argument should be equal to 3 or 6");
        }
    } catch (MyException &a) {
        cerr << a.what() << endl;
        argument = 3;
    }


    Pokedex pokedex;
    PokemonCollection pokemonCollection;

    Pokemon Charmander("Charmander", 8, 39, 65, "Fire", "Obviously prefers hot places. When it rains, steam is said to spout from the tip of its tail.");
    Pokemon Charmeleon("Charmeleon", 12, 58, 80, "Fire", "When it swings its burning tail, it elevates the temperature to unbearably high levels.");
    Pokemon Charizard("Charizard", 16, 78, 100, "Fire", "Flying", "Spits fire that is hot enough to melt boulders. Known to cause forest fires unintentionally.");
    Pokemon Squirtle("Squirtle", 10, 44, 43, "Water", "After birth, its back swells and hardens into a shell. Powerfully sprays foam from its mouth.");
    Pokemon Wartortle("Wartortle", 13, 59, 58, "Water", "Often hides in water to stalk unwary prey. For swimming fast, it moves its ears to maintain balance.");
    Pokemon Blastoise("Blastoise", 17, 79, 78, "Water", "A brutal POKEMON with pressurized water jets on its shell. They are used for high speed tackles.");
    Pokemon Bulbasaur("Bulbasaur", 10, 45, 45, "Grass", "Poison", "A strange seed was planted on its back at birth. The plant sprouts and grows with this POKEMON.");
    Pokemon Ivysaur("Ivysaur", 12, 60, 60, "Grass", "Poison", "When the bulb on its back grows large, it appears to lose the ability to stand on its hind legs.");
    Pokemon Venusaur("Venusaur", 16, 80, 80, "Grass", "Poison", "The plant blooms when it is absorbing solar energy. It stays on the move to seek sunlight.");
    Pokemon Gastly("Gastly", 7, 30, 80, "Ghost", "Poison", "Almost invisible, this gaseous POKEMON cloaks the target and puts it to sleep without notice.");
    Pokemon Haunter("Haunter", 10, 45, 95, "Ghost", "Poison", "Because of its ability to slip through block walls, it is said to be from another dimension.");
    Pokemon Gengar("Gengar", 13, 60, 110, "Ghost", "Poison", "Under a full moon, this POKEMON likes to mimic the shadows of people and laugh at their fright.");
    Pokemon Abra("Abra", 4, 25, 90, "Psychic", "Using its ability to read minds, it will identify impending danger and TELEPORT to safety.");
    Pokemon Kadabra("Kadabra", 7, 40, 105, "Psychic", "It emits special alpha waves from its body that induce headaches just by being close by.");
    Pokemon Alakazam("Alakazam", 10, 55, 120, "Psychic", "Its brain can outperform a supercomputer. Its intelligence quotient is said to be 5,000.");
    Pokemon MrMime("Mr.Mime", 9, 40, 90, "Psychic", "If interrupted while it is miming, it will slap around the offender with its broad hands.");
    Pokemon Lapras("Lapras", 17, 130, 60, "Water", "Ice", "A POKEMON that has been overhunted almost to extinction. It can ferry people across the water.");
    Pokemon Eevee("Eevee", 11, 55, 55, "Normal", "Its genetic code is irregular. It may mutate if it is exposed to radiation from element STONEs.");
    Pokemon Vaporeon("Vaporeon", 13, 130, 65, "Water", "Lives close to water. Its long tail is ridged with a fin which is often mistaken for a mermaid’s.");
    Pokemon Jolteon("Jolteon", 13, 65, 130, "Electric", "It accumulates negative ions in the atmosphere to blast out 10000-volt lightning bolts.");
    Pokemon Flareon("Flareon", 26, 65, 65, "Fire", "When storing thermal energy in its body, its temperature could soar to over 1600 degrees.");
    Pokemon Ponyta("Ponyta", 17, 50, 90, "Fire", "Its hooves are 10 times harder than diamonds. It can trample anything completely flat in little time.");
    Pokemon Rapidash("Rapidash", 20, 65, 105, "Fire", "Very competitive, this POKEMON will chase anything that moves fast in the hopes of racing it.");
    Pokemon Magikarp("Magikarp", 2, 20, 80, "Water", "In the distant past, it was somewhat stronger than the horribly weak descendants that exist today.");
    Pokemon Gyarados("Gyarados", 19, 95, 81, "Water", "Flying", "Rarely seen in the wild. Huge and vicious, it is capable of destroying entire cities in a rage.");
    Pokemon Snorlax("Snorlax", 22, 160, 30, "Normal", "Very lazy. Just eats and sleeps. As its rotund bulk builds, it becomes steadily more slothful.");
    Pokemon Magnemite("Magnemite", 7, 25, 45, "Electric", "Steel", "Uses anti-gravity to stay suspended. Appears without warning and uses THUNDER WAVE and similar moves.");
    Pokemon Magnezone("Magnezone", 12, 50, 70, "Electric", "Steel", "Formed by several MAGNEMITEs linked together. They frequently appear when sunspots flare up.");

    pokemonCollection.addPokemon(Charmander);
    pokemonCollection.addPokemon(Charmeleon);
    pokemonCollection.addPokemon(Charizard);
    pokemonCollection.addPokemon(Squirtle);
    pokemonCollection.addPokemon(Wartortle);
    pokemonCollection.addPokemon(Blastoise);
    pokemonCollection.addPokemon(Bulbasaur);
    pokemonCollection.addPokemon(Ivysaur);
    pokemonCollection.addPokemon(Venusaur);
    pokemonCollection.addPokemon(Gastly);
    pokemonCollection.addPokemon(Haunter);
    pokemonCollection.addPokemon(Gengar);
    pokemonCollection.addPokemon(Abra);
    pokemonCollection.addPokemon(Kadabra);
    pokemonCollection.addPokemon(Alakazam);
    pokemonCollection.addPokemon(MrMime);
    pokemonCollection.addPokemon(Lapras);
    pokemonCollection.addPokemon(Eevee);
    pokemonCollection.addPokemon(Vaporeon);
    pokemonCollection.addPokemon(Jolteon);
    pokemonCollection.addPokemon(Flareon);
    pokemonCollection.addPokemon(Ponyta);
    pokemonCollection.addPokemon(Rapidash);
    pokemonCollection.addPokemon(Magikarp);
    pokemonCollection.addPokemon(Gyarados);
    pokemonCollection.addPokemon(Snorlax);
    pokemonCollection.addPokemon(Magnemite);
    pokemonCollection.addPokemon(Magnezone);

    pokemonCollection.saveToBinaryFile("przyklad.txt");
    pokemonCollection.loadFromBinaryFile("przyklad.txt");

    pokedex.loadLabels();

    MainWindow w(argument, &pokedex);

    w.show();
    return a.exec();
}
