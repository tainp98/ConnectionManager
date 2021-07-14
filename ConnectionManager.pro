TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Connection/UDPSender.cpp \
    Connection/UDPListener.cpp \
    ConnectionFactory/UDPSenderFactory.cpp \
    ConnectionFactory/UDPListenerFactory.cpp

HEADERS += \
    ConnectionFactory/ConnectionFactory.h \
    Connection/Connection.h \
    ConnectionManager.h \
    define.h \
    Connection/UDPSender.h \
    Connection/UDPListener.h \
    ConnectionFactory/UDPSenderFactory.h \
    ConnectionFactory/UDPListenerFactory.h \
    Packet/EyephoenixProtocol.h \
    Packet/KLV.h \
    Packet/utils.h \
    Packet/Object.h \
    Packet/Common_type.h \
    Packet/Data.h \
    Packet/EyeStatus.h \
    Packet/Vector.h

QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread
