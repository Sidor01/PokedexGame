#ifndef POKEDEX_H
#define POKEDEX_H
#include "Pokemon.h"
#include "PokemonCollection.h"
#include <QDialog>
#include <QWidget>
#include <QString>
using namespace std;
namespace Ui {
class Pokedex;
}
/**
 * @brief The Pokedex class represents a dialog window for managing and
 *        displaying a collection of Pokemon.
 */
class Pokedex : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a Pokedex object.
     * @param parent The parent widget (default is nullptr).
     */
    explicit Pokedex(QWidget *parent = nullptr);
    /**
     * @brief Destructor for the Pokedex class.
     */
    ~Pokedex();

    int argument; /**< An integer member variable. */
    /**
     * @brief Loads labels for the Pokemon collection.
     */
    void loadLabels();

private slots:
    /**
     * @brief Slot functions called when checkButton1-14 are clicked.
     */

    void on_checkButton1_clicked();

    void on_checkButton2_clicked();

    void on_checkButton3_clicked();

    void on_checkButton4_clicked();

    void on_checkButton5_clicked();

    void on_checkButton6_clicked();

    void on_checkButton7_clicked();

    void on_checkButton8_clicked();

    void on_checkButton9_clicked();

    void on_checkButton10_clicked();

    void on_checkButton11_clicked();

    void on_checkButton12_clicked();

    void on_checkButton13_clicked();

    void on_checkButton14_clicked();
    /**
     * @brief Slot function called when nextPageButton is clicked.
     */
    void on_nextPageButton_clicked();
    /**
     * @brief Slot function called when backButton is clicked.
     */
    void on_backButton_clicked();


private:
    Ui::Pokedex *ui;/**< The user interface for the Pokedex. */
    PokemonCollection pokemonCollection;/**< The collection of Pokemon. */
};
#endif // POKEDEX_H
