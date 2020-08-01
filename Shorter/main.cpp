#include "mainwindow.h"

#include <QApplication>
#include "node.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qRegisterMetaType<Node>();
    w.show();
    return a.exec();
}
