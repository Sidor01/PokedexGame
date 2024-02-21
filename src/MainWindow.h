#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Pokedex.h"
#include "TeamCreatorThreeSlots.h"
#include <QMainWindow>
/**
 * @brief The MainWindow class represents the main application window.
 */

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the MainWindow class.
     * @param value An integer value.
     * @param pokedex A pointer to the Pokedex object.
     * @param parent The parent QWidget.
     */
    MainWindow(int value, Pokedex * pokedex, QWidget *parent = nullptr);
    /**
     * @brief Destructor for the MainWindow class.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Slot function for handling the "Pokedex" button click.
     */
    void on_pokedexButton_clicked();
    /**
     * @brief Slot function for handling the "Team Creator" button click.
     */
    void on_teamCreatorButton_clicked();


private:
    Ui::MainWindow *ui; ///< The user interface for the main window.
    int argument; ///< An integer argument.
    Pokedex* pokedex; ///< A pointer to the Pokedex object.
    TeamCreatorThreeSlots *CreatorThreeWindow; ///< A pointer to the TeamCreatorThreeSlots window.
};
#endif
