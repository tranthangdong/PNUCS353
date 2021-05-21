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
    ui->label_ModeTunhien->setVisible(false);
    ui->label_ModeGio->setVisible(false);
    ui->label_ModeLanh->setVisible(false);
    QImage img1("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_quat_off.png");
    ui->label_ModeTunhien->setPixmap(QPixmap::fromImage(img1));
    QImage img2("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_tunhien_off.png");
    ui->label_ModeGio->setPixmap(QPixmap::fromImage(img2));
    QImage img3("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_tuyet_off.png");
    ui->label_ModeLanh->setPixmap(QPixmap::fromImage(img3));
    iTemp=25;
    iMode=1;
}

//------------
//Hàm cài đặt mode điều hòa
//---------------------------------------------------
void MainWindow::setMode(int iMode){
    if(iMode==1){
        QImage img1("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_quat_on.jpg");
        ui->label_ModeTunhien->setPixmap(QPixmap::fromImage(img1));
        QImage img2("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_tunhien_off.png");
        ui->label_ModeGio->setPixmap(QPixmap::fromImage(img2));
        QImage img3("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_tuyet_off.png");
        ui->label_ModeLanh->setPixmap(QPixmap::fromImage(img3));
    }
    if(iMode==2){
        QImage img1("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_quat_off.png");
        ui->label_ModeTunhien->setPixmap(QPixmap::fromImage(img1));
        QImage img2("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_tunhien_on.jpg");
        ui->label_ModeGio->setPixmap(QPixmap::fromImage(img2));
        QImage img3("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_tuyet_off.png");
        ui->label_ModeLanh->setPixmap(QPixmap::fromImage(img3));
    }
    if(iMode==3){
        QImage img1("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_quat_off.png");
        ui->label_ModeTunhien->setPixmap(QPixmap::fromImage(img1));
        QImage img2("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_tunhien_off.png");
        ui->label_ModeGio->setPixmap(QPixmap::fromImage(img2));
        QImage img3("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_tuyet_on.jpg");
        ui->label_ModeLanh->setPixmap(QPixmap::fromImage(img3));
    }
}

void MainWindow::on_pushButton_Power_clicked()
{
    if(bFlagPowerOn==false){
        ui->label_TempNumber->setVisible(true);
        ui->label_Do->setVisible(true);
        ui->label_ModeTunhien->setVisible(true);
        ui->label_ModeGio->setVisible(true);
        ui->label_ModeLanh->setVisible(true);
        QImage img1("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/mode_quat_on.jpg");
        ui->label_ModeTunhien->setPixmap(QPixmap::fromImage(img1));
        iMode=2;
        bFlagPowerOn=true;  //chuyển sang trạng thái bật
    }else
    {
        ui->label_TempNumber->setVisible(false);
        ui->label_Do->setVisible(false);
        ui->label_ModeTunhien->setVisible(false);
        ui->label_ModeGio->setVisible(false);
        ui->label_ModeLanh->setVisible(false);
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

void MainWindow::on_pushButton_Mode_clicked()
{
    setMode(iMode);
    if(iMode<3)
        iMode++;
    else if(iMode==3)
        iMode=1;
}
