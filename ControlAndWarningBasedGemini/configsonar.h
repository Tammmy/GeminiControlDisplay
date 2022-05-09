#ifndef CONFIGSONAR_H
#define CONFIGSONAR_H

#include <QWidget>

namespace Ui
{
class ConfigSonar;
}

class ConfigSonar : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigSonar(QWidget* parent = nullptr);
    ~ConfigSonar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ConfigSonar* ui;
};

#endif // CONFIGSONAR_H
