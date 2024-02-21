#include "Pokedex.h"
#include "PokedexSecondPage.h"
#include "PokedexPage.h"
#include "ui_Pokedex.h"
#include "ui_PokedexSecondPage.h"
PokedexSecondPage::PokedexSecondPage(QWidget *parent)
    : QDialog(parent), ui(new Ui::PokedexSecondPage) {

    ui->setupUi(this);

    QIcon icon(":/resources/resources/logo.png");
    setWindowIcon(icon);

    setFixedSize(1160, 774);

    vector<Pokemon> Collection = pokemonCollection.getPokemonCollection();

    for (int i = 14; i < 28; ++i) {

        QString selectedPokemon = QString("Pokemon%1").arg(i + 1);
        QLabel *label = findChild<QLabel *>(selectedPokemon);

        if (label && i < Collection.size()) {
            label->setText(QString::fromStdString(Collection[i].getName()));
        }
    }
}

PokedexSecondPage::~PokedexSecondPage()
{

    delete ui;

}

void PokedexSecondPage::on_CheckButton15_clicked() {

    this->hide();

    QLabel *Pokemon15 = findChild<QLabel *>("Pokemon15");
    QString name = Pokemon15->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton16_clicked() {

    this->hide();

    QLabel *Pokemon16 = findChild<QLabel *>("Pokemon16");
    QString name = Pokemon16->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton17_clicked() {

    this->hide();

    QLabel *Pokemon17 = findChild<QLabel *>("Pokemon17");
    QString name = Pokemon17->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton18_clicked() {

    this->hide();

    QLabel *Pokemon18 = findChild<QLabel *>("Pokemon18");
    QString name = Pokemon18->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton19_clicked() {

    this->hide();

    QLabel *Pokemon19 = findChild<QLabel *>("Pokemon19");
    QString name = Pokemon19->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton20_clicked() {

    this->hide();

    QLabel *Pokemon20 = findChild<QLabel *>("Pokemon20");
    QString name = Pokemon20->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton21_clicked() {

    this->hide();

    QLabel *Pokemon21 = findChild<QLabel *>("Pokemon21");
    QString name = Pokemon21->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton22_clicked() {

    this->hide();

    QLabel *Pokemon22 = findChild<QLabel *>("Pokemon22");
    QString name = Pokemon22->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton23_clicked() {

    this->hide();

    QLabel *Pokemon23 = findChild<QLabel *>("Pokemon23");
    QString name = Pokemon23->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton24_clicked() {

    this->hide();

    QLabel *Pokemon24 = findChild<QLabel *>("Pokemon24");
    QString name = Pokemon24->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton25_clicked() {

    this->hide();

    QLabel *Pokemon25 = findChild<QLabel *>("Pokemon25");
    QString name = Pokemon25->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton26_clicked() {

    this->hide();

    QLabel *Pokemon26 = findChild<QLabel *>("Pokemon26");
    QString name = Pokemon26->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton27_clicked() {

    this->hide();

    QLabel *Pokemon27 = findChild<QLabel *>("Pokemon27");
    QString name = Pokemon27->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_CheckButton28_clicked() {

    this->hide();

    QLabel *Pokemon28 = findChild<QLabel *>("Pokemon28");
    QString name = Pokemon28->text();
    PokedexPage *pokedexPage = new PokedexPage(name.toStdString(), this);

    pokedexPage->show();
}

void PokedexSecondPage::on_BackButton_clicked() {

    this->hide();

    Pokedex *pokedexPage = dynamic_cast<Pokedex *>(parentWidget());

    if (pokedexPage) {
        pokedexPage->show();
    }
}
