QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets\
                                        webenginewidgets


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    source/startwindow.cpp \
    source/gamewindow.cpp \
    source/playerinfo.cpp\
    source/playernum.cpp

HEADERS += \
    header/startwindow.h\
    header/gamewindow.h\
    header/playerinfo.h\
    header/playernum.h

FORMS += \
    form/startwindow.ui\
    form/gamewindow.ui\
    form/playerinfo.ui\
    form/playernum.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
