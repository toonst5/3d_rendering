QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    cords.cpp \
    main.cpp \
    mainWindow.cpp \
    matrixMath.cpp \
    poly.cpp \
    sorters.cpp

HEADERS += \
    button.h \
    cords.h \
    mainWindow.h \
    matrixMath.h \
    poly.h \
    sorters.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
