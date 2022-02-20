#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QDialog>
#include <QPushButton>
#include "playernum.h"

namespace Ui {
class PlayerInfo;
}

class GameWindow;
class StartWindow;

class PlayerInfo : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerInfo(QWidget *parent = nullptr);
    ~PlayerInfo();

    // player information
    // index 0 : player name , index 1: player color
    static QString p1_info[2];
    static QString p2_info[2];
    static QString p3_info[2];
    static QString p4_info[2];

public slots:
    void submit();
    void cancle();

private:
    Ui::PlayerInfo *ui;
    GameWindow *gamewindow;
    StartWindow *startwindow;
    int playercount = 1;

};

#endif // PLAYERINFO_H
