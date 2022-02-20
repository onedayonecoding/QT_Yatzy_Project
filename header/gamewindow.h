#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "../header/playerinfo.h"
#include <QWidget>
#include <QPushButton>
#include <QVector>

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

    //dices button
    QPushButton *dice[5];

    //dices number
    QVector <int> dicenum = {0,0,0,0,0};

    // Dices chanceselection
    bool dicechange[5]={true, true, true, true, true};

    // game turn
    int rollturn=2;
    int playerturn=1;

    //css style
    const QString buttonborder = "QPushButton {border: 3px solid}";
    const QString buttonreset = "QPushButton {border: 0px solid}";
    QString windowcolor;

    //player point
    QVector <int> P1_Point = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector <int> P2_Point = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector <int> P3_Point = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector <int> P4_Point = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector <QString> P1_Point_str = {"","","","","","","","","","","","",""};
    QVector <QString> P2_Point_str = {"","","","","","","","","","","","",""};
    QVector <QString> P3_Point_str = {"","","","","","","","","","","","",""};
    QVector <QString> P4_Point_str = {"","","","","","","","","","","","",""};

    // count true false
    bool count_bool(int num);
    bool fullhouse_bool();
    bool straight_bool(int num);


signals:
    void Send(int i);

};
#endif // GAMEWINDOW_H
