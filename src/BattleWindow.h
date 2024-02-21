#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H
#include "Trainer.h"
#include "TeamCreatorThreeSlots.h"
#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
/**
 * @class BattleWindow
 * @brief Represents the battle window for the Pokemon game.
 *
 * This class is responsible for managing and displaying the battle between the user's and enemy's Pokemon teams.
 */
namespace Ui {
class BattleWindow;
}

class BattleWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the BattleWindow class.
     *
     * @param size The size of the Pokemon teams.
     * @param choice The user's choice of enemy.
     * @param userTeam Pointer to the user's Pokemon team.
     * @param parent Pointer to the parent widget.
     */
    explicit BattleWindow(int size,int choice, Pokemon* userTeam, QWidget *parent = nullptr);
    /**
     * @brief Destructor for the BattleWindow class.
     */
    ~BattleWindow();
    /**
     * @brief Calculates the remaining health after an attack.
     *
     * @tparam T The type of health and attack values.
     * @param attack The attack value.
     * @param health The current health.
     * @return The remaining health after the attack.
     */
    template<typename T>
    T damage(T attack, T health)
    {
        return health-attack;
    }
    /**
     * @brief Main loop for the battle.
     */
    void mainLoop();
    /**
     * @brief Delays and appends text to the battle window.
     *
     * @param text The text to append.
     * @param delay The delay before appending the text.
     */
    void delayAndAppend(const QString &text, int delay);

private:
    Ui::BattleWindow *ui;/**< Pointer to the UI components of the battle window. */
    int teamSize; /**< The size of the Pokemon teams. */
    int userTeamLeftPokemon;/**< The number of remaining Pokemon in the user's team. */
    int enemyTeamLeftPokemon;/**< The number of remaining Pokemon in the enemy's team. */
    double healthAfterAttack;/**< The remaining health after an attack. */
    Pokemon* userTeam;/**< Pointer to the user's Pokemon team. */
    Pokemon* enemyTeam;/**< Pointer to the enemy's Pokemon team. */
};
#endif // BATTLEWINDOW_H
