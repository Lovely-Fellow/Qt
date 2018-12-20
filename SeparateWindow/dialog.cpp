#include "dialog.h"
#include "ui_dialog.h"
#include <QtWidgets>

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    secondWindow = new QDialog(this); //or QMainWindow, or your custom class

    QWidget *widget = new QWidget(secondWindow);
    QLabel *infoLabel;
    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"));
    infoLabel->setParent(secondWindow);
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(secondWindow);
    layout->setMargin(5);

    layout->addWidget(infoLabel);

    widget->setLayout(layout);

    secondWindow->setMinimumSize(160, 160);
    secondWindow->resize(480, 320);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
   if (!secondWindow)
       return;

    secondWindow->open();
    secondWindow->activateWindow();
}

void Dialog::on_pushButton_2_clicked()
{
    if (!secondWindow)
        return;

    secondWindow->show();
    secondWindow->activateWindow();
}

void Dialog::on_pushButton_3_clicked()
{
    if (!secondWindow)
        return;

    secondWindow->exec();
    secondWindow->activateWindow();
}
