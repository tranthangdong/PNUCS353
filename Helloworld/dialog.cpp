#include "dialog.h"
#include "ui_dialog.h"
#include <QTextStream>

//Hàm khởi tạo - Là hàm chạy đầu tiên khi run chương trình
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    initGiaoDien();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initGiaoDien()
{
    //Load hình lên button
    QImage imgLuu("D:/Repository/DEV-QT/PNUCS353/Helloworld/mode_quat_off.png");
    //QImage imgLuu("D:/Repository/DEV-QT/PCS353/GUIDieuHoa/mode_quat_off.png");
    QIcon ButtonIcon(QPixmap::fromImage(imgLuu));
    ui->pButton_Luu->setIcon(ButtonIcon);
    ui->pButton_Luu->setIconSize(QPixmap::fromImage(imgLuu).rect().size());
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
    bool kiemtrahoten=true;
    //Kiểm tra ô họ tên có đúng kiểu dữ liệu không
    QString hoten = ui->textEdit_HoTen->toPlainText();
    foreach(QChar s, hoten) {
        if(s.isDigit()==true){
            kiemtrahoten=false;
        }
    }

    if(kiemtrahoten==true){
        //Tạo ra một row mới trong tableWidget
        int iSoDongDuLieu = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(iSoDongDuLieu);

        //Chèn dư liêu sinh viên vào row vừa tạo
        ui->tableWidget->setItem(iSoDongDuLieu,0, new QTableWidgetItem(ui->textEdit_HoTen->toPlainText()));     //chèn vào cột thứ 1 (cột tên)
        ui->tableWidget->setItem(iSoDongDuLieu,1, new QTableWidgetItem(ui->textEdit_NamSinh->toPlainText()));   //chèn vào cột thứ 2 (cột năm sinh)
        ui->tableWidget->setItem(iSoDongDuLieu,2, new QTableWidgetItem(ui->textEdit_DiaChi->toPlainText()));    //chèn vào cột thứ 3 (cột địa chỉ)
        ui->tableWidget->setItem(iSoDongDuLieu,3, new QTableWidgetItem(ui->comboBoxThanhpho->currentText()));   //chèn vào cột thứ 4 (cột thành phố)

        //Chèn dữ liệu sau khi kiểm tra Radiobutton
        if(ui->radioButtonNam->isChecked()==true)
        {
            ui->tableWidget->setItem(iSoDongDuLieu,4, new QTableWidgetItem("Nam"));
        }else if (ui->radioButtonNu->isChecked()==true)
        {
            ui->tableWidget->setItem(iSoDongDuLieu,4, new QTableWidgetItem("Nữ"));
        }

        QString sToHopMon="";
        //Chèn dữ liệu sau khi kiểm tra Checkbox
        if(ui->checkBox_Anh->isChecked())
            sToHopMon = sToHopMon+"Anh ; ";
        if(ui->checkBox_Hoa->isChecked())
            sToHopMon = sToHopMon+"Hóa ; ";
        if(ui->checkBox_Ly->isChecked())
            sToHopMon = sToHopMon+"Lý ; ";
        if(ui->checkBox_Sinh->isChecked())
            sToHopMon = sToHopMon+"Sinh ; ";
        if(ui->checkBox_Toan->isChecked())
            sToHopMon = sToHopMon+"Toán ; ";
        if(ui->checkBox_Van->isChecked())
            sToHopMon = sToHopMon+"Văn ; ";
        ui->tableWidget->setItem(iSoDongDuLieu,5, new QTableWidgetItem(sToHopMon));   //chèn vào cột thứ 5 (cột tổ hợp môn)


        //Chèn dữ liệu từ listWidget
        QString sKhuVuc="";
        sKhuVuc = ui->listWidgetKhuVuc->currentItem()->text();    //Lấy giá trị của iteam đang được select
        ui->tableWidget->setItem(iSoDongDuLieu,6, new QTableWidgetItem(sKhuVuc));   //chèn vào cột thứ 6 (khu vực)

        //Xóa trắng các textedit
        ui->textEdit_HoTen->setText("");
        ui->textEdit_NamSinh->setText("");
        ui->textEdit_DiaChi->setText("");
    }
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

void Dialog::on_pButton_Test_clicked()
{
    //ui->label_Test->setText(QString::number(ui->comboBoxThanhpho->currentIndex())); //Lấy vị trí hiện tại của item đang được lựa chọn
    //ui->label_Test->setText(QString::number(ui->comboBoxThanhpho->maxCount())); //Tổng số item mà combobox có thể chứa đựng bên trong nó
    ui->label_Test->setText(QString::number(ui->comboBoxThanhpho->count()));

}

void Dialog::on_pButton_TaiHinh_clicked()
{
    QString str1="123";

    //Load hình lên GraphicsViewer
    //QImage img("D:/Repository/DEV-QT/PNUCS353/Helloworld/PNU.png");
    //QPixmap pixmap("D:/Repository/DEV-QT/PNUCS353/Helloworld/PNU.png");
    //QGraphicsScene* scene = new QGraphicsScene();
    //QGraphicsView* view = new QGraphicsView(scene);
    //QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(img));
    //scene->addItem(item);

    //Load hình lên Label
    QImage imgLuu("D:/Repository/DEV-QT/PNUCS353/Helloworld/mode_quat_off.png");
    ui->label_Hinh->setPixmap(QPixmap::fromImage(imgLuu));

}

void Dialog::on_pButton_QString_clicked()
{
    //1. Khai báo khởi tạo chuỗi
    QString sChuoi1, sChuoi2, sChuoi3, sChuoi4;
    QString strChuoi1, strChuoi2;
    QString sChuoi = "Helloworld!";
    //1. Gán giá trị cho chuỗi
    strChuoi2 = "Goodbye";
    strChuoi1 = sChuoi; //Gán giá trị của sChuoi cho strChuoi1.

    //2. Hàm thêm nội dung vào chuỗi
    sChuoi1="Ho ";
    sChuoi2="va Ten";
    sChuoi3="1. ";

    sChuoi1.append(sChuoi2);    //Lấy nội dung chuỗi 2 gắn vào sau chuỗi 1.
    sChuoi1.prepend(sChuoi3);   //Lấy nội dung chuỗi 3 gắng vào đầu chuỗi 1.
    //ui->textEdit_QString->setText(sChuoi1);

    //3. Hàm viết hoa và viết thường
    sChuoi1 = sChuoi1.toUpper(); //toLower();
    //ui->textEdit_QString->setText(sChuoi1);

    //4. Các hàm lấy độ dài: size(), count() và length()
    int iSize = sChuoi1.size();
    int cSize = sChuoi1.count();
    int lSize = sChuoi1.length();

    //ui->textEdit_Size->setText(QString::number(iSize));
    //ui->textEdit_Size->setText(QString::number(cSize));
    //ui->textEdit_Size->setText(QString::number(lSize));

    //5. Các hàm lấy chuỗi con "1.Ho va Ten"
    QString sChuoiTam1 = sChuoi1.left(6);       //Lấy chuỗi con từ bên trái
    //QString sChuoiTam2 = sChuoi1.right(3);    //Lấy chuỗi con từ bên phải
    QString sChuoiTam2 = sChuoi1.mid(6,6);      //Lấy chuỗi con ở giữa
    //ui->textEdit_QString->setText(sChuoiTam1);
    //ui->textEdit_Size->setText(sChuoiTam2);

    //6. Duyệt chuỗi tìm thông tin
    sChuoi = "There are many stars.";

    //a. Loại vòng lặp 1-------------------
    foreach(QChar qc, sChuoi){
        //ui->textEdit_QString->append(qc);
        //ui->textEdit_QString->append("-");
    }

    //b. Loại vòng lặp 2-------------------
    for(QChar *it = sChuoi.begin() ; it!=sChuoi.end() ; ++it){
        //ui->textEdit_QString->append(*it);
        //ui->textEdit_QString->append("-");
    }

    //c. Loại vòng lặp 3-------------------
    for(int i=0; i<sChuoi.length(); i++){
        //ui->textEdit_QString->append(sChuoi.at(i));
        //ui->textEdit_QString->append("-");
    }

    //8. chuyển đổi kiểu dữ liệu:  toInt(), toFloat(), toLong(), setNum()
    int iNgay=14;
    QString sNgay="5";

    iNgay = iNgay + sNgay.toInt();

    sNgay = sNgay.setNum(iNgay);
    //ui->textEdit_Size->setText(sNgay);

    //9. kiểm tra dạng ký tự: isDigit(), isLetter(), isSpace()
    //10. edit chuỗi: remove, replace, clear
    sChuoi = "Truong Dai Hoc Duy Tan";
    //sChuoi.remove(0, 7);
    sChuoi.replace(0,6, "University");
    sChuoi.clear();     // = sChuoi="";
    ui->textEdit_QString->setText(sChuoi);




}
