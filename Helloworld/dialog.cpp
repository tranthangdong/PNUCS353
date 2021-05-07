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
    ui->label_ThongBao->setText("HelloWorld!");
}
