#include "BattleWindow.h"
#include "ui_BattleWindow.h"
#include <iostream>
BattleWindow::BattleWindow(int size, int choice, Pokemon *userTeam, QWidget *parent) : QDialog(parent), ui(new Ui::BattleWindow) {
    ui->setupUi(this);

    setFixedSize(1160, 662);
    QIcon icon(":/resources/resources/logo.png");
    setWindowIcon(icon);
    QPixmap pix(":/resources/resources/battleBackground.png");
    ui->backgroundImage->setPixmap(pix.scaled(this->size(), Qt::KeepAspectRatio));

    teamSize = size;

    enemyTeam = new Pokemon[size];
    this->userTeam = new Pokemon[size];

    for (int i = 0; i < teamSize; ++i) {
        this->userTeam[i] = Pokemon(userTeam[i]);
    }

    Trainer *trainer = nullptr;
    Pokemon *trainerTeam = nullptr;

    switch (choice) {
    case 1:
        trainer = new FireTrainer(size);
        break;
    case 2:
        trainer = new WaterTrainer(size);
        break;
    case 3:
        trainer = new GrassTrainer(size);
        break;
    default:
        trainer = new Trainer(size);
        break;
    }
    trainer->setTeam();
    trainerTeam = trainer->getTeam();

    for (int i = 0; i < teamSize; ++i) {
        enemyTeam[i] = Pokemon(trainerTeam[i]);
    }
    delete trainer;

    mainLoop();
}
BattleWindow::~BattleWindow() {
    delete ui;
    delete[] userTeam;
    delete[] enemyTeam;
}
void BattleWindow::mainLoop() {
    bool enemyTurn = true;

    ui->hpBar1->setRange(0, userTeam[0].getHealth());

    ui->hpBar2->setRange(0, enemyTeam[0].getHealth());

    ui->hpBar1->setValue(userTeam[0].getHealth());

    ui->hpBar2->setValue(enemyTeam[0].getHealth());

    ui->userPokemonHp->setText(QString::number(userTeam[0].getHealth()) + "/" + QString::number(userTeam[0].getHealth()));

    ui->enemyPokemonHp->setText(QString::number(enemyTeam[0].getHealth()) + "/" + QString::number(enemyTeam[0].getHealth()));

    ui->userPokemonName->setText(QString::fromStdString(userTeam[0].getName()));

    ui->enemyPokemonName->setText(QString::fromStdString(enemyTeam[0].getName()));

    delayAndAppend("Welcome to PKMN Battle!", 1000);

    delayAndAppend("Your team: ", 2000);
    for (int i = teamSize-1; i >=0; i--) {
        delayAndAppend(QString::fromStdString(userTeam[i].getName()), 3000);
    }

    delayAndAppend("Enemy team: ", 4000);
    for (int i = teamSize-1; i >=0; i--) {
        delayAndAppend(QString::fromStdString(enemyTeam[i].getName()), 5000);
    }

    delayAndAppend("Your first pokemon: ", 6000);
    delayAndAppend(QString::fromStdString(userTeam[0].getName()), 7000);

    delayAndAppend("Enemy first pokemon: ", 8000);
    delayAndAppend(QString::fromStdString(enemyTeam[0].getName()), 9000);

    int latency = 10000;
    int userPokemonsLeft = teamSize;
    int enemyPokemonsLeft = teamSize;
    int currentUserPokemon = 0;
    int currentEnemyPokemon = 0;

    double currentUserPokemonHealth = userTeam[currentUserPokemon].getHealth();
    double currentEnemyPokemonHealth = enemyTeam[currentEnemyPokemon].getHealth();
    double currentUserPokemonAttack = userTeam[currentUserPokemon].getAttack();
    double currentEnemyPokemonAttack = enemyTeam[currentEnemyPokemon].getAttack();

    delayAndAppend("Current user Pokemon health: ", latency);
    latency = latency + 1000;
    delayAndAppend(QString::number(currentUserPokemonHealth), latency);
    latency = latency + 1000;
    delayAndAppend("Current enemy Pokemon health: ", latency);
    latency = latency + 1000;
    delayAndAppend(QString::number(currentEnemyPokemonHealth), latency);
    latency = latency + 1000;

    if (userTeam[0].getSpeed() >= enemyTeam[0].getSpeed()) {
        delayAndAppend("Your Pokemon is faster so you start the battle! ", latency);
        latency = latency + 1000;
        healthAfterAttack = damage<double>(userTeam[0].getAttack(), enemyTeam[0].getHealth());
        delayAndAppend("Your Pokemon attacks! ", latency);
        latency = latency + 1000;
        currentEnemyPokemonHealth = healthAfterAttack;

        delayAndAppend("Current user Pokemon health affter attack: ", latency);
        latency = latency + 1000;
        delayAndAppend(QString::number(currentUserPokemonHealth), latency);
        latency = latency + 1000;
        delayAndAppend("Current enemy Pokemon health after attack: ", latency);
        latency = latency + 1000;
        delayAndAppend(QString::number(currentEnemyPokemonHealth), latency);
        latency = latency + 1000;

        QTimer::singleShot(latency, this, [=]() {
            ui->hpBar2->setValue(currentEnemyPokemonHealth);
            ui->enemyPokemonHp->setText(QString::number(currentEnemyPokemonHealth) + "/" + QString::number(enemyTeam[currentEnemyPokemon].getHealth()));
        });
        latency = latency + 1000;

    } else {
        delayAndAppend("Enemy Pokemon is faster so he starts the battle! ", latency);
        latency = latency + 1000;
        enemyTurn = false;
        healthAfterAttack = damage<double>(enemyTeam[0].getAttack(), userTeam[0].getHealth());
        delayAndAppend("Enemy Pokemon attacks! ", latency);
        latency = latency + 1000;
        currentUserPokemonHealth = healthAfterAttack;

        delayAndAppend("Current user Pokemon health affter attack: ", latency);
        latency = latency + 1000;
        delayAndAppend(QString::number(currentUserPokemonHealth), latency);
        latency = latency + 1000;
        delayAndAppend("Current enemy Pokemon health after attack: ", latency);
        latency = latency + 1000;
        delayAndAppend(QString::number(currentEnemyPokemonHealth), latency);
        latency = latency + 1000;

        QTimer::singleShot(latency, this, [=]() {
            ui->hpBar1->setValue(currentUserPokemonHealth);
            ui->userPokemonHp->setText(QString::number(currentUserPokemonHealth) + "/" + QString::number(userTeam[currentUserPokemon].getHealth()));
        });
        latency = latency + 1000;
    }

    bool userDied = false;
    bool enemyDied = false;
    int userIterator = 1;
    int enemyIterator = 1;
    while (userPokemonsLeft > 0 && enemyPokemonsLeft > 0) {

        while (true) {
            if (userDied == true) {
                currentUserPokemonHealth = userTeam[currentUserPokemon + userIterator].getHealth();
                currentUserPokemonAttack = userTeam[currentUserPokemon + userIterator].getAttack();

                QTimer::singleShot(latency, this, [=]() {
                    ui->userPokemonName->setText(QString::fromStdString(userTeam[currentUserPokemon + userIterator].getName()));
                    ui->hpBar1->setRange(0, userTeam[currentUserPokemon + userIterator].getHealth());
                    ui->hpBar1->setValue(userTeam[currentUserPokemon + userIterator].getHealth());
                    ui->userPokemonHp->setText(QString::number(userTeam[currentUserPokemon + userIterator].getHealth()) + "/" + QString::number(userTeam[currentUserPokemon + userIterator].getHealth()));
                });
                latency = latency + 1000;
                userIterator++;
                userDied = false;
            }
            if (enemyDied == true) {
                currentEnemyPokemonHealth = enemyTeam[currentEnemyPokemon + enemyIterator].getHealth();
                currentEnemyPokemonAttack = enemyTeam[currentEnemyPokemon + enemyIterator].getAttack();
                QTimer::singleShot(latency, this, [=]() {
                    ui->enemyPokemonName->setText(QString::fromStdString(enemyTeam[currentEnemyPokemon + enemyIterator].getName()));
                    ui->hpBar2->setRange(0, enemyTeam[currentEnemyPokemon + enemyIterator].getHealth());
                    ui->hpBar2->setValue(enemyTeam[currentEnemyPokemon + enemyIterator].getHealth());
                    ui->enemyPokemonHp->setText(QString::number(enemyTeam[currentEnemyPokemon + enemyIterator].getHealth()) + "/" + QString::number(enemyTeam[currentEnemyPokemon + enemyIterator].getHealth()));
                });
                latency = latency + 1000;

                enemyIterator++;
                enemyDied = false;
            }
            if (enemyTurn) {

                delayAndAppend("Enemy Pokemon attacks! ", latency);
                latency = latency + 1000;

                healthAfterAttack = damage<double>(currentEnemyPokemonAttack, currentUserPokemonHealth);
                currentUserPokemonHealth = healthAfterAttack;

                delayAndAppend("Current user Pokemon health affter attack: ", latency);
                latency = latency + 1000;
                delayAndAppend(QString::number(currentUserPokemonHealth), latency);
                latency = latency + 1000;
                delayAndAppend("Current enemy Pokemon health after attack: ", latency);
                latency = latency + 1000;
                delayAndAppend(QString::number(currentEnemyPokemonHealth), latency);
                latency = latency + 1000;

                QTimer::singleShot(latency, this, [=]() {
                    ui->hpBar1->setValue(currentUserPokemonHealth);
                    ui->userPokemonHp->setText(QString::number(currentUserPokemonHealth) + "/" + QString::number(userTeam[currentUserPokemon].getHealth()));
                });
                latency = latency + 1000;

                if (currentUserPokemonHealth < 1) {

                    delayAndAppend("Your pokemon has died...", latency);
                    latency = latency + 1000;
                    QTimer::singleShot(latency, this, [=]() {
                        ui->hpBar1->setValue(0);

                    });
                    latency = latency + 1000;
                    userPokemonsLeft--;
                    userDied = true;
                    // Poprawienie wyświetlanego tekstu

                    delayAndAppend("User pokemons left: ", latency);
                    latency = latency + 1000;

                    delayAndAppend(QString::number(userPokemonsLeft), latency);
                    latency = latency + 1000;

                    if (userPokemonsLeft > 0) {
                        delayAndAppend("Your next pokemon is: ", latency);
                        latency = latency + 1000;
                    }
                    delayAndAppend(QString::fromStdString(userTeam[currentUserPokemon + 1].getName()), latency);
                    latency = latency + 1000;
                    enemyTurn = !enemyTurn;
                    break;
                }
            } else {

                delayAndAppend("Your Pokemon attacks! ", latency);
                latency = latency + 1000;

                healthAfterAttack = damage<double>(currentUserPokemonAttack, currentEnemyPokemonHealth);
                currentEnemyPokemonHealth = healthAfterAttack;

                delayAndAppend("Current user Pokemon health affter attack: ", latency);
                latency = latency + 1000;
                delayAndAppend(QString::number(currentUserPokemonHealth), latency);
                latency = latency + 1000;
                delayAndAppend("Current enemy Pokemon health after attack: ", latency);
                latency = latency + 1000;
                delayAndAppend(QString::number(currentEnemyPokemonHealth), latency);
                latency = latency + 1000;

                QTimer::singleShot(latency, this, [=]() {
                    ui->hpBar2->setValue(currentEnemyPokemonHealth);
                    ui->enemyPokemonHp->setText(QString::number(currentEnemyPokemonHealth) + "/" + QString::number(enemyTeam[currentEnemyPokemon].getHealth()));
                });
                latency = latency + 1000;

                if (currentEnemyPokemonHealth < 1) {

                    delayAndAppend("Enemy pokemon has died!", latency);
                    latency = latency + 1000;

                    QTimer::singleShot(latency, this, [=]() {
                        ui->hpBar2->setValue(0);

                    });
                    latency = latency + 1000;

                    enemyPokemonsLeft--;
                    enemyDied = true;

                    delayAndAppend("Enemy pokemons left: ", latency);
                    latency = latency + 1000;

                    delayAndAppend(QString::number(enemyPokemonsLeft), latency);
                    latency = latency + 1000;

                    if (enemyPokemonsLeft > 0) {
                        delayAndAppend("Enemy next pokemon is: ", latency);
                        latency = latency + 1000;
                    }
                    delayAndAppend(QString::fromStdString(enemyTeam[currentEnemyPokemon + 1].getName()), latency);
                    latency = latency + 1000;
                    enemyTurn = !enemyTurn;
                    break;
                }
            }

            enemyTurn = !enemyTurn;
        }
    }

    if (userPokemonsLeft > 0) {
        delayAndAppend("You won the battle! ", latency);
        latency = latency + 1000;
        delayAndAppend("Pokemons left: ", latency);
        latency = latency + 1000;
        delayAndAppend(QString::number(userPokemonsLeft), latency);
    } else {
        delayAndAppend("Enemy won the battle... ", latency);
        latency = latency + 1000;
        delayAndAppend("Enemy pokemons left: ", latency);
        latency = latency + 1000;
        delayAndAppend(QString::number(enemyPokemonsLeft), latency);
    }
}

void BattleWindow::delayAndAppend(const QString &text, int delay) {
    QTimer::singleShot(delay, this, [this, text]() { ui->battleLog->append(text); });
}
