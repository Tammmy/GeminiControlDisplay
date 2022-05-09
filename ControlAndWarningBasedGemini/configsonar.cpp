#include "configsonar.h"
#include "ui_configsonar.h"


#include <QDebug>

ConfigSonar::ConfigSonar(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ConfigSonar)
{
    ui->setupUi(this);
}

ConfigSonar::~ConfigSonar()
{
    delete ui;
}

void ConfigSonar::on_pushButton_clicked()
{
    qDebug() << "OK Clicked";
    // TODO Uodate sonar config
}

void ConfigSonar::on_pushButton_2_clicked()
{
    this->close();
}
