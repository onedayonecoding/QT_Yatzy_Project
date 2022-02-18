#include "../header/gamewindow.h"
#include "ui_gamewindow.h"
#include "../header/startwindow.h"
#include "../header/playerinfo.h"

#include <QRandomGenerator>
#include <QDebug>

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    init();

    connect(ui->exit_button,SIGNAL(clicked()),SLOT(close()));
    connect(ui->start_button,SIGNAL(clicked()),SLOT(clickStartWindow()));
    connect(ui->roll_button,SIGNAL(clicked()),SLOT(clickRoll()));
    connect(ui->dice1,SIGNAL(clicked()),SLOT(clickdice1()));
    connect(ui->dice2,SIGNAL(clicked()),SLOT(clickdice2()));
    connect(ui->dice3,SIGNAL(clicked()),SLOT(clickdice3()));
    connect(ui->dice4,SIGNAL(clicked()),SLOT(clickdice4()));
    connect(ui->dice5,SIGNAL(clicked()),SLOT(clickdice5()));
    connect(ui->score_button,SIGNAL(clicked()),SLOT(clickScore()));
}

GameWindow::~GameWindow()
{
    delete ui;
    if(startwindow) delete startwindow;
}

void GameWindow::init(){
    qDebug()<<"game init";
    windowcolor = PlayerInfo::p1_info[1];
    changewindowcolor();
    ui->playername->setText(PlayerInfo::p1_info[0]);
}

void GameWindow::clickStartWindow(){
    startwindow = new StartWindow;
    startwindow->show();
    this->close();
}

void GameWindow::changewindowcolor(){
    if(windowcolor=="red"){
        this->setStyleSheet("background:#FF6666");
    }else if(windowcolor=="blue"){
        this->setStyleSheet("background:#6666FF");
    }else if(windowcolor=="green"){
        this->setStyleSheet("background:#66FF66");
    }else{
        this->setStyleSheet("background:#FFFF99");
    }
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

    QString ones;
    QString twos;
    QString threes;
    QString fours;
    QString fives;
    QString sixs;
    QString triple;
    QString fourkind;
    QString fullhouse;
    QString small;
    QString large;
    QString yatzy;
    QString chance;

    chance = QString("%1").arg(dicenum1.toInt()+dicenum2.toInt()
                               +dicenum3.toInt()+dicenum4.toInt()+dicenum5.toInt());

    ui->ones_point->setText(ones);
    ui->twos_point->setText(twos);
    ui->threes_point->setText(threes);
    ui->fours_point->setText(fours);
    ui->fives_point->setText(fives);
    ui->sixs_point->setText(sixs);
    ui->triple_point->setText(triple);
    ui->fourth_point->setText(fourkind);
    ui->FH_point->setText(fullhouse);
    ui->small_point->setText(small);
    ui->large_point->setText(large);
    ui->yatzy_point->setText(yatzy);
    ui->chance_point->setText(chance);
}

void GameWindow::clickScore(){
    if(playerturn==PlayerNum::playernumber) playerturn=1;
    else playerturn++;

    if (playerturn==1){
        windowcolor = PlayerInfo::p1_info[1];
        ui->playername->setText(PlayerInfo::p1_info[0]);
    }else if(playerturn==2){
        windowcolor = PlayerInfo::p2_info[1];
        ui->playername->setText(PlayerInfo::p2_info[0]);
    }else if(playerturn==3){
        windowcolor = PlayerInfo::p3_info[1];
        ui->playername->setText(PlayerInfo::p3_info[0]);
    }else{
        windowcolor = PlayerInfo::p4_info[1];
        ui->playername->setText(PlayerInfo::p4_info[0]);
    }
    changewindowcolor();
}

void GameWindow::clickdice1(){
    if(dicechange1==true){
        dicechange1=false;
        ui->dice1->setStyleSheet(buttonborder);
    } else{
        ui->dice1->setStyleSheet(buttonreset);
        dicechange1=true;
    }
}
void GameWindow::clickdice2(){
    if(dicechange2==true){
        dicechange2=false;
        ui->dice2->setStyleSheet(buttonborder);
    } else{
        ui->dice2->setStyleSheet(buttonreset);
        dicechange2=true;
    }
}
void GameWindow::clickdice3(){
    if(dicechange3==true){
        dicechange3=false;
        ui->dice3->setStyleSheet(buttonborder);
    } else{
        ui->dice3->setStyleSheet(buttonreset);
        dicechange3=true;
    }
}
void GameWindow::clickdice4(){
    if(dicechange4==true){
        dicechange4=false;
        ui->dice4->setStyleSheet(buttonborder);
    } else{
        ui->dice4->setStyleSheet(buttonreset);
        dicechange4=true;
    }
}
void GameWindow::clickdice5(){
    if(dicechange5==true){
        dicechange5=false;
        ui->dice5->setStyleSheet(buttonborder);
    } else{
        ui->dice5->setStyleSheet(buttonreset);
        dicechange5=true;
    }
}
