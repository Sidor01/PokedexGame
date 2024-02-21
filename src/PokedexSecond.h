#ifndef POKEDEXSECOND_H
#define POKEDEXSECOND_H
#include "Pokemon.h"
#include "PokedexPage.h"
#include "PokemonCollection.h"
#include <QDialog>
#include <iostream>
#include <QWidget>
#include <QString>
using namespace std;
namespace Ui {
class Pokedex;
}

class Pokedex : public QDialog
{
    Q_OBJECT

public:
    explicit Pokedex(QWidget *parent = nullptr);
    ~Pokedex();

    void backButtonClicked();

    void loadLabels();

private slots:

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

    void on_nextPageButton_clicked();

private:
    Ui::Pokedex *ui;
    PokemonCollection pokemonCollection;
};
#endif // POKEDEXSECOND_H
