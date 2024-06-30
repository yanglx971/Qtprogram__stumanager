QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    course.cpp \
    loginwindow.cpp \
    main.cpp \
    modewindow.cpp \
    schooledit.cpp \
    student.cpp \
    studentview.cpp \
    teacher.cpp \
    teacherinsert.cpp \
    teachersearch.cpp \
    teacherview.cpp

HEADERS += \
    course.h \
    globalcourse.h \
    globalstudent.h \
    globalteacher.h \
    loginwindow.h \
    modewindow.h \
    schooledit.h \
    student.h \
    studentview.h \
    teacher.h \
    teacherinsert.h \
    teachersearch.h \
    teacherview.h

FORMS += \
    loginwindow.ui \
    modewindow.ui \
    schooledit.ui \
    studentview.ui \
    teacherinsert.ui \
    teachersearch.ui \
    teacherview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
