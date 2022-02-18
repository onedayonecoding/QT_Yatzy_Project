#include "startwindow.h"
#include "ui_startwindow.h"
#include "gamewindow.h"
#include "playernum.h"


#include <QWidget>
#include <QPushButton>
#include <QWebEngineView>

StartWindow::StartWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    gamewindow = new GameWindow;
    playernum = new PlayerNum;
    rollbook = new QWebEngineView;

    connect(ui->solo_button,SIGNAL(clicked()),SLOT(clickSolo()));
    connect(ui->several_button,SIGNAL(clicked()),SLOT(clickSeveral()));
    connect(ui->exit_button,SIGNAL(clicked()),SLOT(close()));
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::clickSolo(){
    playernum -> show();
    this->close();
}

void StartWindow::clickSeveral(){
    rollbook->load(QUrl("https://namu.wiki/w/%EC%95%BC%EC%B0%8C"));
    rollbook->show();
}
