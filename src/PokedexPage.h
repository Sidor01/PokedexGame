#ifndef POKEDEXPAGE_H
#define POKEDEXPAGE_H
#include "Pokemon.h"
#include "PokemonCollection.h"
#include <QDialog>
namespace Ui {
class PokedexPage;
}
/**
 * @brief The PokedexPage class represents a dialog window for displaying
 *        information about a specific Pokemon and its collection.
 */
class PokedexPage : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a PokedexPage object with the specified Pokemon name.
     * @param name The name of the Pokemon to be displayed.
     * @param parent The parent widget (default is nullptr).
     */
    explicit PokedexPage(std::string name,QWidget *parent = nullptr);
    /**
     * @brief Destructor for the PokedexPage class.
     */
    ~PokedexPage();

private slots:
    /**
     * @brief Slot function called when the back button is clicked.
     */
    void on_backButton_clicked();

private:
    Ui::PokedexPage *ui;/**< The user interface for the PokedexPage. */
    Pokemon pokemon;  /**< The Pokemon object associated with the page. */
    PokemonCollection pokemonCollection;/**< The collection of Pokemon. */
};

#endif // POKEDEXPAGE_H
