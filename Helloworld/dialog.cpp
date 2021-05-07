#include "dialog.h"
#include "ui_dialog.h"

//Hàm khởi tạo
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pButton_Exit_clicked()
{
    close();
}

void Dialog::on_pButton_Hello_clicked()
{
    //ui->label_ThongBao->setText("HelloWorld!");
    //Nhiệm vụ:
    //1. Truy xuất vào giao diện chính
    //2. Gọi widget có tên là label_ThongBao
    //3. Gọi hàm setText thay đổi nội dung của QLabel
}

void Dialog::on_pushButton1_clicked()
{
    //ui->label_NhiemVu->setText("Nhiệm vu:\n\
        1. Truy xuất vào giao diện chính.\n\
        2. Gọi Widget có tên là label_NhiemVu\n\
        3. Gọi hàm setText thay đôi nội dung của Qlabel\n\
    ");

}

void Dialog::on_pButton_Luu_clicked()
{
    //Tạo ra một row mới trong tableWidget
    int iSoDongDuLieu = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(iSoDongDuLieu);

    //Chèn dư liêu sinh viên vào row vừa tạo
    ui->tableWidget->setItem(iSoDongDuLieu,0, new QTableWidgetItem(ui->textEdit_HoTen->toPlainText())); //chèn vào cột thứ 1 (cột tên)
    ui->tableWidget->setItem(iSoDongDuLieu,1, new QTableWidgetItem(ui->textEdit_NamSinh->toPlainText())); //chèn vào cột thứ 2 (cột năm sinh)
    ui->tableWidget->setItem(iSoDongDuLieu,2, new QTableWidgetItem(ui->textEdit_DiaChi->toPlainText())); //chèn vào cột thứ 3 (cột địa chỉ)

    //Xóa trắng các textedit
    ui->textEdit_HoTen->setText("");
    ui->textEdit_NamSinh->setText("");
    ui->textEdit_DiaChi->setText("");
}

void Dialog::on_pButton_Xoa_clicked()
{
    //Đém số dòng dữ liệu trong tablewidget
    int iSoDongDuLieu = ui->tableWidget->rowCount();
    //Kiểm tra có dữu liệu hay không (số dòng phải lớn 0)
    if(iSoDongDuLieu>0)
        //Xóa dòng cuối cùng
        //ui->tableWidget->removeRow(iSoDongDuLieu-1);    //Trừ 1 là vì số dòng dữ liệu được đánh số từ 0
    ui->tableWidget->removeRow(1);
}
