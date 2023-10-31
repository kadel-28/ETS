QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
INCLUDEPATH += C:/qt/Tools/OpenSSLv3/Win_x64/include/openssl
INCLUDEPATH += C:/qt/Tools/OpenSSLv3/Win_x64/include


LIBS += -LC:/qt/Tools/OpenSSLv3/Win_x64/lib -Llibcrypto
LIBS += -LC:/qt/Tools/OpenSSLv3/Win_x64/lib -Llibssl




# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Register.cpp \
        adding_transaction_page.cpp \
        graph_page.cpp \
        home.cpp \
        ledger_page.cpp \
        main.cpp \
        mainwindow.cpp
        mainwindow.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    adding_transaction_page.ui \
    graph_page.ui \
    ledger_page.ui \
    mainwindow.ui \
    second_win.ui \
    third_win.ui

HEADERS += \
    Register.h \
    adding_transaction_page.h \
    graph_page.h \
    ledger_page.h \
    mainwindow.h \
    second_win.h
