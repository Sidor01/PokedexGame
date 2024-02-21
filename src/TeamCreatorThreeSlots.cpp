#include "TeamCreatorThreeSlots.h"
#include "ui_TeamCreatorThreeSlots.h"
#include "BattleWindow.h"
Pokemon* TeamCreatorThreeSlots::team = nullptr;

TeamCreatorThreeSlots::TeamCreatorThreeSlots(int value, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TeamCreatorThreeSlots)
{
    ui->setupUi(this);

    setFixedSize(1160,774);
    QIcon icon(":/resources/resources/logo.png");

    setWindowIcon(icon);

    connect(ui->statChoiceComboBox, QOverload<int>::of(&QComboBox::activated), this, &TeamCreatorThreeSlots::onComboBoxActivated);
    connect(ui->firstPokemonComboBox, QOverload<int>::of(&QComboBox::activated), this, &TeamCreatorThreeSlots::onComboBoxActivated);
    connect(ui->secondPokemonComboBox, QOverload<int>::of(&QComboBox::activated), this, &TeamCreatorThreeSlots::onComboBoxActivated);
    connect(ui->pokemonChoiceComboBox, QOverload<int>::of(&QComboBox::activated), this, &TeamCreatorThreeSlots::onComboBoxActivated);

    if(value!=6)
    {
        ui->team4->setEnabled(false);
        ui->team5->setEnabled(false);
        ui->team6->setEnabled(false);
        ui->team4->hide();
        ui->team5->hide();
        ui->team6->hide();
    }

    teamSize = value;

    team = new Pokemon[value];

    ui->fightButton->hide();
    ui->fightButton->setEnabled(false);

    loadFromBinaryFile("team.txt");
}

TeamCreatorThreeSlots::~TeamCreatorThreeSlots()
{
    delete[] team;
    delete ui;
}

void TeamCreatorThreeSlots::on_fireTrainerCheckBox_stateChanged(int arg1)
{
    if(ui->fireTrainerCheckBox->isChecked())
    {
        ui->waterTrainerCheckBox->setEnabled(false);
        ui->grassTrainerCheckBox->setEnabled(false);

    }else
    {
        ui->waterTrainerCheckBox->setEnabled(true);
        ui->grassTrainerCheckBox->setEnabled(true);
    }
    trainerChoice = 1;
}


void TeamCreatorThreeSlots::on_waterTrainerCheckBox_stateChanged(int arg1)
{
    if(ui->waterTrainerCheckBox->isChecked())
    {
        ui->fireTrainerCheckBox->setEnabled(false);
        ui->grassTrainerCheckBox->setEnabled(false);
    }else
    {
        ui->fireTrainerCheckBox->setEnabled(true);
        ui->grassTrainerCheckBox->setEnabled(true);
    }
    trainerChoice = 2;
}


void TeamCreatorThreeSlots::on_grassTrainerCheckBox_stateChanged(int arg1)
{
    if(ui->grassTrainerCheckBox->isChecked())
    {
        ui->fireTrainerCheckBox->setEnabled(false);
        ui->waterTrainerCheckBox->setEnabled(false);
    }else
    {
        ui->fireTrainerCheckBox->setEnabled(true);
        ui->waterTrainerCheckBox->setEnabled(true);
    }
    trainerChoice = 3;
}


