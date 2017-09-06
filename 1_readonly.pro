TARGET =   mv_readonly

TEMPLATE = app

QT += widgets

SOURCES += main.cpp \
           mymodel.cpp \
    tableview.cpp \
    tableitemdelegate.cpp

HEADERS += mymodel.h \
    tableview.h \
    tableitemdelegate.h


# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/tutorials/modelview/1_readonly
INSTALLS += target
