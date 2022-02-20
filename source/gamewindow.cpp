#include "../header/gamewindow.h"
#include "ui_gamewindow.h"
#include "../header/startwindow.h"
#include "../header/playerinfo.h"

#include <QRandomGenerator>
#include <QDebug>
#include <QtAlgorithms>

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    // dice button setting
    for(int i=0; i<5; i++){
        dice[i] = new QPushButton(this);
        dice[i]->resize(60,60);
        dice[i]->move(650,120+62*i);
    }


    connect(ui->exit_button,SIGNAL(clicked()),SLOT(close()));
    connect(ui->start_button,SIGNAL(clicked()),SLOT(clickStartWindow()));
    connect(ui->roll_button,SIGNAL(clicked()),SLOT(clickRoll()));

    // dice button connect
    connect(dice[0],SIGNAL(clicked()),SLOT(clickdice1()));
    connect(dice[1],SIGNAL(clicked()),SLOT(clickdice2()));
    connect(dice[2],SIGNAL(clicked()),SLOT(clickdice3()));
    connect(dice[3],SIGNAL(clicked()),SLOT(clickdice4()));
    connect(dice[4],SIGNAL(clicked()),SLOT(clickdice5()));

    connect(ui->score_button,SIGNAL(clicked()),SLOT(clickScore()));
}

GameWindow::~GameWindow()
{
    delete ui;
    if(startwindow) delete startwindow;
}

void GameWindow::init(){
    windowcolor = PlayerInfo::p1_info[1];
    ui->playername->setText(PlayerInfo::p1_info[0]);
    changewindowcolor();
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
    for(int i=0; i<5; i++){
        if(dicechange[i]==true){
            dicenum[i] = (QRandomGenerator::global()->generate())%6+1;
            dice[i]->setText(QString("%1").arg(dicenum[i]));
        }
    }

    int sum = P1_Point[0] + P1_Point[1] + P1_Point[2] + P1_Point[3] + P1_Point[4] + P1_Point[5];

    P1_Point[0] = std::count(dicenum.begin(),dicenum.end(),1);
    P1_Point[1] = std::count(dicenum.begin(),dicenum.end(),2)*2;
    P1_Point[2] = std::count(dicenum.begin(),dicenum.end(),3)*3;
    P1_Point[3] = std::count(dicenum.begin(),dicenum.end(),4)*4;
    P1_Point[4] = std::count(dicenum.begin(),dicenum.end(),5)*5;
    P1_Point[5] = std::count(dicenum.begin(),dicenum.end(),6)*6;
    sum>=63 ? P1_Point[6]=35 : P1_Point[6]=0;
    count_bool(3) ? P1_Point[7]=std::accumulate(dicenum.begin(),dicenum.end(),0) : P1_Point[7]=0;
    count_bool(4) ? P1_Point[8]=std::accumulate(dicenum.begin(),dicenum.end(),0) : P1_Point[8]=0;
    fullhouse_bool() ? P1_Point[9]=25 : P1_Point[9]=0;
    straight_bool(4) ? P1_Point[10]=30 : P1_Point[10]=0;
    straight_bool(5) ? P1_Point[11]=40 : P1_Point[11]=0;
    count_bool(5) ? P1_Point[12]=50 : P1_Point[12]=0;
    P1_Point[13] = std::accumulate(dicenum.begin(),dicenum.end(),0);

    ui->ones_point->setText(QString("%1").arg(P1_Point[0]));
    ui->twos_point->setText(QString("%1").arg(P1_Point[1]));
    ui->threes_point->setText(QString("%1").arg(P1_Point[2]));
    ui->fours_point->setText(QString("%1").arg(P1_Point[3]));
    ui->fives_point->setText(QString("%1").arg(P1_Point[4]));
    ui->sixs_point->setText(QString("%1").arg(P1_Point[5]));
    ui->bonus_point->setText(QString("%1").arg(P1_Point[6]));
    ui->triple_point->setText(QString("%1").arg(P1_Point[7]));
    ui->fourth_point->setText(QString("%1").arg(P1_Point[8]));
    ui->FH_point->setText(QString("%1").arg(P1_Point[9]));
    ui->small_point->setText(QString("%1").arg(P1_Point[10]));
    ui->large_point->setText(QString("%1").arg(P1_Point[11]));
    ui->yatzy_point->setText(QString("%1").arg(P1_Point[12]));
    ui->chance_point->setText(QString("%1").arg(P1_Point[13]));

    qDebug()<<"dice num : "<<dicenum[0]<<" "<<dicenum[1]<<" "<<dicenum[2]<<" "<<dicenum[3]<<" "<<dicenum[4];
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

    qDebug()<<"windowcolor : "<<windowcolor;

    changewindowcolor();
}



void GameWindow::clickdice1(){
    if(dicechange[0]==true){
        dicechange[0]=false;
        dice[0]->setStyleSheet(buttonborder);
    } else{
        dice[0]->setStyleSheet(buttonreset);
        dicechange[0]=true;
    }
}
void GameWindow::clickdice2(){
    if(dicechange[1]==true){
        dicechange[1]=false;
        dice[1]->setStyleSheet(buttonborder);
    } else{
        dice[1]->setStyleSheet(buttonreset);
        dicechange[1]=true;
    }
}
void GameWindow::clickdice3(){
    if(dicechange[2]==true){
        dicechange[2]=false;
        dice[2]->setStyleSheet(buttonborder);
    } else{
        dice[2]->setStyleSheet(buttonreset);
        dicechange[2]=true;
    }
}
void GameWindow::clickdice4(){
    if(dicechange[3]==true){
        dicechange[3]=false;
        dice[3]->setStyleSheet(buttonborder);
    } else{
        dice[3]->setStyleSheet(buttonreset);
        dicechange[3]=true;
    }
}
void GameWindow::clickdice5(){
    if(dicechange[4]==true){
        dicechange[4]=false;
        dice[4]->setStyleSheet(buttonborder);
    } else{
        dice[4]->setStyleSheet(buttonreset);
        dicechange[4]=true;
    }
}

//game rank rule
bool GameWindow::count_bool(int num){
    for(int i=1; i<=6; i++){
        if(std::count(dicenum.begin(),dicenum.end(),i)>=num) return true;
    }
    return false;
}
bool GameWindow::fullhouse_bool(){
    for(int i=1; i<=6; i++){
        if(std::count(dicenum.begin(),dicenum.end(),i)>=3){
            for(int j=1; j<=6; j++){
                if(j==i) continue;

                if(std::count(dicenum.begin(),dicenum.end(),j)>=2) return true;
            }
        }
    }
    return false;
}
bool GameWindow::straight_bool(int num){
    QVector <int> dicenum2 =dicenum;
    std::sort(dicenum2.begin(),dicenum2.end());

//    qDebug()<<"dice num2 : "<<dicenum2[0]<<" "<<dicenum2[1]<<" "<<dicenum2[2]<<" "<<dicenum2[3]<<" "<<dicenum2[4];

    if(dicenum2[4]==dicenum2[3]+1 && dicenum2[3]==dicenum2[2]+1 &&
            dicenum2[2]==dicenum2[1]+1 && dicenum2[1]==dicenum2[0]+1) return true;

    if(num==4){
        if(dicenum2[4]<=dicenum2[3]+1 && dicenum2[3]<=dicenum2[2]+1 &&
                dicenum2[2]<=dicenum2[1]+1 && dicenum2[1]<=dicenum2[0]+1 && dicenum2[4]-dicenum2[0]==3) return true;
    }

    return false;
}

