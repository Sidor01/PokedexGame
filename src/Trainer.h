/**
 * @file Trainer.h
 * @brief Declaration of the Trainer class.
 */
#ifndef TRAINER_H
#define TRAINER_H

#include <QCoreApplication>
#include "Pokemon.h"
#include "PokemonCollection.h"

/**
 * @brief The Trainer class represents a generic Pokémon trainer.
 */

class Trainer
{
protected:

    Pokemon *team; ///< Pointer to the Pokémon team.
public:

    /**
     * @brief Constructor for the Trainer class.
     * @param value Size of trainer's team.
     */

    Trainer(int value);

    /**
     * @brief Virtual destructor for the Trainer class.
     */

    virtual ~Trainer();

    /**
     * @brief Virtual function to set the Pokémon team.
     */

    virtual void setTeam();

    /**
     * @brief Get the size of the Pokémon team.
     * @return The size of the team.
     */

    int getTeamSize();

    /**
     * @brief Virtual function to get the Pokémon team.
     * @return Pointer to the Pokémon team.
     */

    virtual Pokemon* getTeam();

    int teamSize; ///< Size of the Pokémon team.

    PokemonCollection pokemonCollection; ///< Collection of Pokémon available for the trainer.

};
/**
 * @brief The FireTrainer class represents a Pokémon trainer specializing in Fire-type Pokémon.
 */
class FireTrainer : public Trainer {
private:
    Pokemon *fireTeam; ///< Pointer to the Fire-type Pokémon team.
public:
    /**
     * @brief Constructor for the FireTrainer class.
     * @param value Size of trainer's team.
     */
    FireTrainer(int value);

    /**
     * @brief Destructor for the FireTrainer class.
     */

    ~FireTrainer();

    /**
     * @brief Overrides the setTeam method to set the Fire-type Pokémon team.
     */

    void setTeam() override;

    /**
     * @brief Overrides the getTeam method to get the Fire-type Pokémon team.
     * @return Pointer to the Fire-type Pokémon team.
     */

    Pokemon* getTeam() override;
};
/**
 * @brief The WaterTrainer class represents a Pokémon trainer specializing in Water-type Pokémon.
 */

class WaterTrainer : public Trainer {
private:
    Pokemon *waterTeam; ///< Pointer to the Water-type Pokémon team.
public:
    /**
     * @brief Constructor for the WaterTrainer class.
     * @param value Size of trainer's team.
     */
    WaterTrainer(int value);
    /**
     * @brief Destructor for the WaterTrainer class.
     */
    ~WaterTrainer();
    /**
     * @brief Overrides the setTeam method to set the Water-type Pokémon team.
     */
    void setTeam() override;
    /**
     * @brief Overrides the getTeam method to get the Water-type Pokémon team.
     * @return Pointer to the Water-type Pokémon team.
     */
    Pokemon* getTeam() override;
};
/**
 * @brief The GrassTrainer class represents a Pokémon trainer specializing in Grass-type Pokémon.
 */
class GrassTrainer : public Trainer {
private:

    Pokemon *grassTeam; ///< Pointer to the Grass-type Pokémon team.
public:
    /**
     * @brief Constructor for the GrassTrainer class.
     * @param value Size of trainer's team.
     */
    GrassTrainer(int value);
    /**
     * @brief Destructor for the GrassTrainer class.
     */
    ~GrassTrainer();
    /**
     * @brief Overrides the setTeam method to set the Grass-type Pokémon team.
     */
    void setTeam() override;
    /**
     * @brief Overrides the getTeam method to get the Grass-type Pokémon team.
     * @return Pointer to the Grass-type Pokémon team.
     */
    Pokemon* getTeam() override;

};

#endif // TRAINER_H
