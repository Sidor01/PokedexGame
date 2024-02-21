#include "Pokedex.h"
#include "PokedexPage.h"
#include "PokedexSecondPage.h"
#include "ui_PokedexPage.h"
PokedexPage::PokedexPage(std::string name, QWidget *parent)
    : QDialog(parent), ui(new Ui::PokedexPage) {

    ui->setupUi(this);

    setFixedSize(1160, 774);

    QIcon icon(":/resources/resources/logo.png");
    setWindowIcon(icon);

    QPushButton *backButton = findChild<QPushButton *>("backButton");
    if (backButton) {
        connect(backButton, &QPushButton::clicked, this, &PokedexPage::on_backButton_clicked);
    }

    vector<Pokemon> Collection = pokemonCollection.getPokemonCollection();
    int index = pokemonCollection.findPokemon(name);
    pokemon = Collection[index];

    std::string pokemonName = pokemon.getName();
    ui->nameText->setText(QString::fromStdString(pokemonName));

    int pokemonAttack = pokemon.getAttack();
    ui->attackText->setText(QString::number(pokemonAttack));

    int pokemonHealth = pokemon.getHealth();
    ui->healthText->setText(QString::number(pokemonHealth));

    int pokemonSpeed = pokemon.getSpeed();
    ui->speedText->setText(QString::number(pokemonSpeed));

    QString pokemonType = pokemon.getFirstType();
    ui->typeText->setText(pokemonType);

    QString pokemonSecondType = pokemon.getSecondType();
    ui->secondTypeText->setText(pokemonSecondType);

    QString pokemonDescription = pokemon.getDescription();
    ui->descriptionText->setText(pokemonDescription);
    ui->descriptionText->setWordWrap(true);
}

PokedexPage::~PokedexPage()
{
    delete ui;

}

void PokedexPage::on_backButton_clicked() {

    this->hide();

    QWidget *parentWidget = this->parentWidget();

    if (parentWidget) {

        Pokedex *pokedex = qobject_cast<Pokedex *>(parentWidget);
        PokedexSecondPage *pokedexSecond = qobject_cast<PokedexSecondPage *>(parentWidget);

        if (pokedex) {

            pokedex->show();

        } else if (pokedexSecond) {

            pokedexSecond->show();

        }
    }
}
