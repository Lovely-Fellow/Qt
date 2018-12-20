#include "dialog.h"
#include "ui_dialog.h"
#include <QtWidgets>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    createActions();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_customContextMenuRequested(const QPoint &pos)
{
    QMenu menu(ui->pushButton);
    menu.addAction(cutAct);
    menu.exec( QCursor::pos());
}



void Dialog::cut()
{

}


void Dialog::createActions()
{

    cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, &QAction::triggered, this, &Dialog::cut);


}
