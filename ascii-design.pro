TEMPLATE = app
QT += gui core widgets
CONFIG += qt release warn_on
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/optionsman.ui ui/infodialog.ui
HEADERS = src/mainwindowimpl.h \
 src/figletmanager.h \
 src/figletfonts.h \
 src/options.h \
 src/dialogoptionsimpl.h \
 src/dialoginfoimpl.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/figletmanager.cpp \
 src/figletfonts.cpp \
 src/options.cpp \
 src/dialogoptionsimpl.cpp \
 src/dialoginfoimpl.cpp
RESOURCES += res.qrc
RC_FILE = winicon.rc
