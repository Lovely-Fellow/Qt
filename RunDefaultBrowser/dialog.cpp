#include "dialog.h"
#include "ui_dialog.h"
#include<QDesktopServices>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QDesktopServices::openUrl ( QUrl(ui->textEdit->toPlainText()) ); /*http://Google.com/*/
}
