#include "playerinfo.h"
#include "ui_playerinfo.h"
#include "playernum.h"
#include "gamewindow.h"
#include "startwindow.h"

#include <QComboBox>
#include <QDebug>
#include <QPushButton>

PlayerInfo::PlayerInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerInfo)
{
    ui->setupUi(this);

    gamewindow = new GameWindow;

    ui->playercolor->addItems({"red","blue","green","yellow"});

    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(submit()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(cancle()));
}

PlayerInfo::~PlayerInfo()
{
    delete ui;
}

void PlayerInfo::submit(){
    if(playercount==1){
        qDebug()<<"submit1";
        p1_info[0]=ui->playercolor->currentText();
        p1_info[1]=ui->playercolor->currentText();
        playercount++;
        if(playercount > PlayerNum::playernumber){
            gamewindow->show();
        }else{
            this->show();
        }
        qDebug()<<"array1 "<<p1_info[0]<<" "<<p1_info[1];
    }else if(playercount==2){
        qDebug()<<"submit1";
        p2_info[0]=ui->playercolor->currentText();
        p2_info[1]=ui->playercolor->currentText();
        playercount++;
        if(playercount > PlayerNum::playernumber){
            gamewindow->show();
        }else{
            this->show();
        }
        qDebug()<<"array2 "<<p2_info[0]<<" "<<p2_info[1];
    }else if(playercount==3){
        qDebug()<<"submit1";
        p3_info[0]=ui->playercolor->currentText();
        p3_info[1]=ui->playercolor->currentText();
        playercount++;
        if(playercount > PlayerNum::playernumber){
            gamewindow->show();
        }else{
            this->show();
        }
        qDebug()<<"array3 "<<p3_info[0]<<" "<<p3_info[1];
    }else{
        qDebug()<<"submit1";
        p4_info[0]=ui->playercolor->currentText();
        p4_info[1]=ui->playercolor->currentText();
        playercount++;
        if(playercount > PlayerNum::playernumber){
            gamewindow->show();
        }else{
            this->show();
        }
        qDebug()<<"array4 "<<p4_info[0]<<" "<<p4_info[1];
    }

}

void PlayerInfo::cancle(){
    startwindow = new StartWindow;
    startwindow->show();
}

// static value initialize
QString PlayerInfo::p1_info[2] = {NULL,NULL};
QString PlayerInfo::p2_info[2] = {NULL,NULL};
QString PlayerInfo::p3_info[2] = {NULL,NULL};
QString PlayerInfo::p4_info[2] = {NULL,NULL};
