#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(bool transparent, bool frameless, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("中国水产科学研究院渔业机械研究所@2022");
}

MainWindow::~MainWindow()
{
    delete ui;
}

