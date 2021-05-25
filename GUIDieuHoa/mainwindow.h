#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

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
    void init_windows();

    void setMode(int iMode);

    void readConfig();

    void writeConfig();

    void on_pushButton_Power_clicked();

    void on_pushButtoneTempCong_clicked();

    void on_pushButton_TempTru_clicked();

    void on_pushButton_Mode_clicked();

    void on_pushButton_Read_clicked();

    void on_pushButton_Write_clicked();

private:
    Ui::MainWindow *ui;
    bool bFlagPowerOn;  //false: tắt   ;   true: đang mở
    int iTemp;
    const int iTempMin=18;
    const int iTempMax=30;
    int iMode;

};
#endif // MAINWINDOW_H
