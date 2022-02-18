#include "playernum.h"
#include "ui_playernum.h"
#include "playerinfo.h"
#include "startwindow.h"

#include <QDialogButtonBox>

PlayerNum::PlayerNum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerNum)
{
    ui->setupUi(this);
    playerinfo = new PlayerInfo;

    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(submit()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(cancle()));
}

PlayerNum::~PlayerNum()
{
    delete ui;
}

void PlayerNum::submit(){
    playernumber = ui->playernumber->value();
    playerinfo->show();
}
//void PlayerNum::cancle()

int PlayerNum::playernumber=0;
