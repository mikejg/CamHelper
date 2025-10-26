QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Classes/database.cpp \
    Classes/mcellwidget.cpp \
    Classes/mcombobox.cpp \
    Classes/mdoublespinbox.cpp \
    Classes/mfile.cpp \
    Classes/mlineedit.cpp \
    Classes/roundedlabel.cpp \
    Classes/spf_parser.cpp \
    Dialoge/dialog_init.cpp \
    Dialoge/dialog_open.cpp \
    Dialoge/dialog_programm.cpp \
    Dialoge/dialog_progress.cpp \
    Dialoge/dialog_rawpartinspection.cpp \
    Dialoge/dialog_repetition.cpp \
    Dialoge/dialog_save.cpp \
    Dialoge/dialog_settings.cpp \
    Dialoge/dialog_tag.cpp \
    Dialoge/dialog_tools.cpp \
    Dialoge/dialog_toolsearch.cpp \
    Logging/logging.cpp \
    Logging/mhighlighter.cpp \
    Magazin/magazin.cpp \
    Magazin/magazinmodel.cpp \
    MainProgramm/highlighter840.cpp \
    MainProgramm/mainprogramm.cpp \
    Model/programmmodel.cpp \
    Model/spinboxdelegate.cpp \
    Model/toolmodel.cpp \
    Project/mlabel.cpp \
    Project/pix_scrollarea.cpp \
    Project/pix_scrollcontent.cpp \
    Project/project.cpp \
    Project/project_export.cpp \
    Project/selectorwidget.cpp \
    Project/tab_project.cpp \
    Tool/tool.cpp \
    Tool/toollist.cpp \
    ToolSheet/tableprinter.cpp \
    ToolSheet/toolsheet.cpp \
    ToolSheet/toolsheet_model.cpp \
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
    main.cpp \
    mainwindow.cpp \
    settings.cpp

HEADERS += \
    Classes/database.h \
    Classes/mcellwidget.h \
    Classes/mcombobox.h \
    Classes/mdoublespinbox.h \
    Classes/mfile.h \
    Classes/mlineedit.h \
    Classes/roundedlabel.h \
    Classes/spf_parser.h \
    Classes/struct.h \
    Dialoge/dialog_init.h \
    Dialoge/dialog_open.h \
    Dialoge/dialog_programm.h \
    Dialoge/dialog_progress.h \
    Dialoge/dialog_rawpartinspection.h \
    Dialoge/dialog_repetition.h \
    Dialoge/dialog_save.h \
    Dialoge/dialog_settings.h \
    Dialoge/dialog_tag.h \
    Dialoge/dialog_tools.h \
    Dialoge/dialog_toolsearch.h \
    Logging/logging.h \
    Logging/mhighlighter.h \
    Magazin/magazin.h \
    Magazin/magazinmodel.h \
    MainProgramm/highlighter840.h \
    MainProgramm/mainprogramm.h \
    Model/programmmodel.h \
    Model/spinboxdelegate.h \
    Model/toolmodel.h \
    Project/mlabel.h \
    Project/pix_scrollarea.h \
    Project/pix_scrollcontent.h \
    Project/project.h \
    Project/project_export.h \
    Project/selectorwidget.h \
    Project/tab_project.h \
    Tool/tool.h \
    Tool/tool_Struct.h \
    Tool/toollist.h \
    ToolSheet/tableprinter.h \
    ToolSheet/toolsheet.h \
    ToolSheet/toolsheet_model.h \
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
    mainwindow.h \
    settings.h

FORMS += \
    Classes/mcellwidget.ui \
    Dialoge/dialog_init.ui \
    Dialoge/dialog_open.ui \
    Dialoge/dialog_programm.ui \
    Dialoge/dialog_progress.ui \
    Dialoge/dialog_rawpartinspection.ui \
    Dialoge/dialog_repetition.ui \
    Dialoge/dialog_save.ui \
    Dialoge/dialog_settings.ui \
    Dialoge/dialog_tag.ui \
    Dialoge/dialog_tools.ui \
    Dialoge/dialog_toolsearch.ui \
    Magazin/magazin.ui \
    Project/pix_scrollarea.ui \
    Project/pix_scrollcontent.ui \
    Project/selectorwidget.ui \
    Project/tab_project.ui \
    ToolSheet/toolsheet.ui \
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
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc
