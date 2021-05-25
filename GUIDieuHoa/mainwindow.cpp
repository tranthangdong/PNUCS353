#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileInfo>


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

//------------
//Hàm đọc file data chứa thông tin đã lưu trữ
//---------------------------------------------------
void MainWindow::readConfig(){
    QTextStream out(stdout);
    QFile file("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/data.txt");

    if(!file.open(QIODevice::ReadOnly)){    //Mở file ra để đọc dữ liệu
        qWarning("Loi! Khong the mo duoc file.");
    }
    QTextStream in(&file);
    QString line;               //Biến kiểu string để lưu giá trị đọc được theo dòng từ file data.txt
    line = in.readLine();       //Đọc dòng thứ 1 trong file data.txt
    iTemp = line.toInt();
    ui->label_TempNumber->setText(line);    //Gán giá trị dòng thứ 1 vào label TempNumber
    line = in.readLine();       //Đọc dòng thứ 2 trong file data.txt
    iMode = line.toInt();       //Đổi kiểu dữ liệu của dòng thứ 2 từ string thành int
    setMode(iMode);             //Gán dữ liệu int đã quy đổi vào tham số gọi hàm setMode
    file.close();               //Đóng file lại
}

//------------
//Hàm ghi file data chứa thông tin đã lưu trữ
//---------------------------------------------------
void MainWindow::writeConfig(){
    QTextStream out(stdout);
    QFile file("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/data.txt");

    if(file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        out<<QString::number(iTemp)<<endl;
        out<<QString::number(iMode)<<endl;
    }else{
        qWarning("Loi! Khong mo duoc file.");
    }
    file.close();
}

void MainWindow::on_pushButton_Power_clicked()
{
    if(bFlagPowerOn==false){
        readConfig();
        ui->label_TempNumber->setVisible(true);
        ui->label_Do->setVisible(true);
        ui->label_ModeTunhien->setVisible(true);
        ui->label_ModeGio->setVisible(true);
        ui->label_ModeLanh->setVisible(true);
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
        writeConfig();
    }
}

void MainWindow::on_pushButton_TempTru_clicked()
{
    if(iTemp>iTempMin){
        iTemp--; //tăng nhiệt độ lên 1 độ và lưu lại vào biến
        ui->label_TempNumber->setText(QString::number(iTemp));
        writeConfig();
    }
}

void MainWindow::on_pushButton_Mode_clicked()
{
    if(iMode<3)
        iMode++;
    else if(iMode==3)
        iMode=1;
    setMode(iMode);
    writeConfig();
}

void MainWindow::on_pushButton_Read_clicked()
{
    QTextStream out(stdout);
    QFile file("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/data.txt");

    if(!file.open(QIODevice::ReadOnly)){
        qWarning("Loi! Khong the mo duoc file.");
    }
    QTextStream in(&file);
    ui->label_Readfile->setText("");
    while(!in.atEnd()){
        QString line = in.readLine();
        QString slable = ui->label_Readfile->text();
        ui->label_Readfile->setText(slable+" "+line);
        //ui->label_Readfile->setText(line);
    }
}

void MainWindow::on_pushButton_Write_clicked()
{
    QTextStream out(stdout);
    QFile file("D:/Repository/DEV-QT/PNUCS353/GUIDieuHoa/data.txt");

    if(file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        out<<QString::number(iTemp)<<endl;
        out<<QString::number(iMode)<<endl;
    }else{
        qWarning("Loi! Khong mo duoc file.");
    }
    file.close();
}
