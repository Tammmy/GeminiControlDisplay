#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(bool transparent, bool frameless, QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void ShowConfigSonarDialog();
    void ShowConfigWarningDialog();

private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
