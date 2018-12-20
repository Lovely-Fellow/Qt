#include "dialog.h"
#include "ui_dialog.h"
#include <QApplication>
#include <QtWebEngineWidgets/QWebEngineView>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

   QWebEngineView *view = new QWebEngineView(parent);
   view->load(QUrl("http://google.com/"));
   view->show();
}

Dialog::~Dialog()
{
    delete ui;
}
