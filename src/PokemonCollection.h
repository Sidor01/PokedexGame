#ifndef POKEMONCOLLECTION_H
#define POKEMONCOLLECTION_H
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <QCoreApplication>
#include "MyException.h"
/**
 * @class PokemonCollection
 * @brief A class representing a collection of Pokemon.
 *
 * This class provides functionality to manage and manipulate a collection of Pokemon.
 */
class PokemonCollection
{
    static vector<Pokemon> pokemonCollection; /**< A static vector to store the collection of Pokemon. */


public:
    /**
     * @brief Default constructor for PokemonCollection.
     */
    PokemonCollection();
    /**
     * @brief Adds a Pokemon to the collection.
     *
     * @param p The Pokemon to be added.
     */
    void addPokemon(const Pokemon &p);
    /**
     * @brief Loads Pokemon data from a binary file.
     *
     * @param filename The name of the binary file to load data from.
     * @throw MyException if there is an error during file loading.
     */
    void loadFromBinaryFile(const std::string& filename);
    /**
     * @brief Saves Pokemon data to a binary file.
     *
     * @param filename The name of the binary file to save data to.
     * @throw MyException if there is an error during file saving.
     */
    void saveToBinaryFile(const std::string& filename);
    /**
     * @brief Finds a Pokemon in the collection based on a specified value.
     *
     * @param value The value to search for within the Pokemon collection.
     * @return The index of the found Pokemon, or -1 if not found.
     */
    int findPokemon(string value);
    /**
     * @brief Gets a reference to the Pokemon collection.
     *
     * @return A reference to the internal Pokemon collection vector.
     */
    vector<Pokemon>& getPokemonCollection();
};

#endif // POKEMONCOLLECTION_H
