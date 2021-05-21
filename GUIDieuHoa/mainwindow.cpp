#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_windows();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//------------
//Hàm khởi tạo giao diện khi chương trình vừa chạy
//---------------------------------------------------
void MainWindow::init_windows(){
    bFlagPowerOn=false; //Cho chương trình biết là điều hòa tắt
    ui->label_TempNumber->setVisible(false);
    ui->label_Do->setVisible(false);
    iTemp=25;
}

void MainWindow::on_pushButton_Power_clicked()
{
    if(bFlagPowerOn==false){
        ui->label_TempNumber->setVisible(true);
        ui->label_Do->setVisible(true);
        bFlagPowerOn=true;  //chuyển sang trạng thái bật
    }else
    {
        ui->label_TempNumber->setVisible(false);
        ui->label_Do->setVisible(false);
        bFlagPowerOn=false; //chuyển sang trạng thái tắt
    }
}

void MainWindow::on_pushButtoneTempCong_clicked()
{
    if(iTemp<iTempMax){
        iTemp++; //tăng nhiệt độ lên 1 độ và lưu lại vào biến
        ui->label_TempNumber->setText(QString::number(iTemp));
    }
}

void MainWindow::on_pushButton_TempTru_clicked()
{
    if(iTemp>iTempMin){
        iTemp--; //tăng nhiệt độ lên 1 độ và lưu lại vào biến
        ui->label_TempNumber->setText(QString::number(iTemp));
    }
}
