#include "PokemonCollection.h"

vector<Pokemon> PokemonCollection::pokemonCollection;

PokemonCollection::PokemonCollection() {}
void PokemonCollection::addPokemon(const Pokemon &p)
{
    pokemonCollection.push_back(p);

}
void PokemonCollection::saveToBinaryFile(const string &filename) {

    ofstream file(filename, ios::binary);

    try{
        if (!file.is_open()) {
            throw MyException("Error: Unable to open the file for writing");
        }
    } catch (MyException &a) {
        cerr << a.what() << endl;
        QCoreApplication::quit();
    }

    size_t pokemonCount = pokemonCollection.size();
    file.write(reinterpret_cast<char *>(&pokemonCount), sizeof(size_t));

    for (const Pokemon &pokemon : pokemonCollection) {
        file.write(reinterpret_cast<const char *>(&pokemon), sizeof(Pokemon));
    }

    file.close();
}

void PokemonCollection::loadFromBinaryFile(const string &filename) {

    ifstream file(filename, ios::binary);

    try {
        if (!file.is_open()) {
            throw runtime_error("Error: Unable to open the file for reading: " + filename);
        }
    } catch (MyException &a) {
        cerr << a.what() << endl;
        QCoreApplication::quit();
    }

    pokemonCollection.clear();

    size_t pokemonCount;
    file.read(reinterpret_cast<char *>(&pokemonCount), sizeof(size_t));

    pokemonCollection.resize(pokemonCount);

    file.read(reinterpret_cast<char *>(pokemonCollection.data()), pokemonCount * sizeof(Pokemon));

    file.close();
}
int PokemonCollection::findPokemon(string value) {

    string temp = value;
    auto it = ::find(pokemonCollection.begin(), pokemonCollection.end(), temp);

    if (it != pokemonCollection.end()) {

        size_t position = distance(pokemonCollection.begin(), it);

        return static_cast<int>(position);

    } else
        return -1;
}
vector<Pokemon> &PokemonCollection::getPokemonCollection()
{
    return pokemonCollection;
}
