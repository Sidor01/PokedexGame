#ifndef POKEDEXSECONDPAGE_H
#define POKEDEXSECONDPAGE_H
#include <QDialog>
#include "PokemonCollection.h"
namespace Ui {
class PokedexSecondPage;
}
/**
 * @class PokedexSecondPage
 * @brief Represents the second page of the Pokedex application.
 *
 * This class is responsible for displaying a subset of Pokemon and allowing the user
 * to interact with them.
 */
class PokedexSecondPage : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for PokedexSecondPage class.
     * @param parent The parent widget.
     */
    explicit PokedexSecondPage(QWidget *parent = nullptr);
    /**
     * @brief Destructor for PokedexSecondPage class.
     */
    ~PokedexSecondPage();

private slots:
    /**
     * @brief Slots for handling the click event of CheckButton15-28.
     */
    void on_CheckButton15_clicked();

    void on_CheckButton16_clicked();

    void on_CheckButton17_clicked();

    void on_CheckButton18_clicked();

    void on_CheckButton19_clicked();

    void on_CheckButton20_clicked();

    void on_CheckButton21_clicked();

    void on_CheckButton22_clicked();

    void on_CheckButton23_clicked();

    void on_CheckButton24_clicked();

    void on_CheckButton25_clicked();

    void on_CheckButton26_clicked();

    void on_CheckButton27_clicked();

    void on_CheckButton28_clicked();
    /**
     * @brief Slot for handling the click event of BackButton.
     */
    void on_BackButton_clicked();

private:
    Ui::PokedexSecondPage *ui; /**< The user interface for the second page of the Pokedex. */
    PokemonCollection pokemonCollection; /**< The collection of Pokemon for the Pokedex. */
};

#endif // POKEDEXSECONDPAGE_H
