#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QVector>

class PlayerInfo{
public:
    QVector <int> P1_Point = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector <int> P2_Point = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector <int> P3_Point = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector <int> P4_Point = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector <QString> P1_Point_str = {"","","","","","","","","","","","",""};
    QVector <QString> P2_Point_str = {"","","","","","","","","","","","",""};
    QVector <QString> P3_Point_str = {"","","","","","","","","","","","",""};
    QVector <QString> P4_Point_str = {"","","","","","","","","","","","",""};
    QString p1_info[2];
    QString p2_info[2];
    QString p3_info[2];
    QString p4_info[2];
};

#endif // PLAYERINFO_H