void TeamCreatorThreeSlots::on_compareStatsButton_clicked()
{
    vector<Pokemon>Collection = pokemonCollection.getPokemonCollection();

    QString selectedChoice = ui->statChoiceComboBox->currentText();
    QString selectedPokemonFirst = ui->firstPokemonComboBox->currentText();
    QString selectedPokemonSecond = ui->secondPokemonComboBox->currentText();

    int indexFirst = pokemonCollection.findPokemon(selectedPokemonFirst.toStdString());
    int indexSecond = pokemonCollection.findPokemon(selectedPokemonSecond.toStdString());

    if(selectedChoice == "Attack"){

        int firstStat = Collection[indexFirst].getAttack();
        int secondStat = Collection[indexSecond].getAttack();
        int result = firstStat - secondStat;

        ui->statResultLabel->setText(QString::number(result));
    }
    else if(selectedChoice == "Health"){

        int firstStat = Collection[indexFirst].getHealth();
        int secondStat = Collection[indexSecond].getHealth();
        int result = firstStat - secondStat;

        ui->statResultLabel->setText(QString::number(result));
    }
    else if(selectedChoice == "Speed"){

        int firstStat = Collection[indexFirst].getSpeed();
        int secondStat = Collection[indexSecond].getSpeed();
        int result = firstStat - secondStat;

        ui->statResultLabel->setText(QString::number(result));
    }
}
Pokemon* TeamCreatorThreeSlots::getTeam(){
    return team;
}
void TeamCreatorThreeSlots::onComboBoxActivated()
{

}

void TeamCreatorThreeSlots::on_checkStatsButton_clicked()
{
    vector<Pokemon>Collection = pokemonCollection.getPokemonCollection();
    QString selectedPokemon = ui->pokemonChoiceComboBox->currentText();
    int index = pokemonCollection.findPokemon(selectedPokemon.toStdString());

    int attackStat = Collection[index].getAttack();
    int healthStat = Collection[index].getHealth();
    int speedStat = Collection[index].getSpeed();

    ui->attackResultLabel->setText(QString::number(attackStat));
    ui->healthResultLabel->setText(QString::number(healthStat));
    ui->speedResultLabel->setText(QString::number(speedStat));
}

void TeamCreatorThreeSlots::on_teamAcceptButton_clicked()
{
    ui->fightButton->show();
    ui->fightButton->setEnabled(true);
}

void TeamCreatorThreeSlots::on_fightButton_clicked()
{
    saveToBinaryFile("team.txt");
    loadFromBinaryFile("team.txt");

    this->hide();

    BattleWindow battleWindow(teamSize,trainerChoice,team);
    battleWindow.exec();
}

void TeamCreatorThreeSlots::saveToBinaryFile(const std::string& filePath)
{
    std::ofstream saveFile(filePath, std::ios::binary);

    try{
        if(!saveFile.is_open())
            throw MyException("Error: Unable to open the file for saving");
    }
    catch (MyException &a)
    {
        cerr << a.what() << endl;
        QCoreApplication::quit();
    }

    vector<Pokemon> Collection = pokemonCollection.getPokemonCollection();

    for (int i = 0; i < teamSize; ++i) {

        QString selectedPokemon = QString("team%1").arg(i + 1);
        QComboBox* comboBox = findChild<QComboBox*>(selectedPokemon);

        if (comboBox) {

            QString selectedPokemonName = comboBox->currentText();
            int index = pokemonCollection.findPokemon(selectedPokemonName.toStdString());


            if (index != -1) {
                saveFile.write(reinterpret_cast<char*>(&Collection[index]), sizeof(Pokemon));
            }
        }
    }


    saveFile.close();
}

void TeamCreatorThreeSlots::loadFromBinaryFile(const std::string& filePath)
{
    std::ifstream inputFile(filePath, std::ios::binary);

    try{
        if(!inputFile.is_open())
        {
            throw MyException( "Error: Unable to open the file for reading ");

        }
    }
    catch (MyException &a)
    {
        cerr << a.what() << endl;
    }

    for (int i = 0; i < teamSize; ++i)
    {

        inputFile.read(reinterpret_cast<char*>(&team[i]), sizeof(Pokemon));

        std::string pokemonName = team[i].getName();
        QString comboBoxName = QString("team%1").arg(i + 1);
        QComboBox* comboBox = findChild<QComboBox*>(comboBoxName);

        if (comboBox)
        {

            int index = comboBox->findText(QString::fromStdString(pokemonName));


            if (index != -1)
            {
                comboBox->setCurrentIndex(index);
            }
        }
    }

    inputFile.close();
}


