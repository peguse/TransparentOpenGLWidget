#include "mainwindow.h"
#include <QApplication>

#include <QPalette>
#include <QShortcut>
#include <QStyleFactory>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle(QStyleFactory::create("Fusion"));
    QPalette p (QColor(43, 43, 43));
    a.setPalette(p);

    MainWindow w;
    w.show();

    return a.exec();
}
