#include "../header/playernum.h"
#include "ui_playernum.h"
#include "../header/playersetting.h"
#include "../header/startwindow.h"

#include <QDialogButtonBox>

PlayerNum::PlayerNum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerNum)
{
    ui->setupUi(this);
    playersetting = new PlayerSetting;

    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(submit()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(cancle()));
}

PlayerNum::~PlayerNum()
{
    delete ui;
}

void PlayerNum::submit(){
    playernumber = ui->playernumber->value();
    playersetting->show();
}

//void PlayerNum::cancle()
int PlayerNum::playernumber=0;
