#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QWebEngineView>


QT_BEGIN_NAMESPACE
namespace Ui { class StartWindow; }
QT_END_NAMESPACE

class GameWindow;
class PlayerNum;
class PlayerInfo;

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();


public slots :
    void clickSolo();
    void clickSeveral();


private:
    Ui::StartWindow *ui;
    GameWindow *gamewindow;
    PlayerNum *playernum;
    QWebEngineView *rollbook;
    PlayerInfo *playerinfo;
};
#endif // STARTWINDOW_H
