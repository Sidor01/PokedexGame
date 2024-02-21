#include "./ui_MainWindow.h"
#include "MainWindow.h"
MainWindow::MainWindow(int value, Pokedex *pokedex, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    setFixedSize(966, 668);

    argument = value;

    this->pokedex = pokedex;
    pokedex->argument = argument;

    CreatorThreeWindow = new TeamCreatorThreeSlots(argument);

    QIcon icon(":/resources/resources/logo.png");
    setWindowIcon(icon);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pokedexButton_clicked() {

    this->hide();
    pokedex->show();

}

void MainWindow::on_teamCreatorButton_clicked() {

    this->hide();
    CreatorThreeWindow->show();

}
