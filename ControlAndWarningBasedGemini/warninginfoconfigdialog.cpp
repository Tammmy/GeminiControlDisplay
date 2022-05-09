#include "warninginfoconfigdialog.h"
#include "ui_warninginfoconfigdialog.h"

WarningInfoConfigDialog::WarningInfoConfigDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WarningInfoConfigDialog)
{
    ui->setupUi(this);
}

WarningInfoConfigDialog::~WarningInfoConfigDialog()
{
    delete ui;
}
