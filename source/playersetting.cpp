#include "../header/playersetting.h"
#include "ui_playersetting.h"
#include "../header/playernum.h"
#include "../header/gamewindow.h"
#include "../header/startwindow.h"

#include <QComboBox>
#include <QDebug>
#include <QPushButton>

PlayerSetting::PlayerSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerSetting)
{
    ui->setupUi(this);

    gamewindow = new GameWindow;

    ui->playername->setPlaceholderText("enter your name");
    ui->playercolor->addItems({"red","blue","green","yellow"});

    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(submit()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(cancle()));
}

PlayerSetting::~PlayerSetting()
{
    delete ui;
}

void PlayerSetting::submit(){
    if(playercount==1){
        qDebug()<<"submit1";
        p1_info[0]=ui->playername->text();
        p1_info[1]=ui->playercolor->currentText();

        gamewindow->init();
        ui->playername->clear();
        playercount++;

        if(playercount > PlayerNum::playernumber){
            gamewindow->show();
        }else{
            this->show();
        }
        qDebug()<<"array1 "<<p1_info[0]<<" "<<p1_info[1];
    }else if(playercount==2){
        qDebug()<<"submit2";
        p2_info[0]=ui->playername->text();
        p2_info[1]=ui->playercolor->currentText();
        ui->playername->clear();
        playercount++;
        if(playercount > PlayerNum::playernumber){
            gamewindow->show();
        }else{
            this->show();
        }
        qDebug()<<"array2 "<<p2_info[0]<<" "<<p2_info[1];
    }else if(playercount==3){
        qDebug()<<"submit3";
        p3_info[0]=ui->playername->text();
        p3_info[1]=ui->playercolor->currentText();
        ui->playername->clear();
        playercount++;
        if(playercount > PlayerNum::playernumber){
            gamewindow->show();
        }else{
            this->show();
        }
        qDebug()<<"array3 "<<p3_info[0]<<" "<<p3_info[1];
    }else{
        qDebug()<<"submit4";
        p4_info[0]=ui->playername->text();
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

void PlayerSetting::cancle(){
    startwindow = new StartWindow;
    startwindow->show();
}

// static value initialize
