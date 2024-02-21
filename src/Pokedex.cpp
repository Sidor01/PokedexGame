#include "MainWindow.h"
#include "Pokedex.h"
#include "ui_Pokedex.h"
#include "PokedexPage.h"
#include "PokedexSecondPage.h"

using namespace std;

Pokedex::Pokedex(QWidget *parent) : QDialog(parent), ui(new Ui::Pokedex) {

    ui->setupUi(this);

    setFixedSize(1160, 774);

    QIcon icon(":/resources/resources/logo.png");
    setWindowIcon(icon);
}

Pokedex::~Pokedex()
{
    delete ui;
}

void Pokedex::loadLabels() {

    vector<Pokemon> Collection = pokemonCollection.getPokemonCollection();

    for (int i = 0; i < 14; ++i) {

        QString selectedPokemon = QString("pokemon%1").arg(i + 1);
        QLabel *label = findChild<QLabel *>(selectedPokemon);

        if (label && i < Collection.size()) {
            label->setText(QString::fromStdString(Collection[i].getName()));

        }
    }
}

void Pokedex::on_checkButton1_clicked() {

    this->hide();

    QLabel *pokemon1 = findChild<QLabel *>("pokemon1");
    QString name = pokemon1->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void Pokedex::on_checkButton2_clicked() {

    this->hide();

    QLabel *pokemon2 = findChild<QLabel *>("pokemon2");
    QString name = pokemon2->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton3_clicked() {

    this->hide();

    QLabel *pokemon3 = findChild<QLabel *>("pokemon3");
    QString name = pokemon3->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton4_clicked() {

    this->hide();

    QLabel *pokemon4 = findChild<QLabel *>("pokemon4");
    QString name = pokemon4->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton5_clicked() {

    this->hide();

    QLabel *pokemon5 = findChild<QLabel *>("pokemon5");
    QString name = pokemon5->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton6_clicked() {

    this->hide();

    QLabel *pokemon6 = findChild<QLabel *>("pokemon6");
    QString name = pokemon6->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton7_clicked() {

    this->hide();

    QLabel *pokemon7 = findChild<QLabel *>("pokemon7");
    QString name = pokemon7->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton8_clicked() {

    this->hide();

    QLabel *pokemon8 = findChild<QLabel *>("pokemon8");
    QString name = pokemon8->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton9_clicked() {

    this->hide();

    QLabel *pokemon9 = findChild<QLabel *>("pokemon9");
    QString name = pokemon9->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton10_clicked() {

    this->hide();

    QLabel *pokemon10 = findChild<QLabel *>("pokemon10");
    QString name = pokemon10->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton11_clicked() {

    this->hide();

    QLabel *pokemon11 = findChild<QLabel *>("pokemon11");
    QString name = pokemon11->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton12_clicked() {

    this->hide();

    QLabel *pokemon12 = findChild<QLabel *>("pokemon12");
    QString name = pokemon12->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton13_clicked() {

    this->hide();

    QLabel *pokemon13 = findChild<QLabel *>("pokemon13");
    QString name = pokemon13->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_checkButton14_clicked() {

    this->hide();

    QLabel *pokemon14 = findChild<QLabel *>("pokemon14");
    QString name = pokemon14->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();

}

void Pokedex::on_nextPageButton_clicked() {

    this->hide();

    PokedexSecondPage *pokedexSecond = new PokedexSecondPage(this);

    pokedexSecond->show();
}

void Pokedex::on_backButton_clicked() {

    MainWindow *mainWindow = new MainWindow(argument, this);

    mainWindow->show();

    this->hide();
}
