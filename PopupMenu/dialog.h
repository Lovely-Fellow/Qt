#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
//#define QT_NO_CONTEXTMENU
namespace Ui {
class Dialog;
}

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_customContextMenuRequested(const QPoint &pos);

private:
    Ui::Dialog *ui;

private slots:
     void cut();

private:
    void createActions();

    QAction *cutAct;
};

#endif // DIALOG_H
