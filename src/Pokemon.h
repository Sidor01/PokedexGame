#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <QString>
using namespace std;
/**
 * @class Pokemon
 * @brief Represents a Pokemon with various attributes.
 */
class Pokemon
{
private:
    string name;/**< The name of the Pokemon. */
    int attack; /**< The attack stat of the Pokemon. */
    int speed;/**< The speed stat of the Pokemon. */
    int health;/**< The health stat of the Pokemon. */
    QString type;/**< The primary type of the Pokemon. */
    QString secondType;/**< The secondary type of the Pokemon. */
    QString description; /**< A brief description of the Pokemon. */
public:
    /**
     * @brief Default constructor for the Pokemon class.
     */
    Pokemon();
    /**
     * @brief Parameterized constructor for the Pokemon class.
     * @param name The name of the Pokemon.
     * @param attack The attack stat of the Pokemon.
     * @param speed The speed stat of the Pokemon.
     * @param health The health stat of the Pokemon.
     * @param type The primary type of the Pokemon.
     * @param description A brief description of the Pokemon.
     */
    Pokemon(string,int,int,int,QString,QString);
    /**
     * @brief Parameterized constructor for the Pokemon class with a second type.
     * @param name The name of the Pokemon.
     * @param attack The attack stat of the Pokemon.
     * @param speed The speed stat of the Pokemon.
     * @param health The health stat of the Pokemon.
     * @param type The primary type of the Pokemon.
     * @param secondType The secondary type of the Pokemon.
     * @param description A brief description of the Pokemon.
     */
    Pokemon(string,int,int,int,QString,QString,QString);
    /**
     * @brief Copy constructor for the Pokemon class.
     * @param otherPokemon The Pokemon object to be copied.
     */
    Pokemon(const Pokemon& otherPokemon);
    /**
     * @brief Set the name of the Pokemon.
     * @param name The name to set.
     */
    void setName(string);
    /**
     * @brief Set the attack stat of the Pokemon.
     * @param attack The attack stat to set.
     */
    void setAttack(int);
    /**
     * @brief Set the speed stat of the Pokemon.
     * @param speed The speed stat to set.
     */
    void setSpeed(int);
    /**
     * @brief Set the health stat of the Pokemon.
     * @param health The health stat to set.
     */
    void setHealth(int);
    /**
     * @brief Set the primary type of the Pokemon.
     * @param type The primary type to set.
     */
    void setType(QString);
    /**
     * @brief Set the primary and secondary types of the Pokemon.
     * @param type The primary type to set.
     * @param secondType The secondary type to set.
     */
    void setType(QString,QString);
    /**
     * @brief Set the description of the Pokemon.
     * @param description The description to set.
     */
    void setDescription(QString);
    /**
     * @brief Get the name of the Pokemon.
     * @return The name of the Pokemon.
     */
    string getName();
    /**
     * @brief Get the attack stat of the Pokemon.
     * @return The attack stat of the Pokemon.
     */
    int getAttack();
    /**
     * @brief Get the speed stat of the Pokemon.
     * @return The speed stat of the Pokemon.
     */
    int getSpeed();
    /**
     * @brief Get the health stat of the Pokemon.
     * @return The health stat of the Pokemon.
     */
    int getHealth();
    /**
     * @brief Get the primary type of the Pokemon.
     * @return The primary type of the Pokemon.
     */
    QString getFirstType();
    /**
     * @brief Get the secondary type of the Pokemon.
     * @return The secondary type of the Pokemon.
     */
    QString getSecondType();
    /**
     * @brief Get the description of the Pokemon.
     * @return The description of the Pokemon.
     */
    QString getDescription();
    /**
     * @brief Equality operator for comparing a Pokemon object with a string.
     * @param temp The string to compare with.
     * @return True if the Pokemon's name is equal to the provided string, false otherwise.
     */
    bool operator==(string temp);
    int statToCheck;/**< The stat to check. */
};

#endif // POKEMON_H
