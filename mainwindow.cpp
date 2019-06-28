#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set as tranparent window
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_NoSystemBackground, false);

    // *** toolbar should be opaque red without transparency ***
    // *** Currently the desktop background shows through the red toolbar ***
    // *** This makes the controls hard to see ***
    ui->toolbar->setStyleSheet("QWidget[accessibleName=\"toolbar\"]{background: red;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
