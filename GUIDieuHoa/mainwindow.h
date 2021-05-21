#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Power_clicked();
    void init_windows();

    void on_pushButtoneTempCong_clicked();

    void on_pushButton_TempTru_clicked();

private:
    Ui::MainWindow *ui;
    bool bFlagPowerOn;  //false: tắt   ;   true: đang mở
    int iTemp;
    const int iTempMin=18;
    const int iTempMax=30;

};
#endif // MAINWINDOW_H
