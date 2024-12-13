QT       += core printsupport gui sql network core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Dialoge/dialog_open.cpp \
    Dialoge/dialog_programm.cpp \
    Dialoge/dialog_progress.cpp \
    Dialoge/dialog_project.cpp \
    Dialoge/dialog_rawpartinspection.cpp \
    Dialoge/dialog_repetition.cpp \
    Dialoge/dialog_settings.cpp \
    Dialoge/dialog_start.cpp \
    Dialoge/dialog_tag.cpp \
    Dialoge/dialog_tools.cpp \
    Magazin/magazinmodel.cpp \
    Model/programmmodel.cpp \
    Model/spinboxdelegate.cpp \
    Model/tablemodel.cpp \
    Model/toolmodel.cpp \
    Parser/parser_placeholder.cpp \
    Parser/parser_programm.cpp \
    Project/mlabel.cpp \
    Project/pix_scrollarea.cpp \
    Project/pix_scrollcontent.cpp \
    Project/project.cpp \
    Project/project_export.cpp \
    Project/selectorwidget.cpp \
    Project/tab_project.cpp \
    Tools/tool.cpp \
    Tools/toollist.cpp \
    TouchProbe/touchprobe.cpp \
    TouchProbe/tp_ausrichten.cpp \
    TouchProbe/tp_base.cpp \
    TouchProbe/tp_bohrung.cpp \
    TouchProbe/tp_ebenheit.cpp \
    TouchProbe/tp_highlighter.cpp \
    TouchProbe/tp_item.cpp \
    TouchProbe/tp_kante.cpp \
    TouchProbe/tp_nut.cpp \
    TouchProbe/tp_scrollcontent.cpp \
    TouchProbe/tp_steg.cpp \
    database.cpp \
    highlighter.cpp \
    license.cpp \
    logging.cpp \
    Magazin\magazin.cpp \
    main.cpp \
    camhelper.cpp \
    mcombobox.cpp \
    mfile.cpp \
    settings.cpp \
    tableprinter.cpp

HEADERS += \
    Dialoge/dialog_open.h \
    Dialoge/dialog_programm.h \
    Dialoge/dialog_progress.h \
    Dialoge/dialog_project.h \
    Dialoge/dialog_rawpartinspection.h \
    Dialoge/dialog_repetition.h \
    Dialoge/dialog_settings.h \
    Dialoge/dialog_start.h \
    Dialoge/dialog_tag.h \
    Dialoge/dialog_tools.h \
    Magazin/magazinmodel.h \
    Model/programmmodel.h \
    Model/spinboxdelegate.h \
    Model/tablemodel.h \
    Model/toolmodel.h \
    Parser/parser_placeholder.h \
    Parser/parser_programm.h \
    Project/mlabel.h \
    Project/pix_scrollarea.h \
    Project/pix_scrollcontent.h \
    Project/project.h \
    Project/project_export.h \
    Project/selectorwidget.h \
    Project/tab_project.h \
    Tools/tool.h \
    Tools/toollist.h \
    TouchProbe/touchprobe.h \
    TouchProbe/tp_ausrichten.h \
    TouchProbe/tp_base.h \
    TouchProbe/tp_bohrung.h \
    TouchProbe/tp_ebenheit.h \
    TouchProbe/tp_highlighter.h \
    TouchProbe/tp_item.h \
    TouchProbe/tp_kante.h \
    TouchProbe/tp_nut.h \
    TouchProbe/tp_scrollcontent.h \
    TouchProbe/tp_steg.h \
    TouchProbe/tp_struct.h \
    camhelper.h \
    database.h \
    database_items.h \
    highlighter.h \
    license.h \
    logging.h \
    Magazin\magazin.h \
    mcombobox.h \
    mfile.h \
    settings.h \
    tableprinter.h

FORMS += \
    Dialoge/dialog_open.ui \
    Dialoge/dialog_programm.ui \
    Dialoge/dialog_progress.ui \
    Dialoge/dialog_project.ui \
    Dialoge/dialog_rawpartinspection.ui \
    Dialoge/dialog_repetition.ui \
    Dialoge/dialog_settings.ui \
    Dialoge/dialog_start.ui \
    Dialoge/dialog_tag.ui \
    Dialoge/dialog_tools.ui \
    Project/pix_scrollarea.ui \
    Project/pix_scrollcontent.ui \
    Project/selectorwidget.ui \
    Project/tab_project.ui \
    TouchProbe/touchprobe.ui \
    TouchProbe/tp_ausrichten.ui \
    TouchProbe/tp_base.ui \
    TouchProbe/tp_bohrung.ui \
    TouchProbe/tp_ebenheit.ui \
    TouchProbe/tp_item.ui \
    TouchProbe/tp_kante.ui \
    TouchProbe/tp_nut.ui \
    TouchProbe/tp_scrollcontent.ui \
    TouchProbe/tp_steg.ui \
    camhelper.ui \
    Magazin\magazin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc
