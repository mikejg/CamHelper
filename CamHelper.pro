QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Project/mlabel.cpp \
    Project/pix_scrollarea.cpp \
    Project/pix_scrollcontent.cpp \
    Project/selectorwidget.cpp \
    Project/tab_project.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Project/mlabel.h \
    Project/pix_scrollarea.h \
    Project/pix_scrollcontent.h \
    Project/selectorwidget.h \
    Project/tab_project.h \
    mainwindow.h

FORMS += \
    Project/pix_scrollarea.ui \
    Project/pix_scrollcontent.ui \
    Project/selectorwidget.ui \
    Project/tab_project.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc
