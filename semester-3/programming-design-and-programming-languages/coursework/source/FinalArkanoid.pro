QT       += core gui \
          multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/ball.cpp \
    sources/breakout.cpp \
    sources/brick.cpp \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/paddle.cpp

HEADERS += \
    headers/ball.h \
    headers/breakout.h \
    headers/brick.h \
    headers/mainwindow.h \
    headers/paddle.h \
    headers/ui_mainwindow.h \

FORMS += \
    window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    diagram_class.qmodel
