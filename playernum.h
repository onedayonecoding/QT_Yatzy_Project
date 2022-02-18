#ifndef PLAYERNUM_H
#define PLAYERNUM_H
#include <startwindow.h>
#include <QDialog>

namespace Ui {
class PlayerNum;
}

class PlayerInfo;
class StartWindow;

class PlayerNum : public QDialog
{
    Q_OBJECT
    //static int playernumber;

public:
    explicit PlayerNum(QWidget *parent = nullptr);
    ~PlayerNum();
     static int playernumber;

public slots:
    void submit();
    void cancle(){
        startwindow = new StartWindow;
        startwindow -> show();
    };

private:
    Ui::PlayerNum *ui;
    PlayerInfo *playerinfo;
    StartWindow *startwindow;
};


#endif // PLAYERNUM_H
