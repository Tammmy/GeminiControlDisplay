#ifndef WARNINGINFOCONFIGDIALOG_H
#define WARNINGINFOCONFIGDIALOG_H

#include <QWidget>

namespace Ui {
class WarningInfoConfigDialog;
}

class WarningInfoConfigDialog : public QWidget
{
    Q_OBJECT

public:
    explicit WarningInfoConfigDialog(QWidget *parent = nullptr);
    ~WarningInfoConfigDialog();

private:
    Ui::WarningInfoConfigDialog *ui;
};

#endif // WARNINGINFOCONFIGDIALOG_H
