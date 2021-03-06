#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pButton_Exit_clicked();

    void on_pButton_Hello_clicked();

    void on_pushButton1_clicked();

    void on_pButton_Luu_clicked();

    void on_pButton_Xoa_clicked();

    void on_pButton_Test_clicked();

    void on_pButton_TaiHinh_clicked();

    void initGiaoDien();

    void on_pButton_QString_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
