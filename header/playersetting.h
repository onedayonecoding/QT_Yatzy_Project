#ifndef PLAYERSETTING_H
#define PLAYERSETTING_H

#include <QDialog>
#include <QPushButton>
#include "playernum.h"

namespace Ui {
class PlayerSetting;
}

class GameWindow;
class StartWindow;

class PlayerSetting : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerSetting(QWidget *parent = nullptr);
    ~PlayerSetting();

    // player information
    // index 0 : player name , index 1: player color
    QString p1_info[2];
    QString p2_info[2];
    QString p3_info[2];
    QString p4_info[2];

public slots:
    void submit();
    void cancle();

private:
    Ui::PlayerSetting *ui;
    GameWindow *gamewindow;
    StartWindow *startwindow;
    int playercount = 1;

};

#endif // PLAYERSETTING_H
