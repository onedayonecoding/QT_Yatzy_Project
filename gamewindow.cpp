#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "startwindow.h"

#include <QRandomGenerator>
#include <iostream>

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    connect(ui->exit_button,SIGNAL(clicked()),SLOT(close()));
    connect(ui->start_button,SIGNAL(clicked()),SLOT(clickStartWindow()));
    connect(ui->roll_button,SIGNAL(clicked()),SLOT(clickRoll()));
    connect(ui->dice1,SIGNAL(clicked()),SLOT(clickdice1()));
    connect(ui->dice2,SIGNAL(clicked()),SLOT(clickdice2()));
    connect(ui->dice3,SIGNAL(clicked()),SLOT(clickdice3()));
    connect(ui->dice4,SIGNAL(clicked()),SLOT(clickdice4()));
    connect(ui->dice5,SIGNAL(clicked()),SLOT(clickdice5()));

}

GameWindow::~GameWindow()
{
    delete ui;
    if(startwindow) delete startwindow;
}

void GameWindow::clickStartWindow(){
    startwindow = new StartWindow;
    startwindow->show();
    this->close();
}

void GameWindow::clickRoll(){
    if(dicechange1==true){
        dicenum1 = QString("%1").arg((QRandomGenerator::global()->generate())%6+1);
    }
    if(dicechange2==true){
         dicenum2 = QString("%1").arg((QRandomGenerator::global()->generate())%6+1);
    }
    if(dicechange3==true){
        dicenum3 = QString("%1").arg((QRandomGenerator::global()->generate())%6+1);
    }
    if(dicechange4==true){
        dicenum4 = QString("%1").arg((QRandomGenerator::global()->generate())%6+1);
    }
    if(dicechange5==true){
        dicenum5 = QString("%1").arg((QRandomGenerator::global()->generate())%6+1);
    }
    ui->dice1->setText(dicenum1);
    ui->dice2->setText(dicenum2);
    ui->dice3->setText(dicenum3);
    ui->dice4->setText(dicenum4);
    ui->dice5->setText(dicenum5);
}

void GameWindow::clickdice1(){
    if(dicechange1==true){
        dicechange1=false;
    } else dicechange1=true;
}
void GameWindow::clickdice2(){
    if(dicechange2==true){
        dicechange2=false;
    } else dicechange2=true;
}
void GameWindow::clickdice3(){
    if(dicechange3==true){
        dicechange3=false;
    } else dicechange3=true;
}
void GameWindow::clickdice4(){
    if(dicechange4==true){
        dicechange4=false;
    } else dicechange4=true;
}
void GameWindow::clickdice5(){
    if(dicechange5==true){
        dicechange5=false;
    } else dicechange5=true;
}
