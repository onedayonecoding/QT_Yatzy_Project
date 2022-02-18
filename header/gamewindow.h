#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "../header/playerinfo.h"
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class StartWindow;

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

public slots:
   void init();

   void clickStartWindow();
   void changewindowcolor();

   void clickScore();
   void clickRoll();

   void clickdice1();
   void clickdice2();
   void clickdice3();
   void clickdice4();
   void clickdice5();

private:
    Ui::GameWindow *ui;
    StartWindow *startwindow;

    //dices number
    QString dicenum1;
    QString dicenum2;
    QString dicenum3;
    QString dicenum4;
    QString dicenum5;

    // Dices chanceselection
    bool dicechange1=true;
    bool dicechange2=true;
    bool dicechange3=true;
    bool dicechange4=true;
    bool dicechange5=true;

    // game turn
    int rollturn=2;
    int playerturn=1;

    //css style
    QString buttonborder = "QPushButton {border: 3px solid}";
    QString buttonreset = "QPushButton {border: 0px solid}";
    QString windowcolor;
};
#endif // GAMEWINDOW_H
