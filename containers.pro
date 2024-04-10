QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        exceptions/diffirentsizeexception.cpp \
        exceptions/incorrectindexexception.cpp \
        exceptions/testnotpassedexception.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    exceptions/diffirentsizeexception.h \
    exceptions/incorrectindexexception.h \
    exceptions/testnotpassedexception.h \
    iterator.h \
    vec.h \
    vec_impl.h \
    iterator_impl.h
