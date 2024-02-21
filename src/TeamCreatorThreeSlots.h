/**
 * @file TeamCreatorThreeSlots.h
 * @brief Declaration of the TeamCreatorThreeSlots class.
 */
#ifndef TEAMCREATORTHREESLOTS_H
#define TEAMCREATORTHREESLOTS_H
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <QDialog>
#include <QWidget>
#include "Pokemon.h"
#include "PokemonCollection.h"

namespace Ui {
class TeamCreatorThreeSlots;
}
/**
 * @class TeamCreatorThreeSlots
 * @brief A class for creating and managing Pokémon teams.
 */
class TeamCreatorThreeSlots : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for TeamCreatorThreeSlots.
     * @param value Size of trainer's team.
     * @param parent Pointer to the parent widget.
     */
    explicit TeamCreatorThreeSlots(int value, QWidget *parent = nullptr);
    /**
     * @brief Destructor for TeamCreatorThreeSlots.
     */
    ~TeamCreatorThreeSlots();
    /**
     * @brief Getter for the Pokémon team.
     * @return Pointer to the Pokémon team.
     */
    Pokemon* getTeam();

private slots:
    /**
     * @brief Slot for handling ComboBox activation.
     */
    void onComboBoxActivated();
    /**
     * @brief Slot for handling state change of the fire trainer CheckBox.
     * @param arg1 New state.
     */
    void on_fireTrainerCheckBox_stateChanged(int arg1);
    /**
     * @brief Slot for handling state change of the water trainer CheckBox.
     * @param arg1 New state.
     */
    void on_waterTrainerCheckBox_stateChanged(int arg1);
    /**
     * @brief Slot for handling state change of the grass trainer CheckBox.
     * @param arg1 New state.
     */
    void on_grassTrainerCheckBox_stateChanged(int arg1);
    /**
     * @brief Slot for handling click event on the compare stats button.
     */
    void on_compareStatsButton_clicked();
    /**
     * @brief Slot for handling click event on the check stats button.
     */
    void on_checkStatsButton_clicked();
    /**
     * @brief Slot for handling click event on the team accept button.
     */
    void on_teamAcceptButton_clicked();
    /**
     * @brief Slot for handling click event on the fight button.
     */
    void on_fightButton_clicked();
    /**
     * @brief Save Pokémon data to a binary file.
     * @param filePath Path to the file.
     */
    void saveToBinaryFile(const std::string& filePath);
    /**
     * @brief Load Pokémon data from a binary file.
     * @param filePath Path to the file.
     */
    void loadFromBinaryFile(const std::string& filePath);

private:
    Ui::TeamCreatorThreeSlots *ui;/**< User interface object. */
    int teamSize;/**< Size of the Pokémon team. */
    int trainerChoice;/**< Trainer choice indicator. */
    static Pokemon *team;/**< Pointer to the Pokémon team. */

    PokemonCollection pokemonCollection;/**< Collection of Pokémon. */
};

#endif // TEAMCREATORTHREESLOTS_H
