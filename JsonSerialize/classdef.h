#ifndef CLASSDEF_H
#define CLASSDEF_H
#include <QObject>
#include <QVector>
#include <QDebug>
class FMoreInfo : public QObject {
   Q_OBJECT

   Q_PROPERTY( QString gps READ getGps WRITE setGps )
   Q_PROPERTY( bool valid READ getValid WRITE setValid)
    QString gps;
    bool valid;
public:
    Q_INVOKABLE FMoreInfo()
    {

    }
    void setGps(QString g)
    {
        gps = g;
    }
    void setValid(bool v)
    {
        valid = v;
    }
    QString getGps()
    {
        return gps;
    }
    bool getValid()
    {
        return valid;
    }
    void show()
    {
        qDebug() << "gps:"<< gps <<endl;
        qDebug() << "valid"<< valid <<endl;
    }
};

class FPersonInfo : public QObject {
   Q_OBJECT

   Q_PROPERTY( QString name WRITE setName )
   Q_PROPERTY( int age WRITE  setAge)
   Q_PROPERTY( QVector<int> identifiers WRITE setIdentifiers)
   Q_PROPERTY( FMoreInfo more WRITE setFMoreInfo)
   QString name;
   int age;
   QVector<int> *identifiers;
   FMoreInfo more;
public:
    Q_INVOKABLE FPersonInfo(){

    }
    void setName(QString n)
    {
        name = n;
    }
    void setAge(int a)
    {
        age = a;
    }
    void setIdentifiers(QVector<int> i)
    {
        identifiers = &i;
    }
    void setFMoreInfo(FMoreInfo& m)
    {
       more.setGps(m.getGps());
       more.setValid(m.getValid());
    }
    void show()
    {
         qDebug() << "name:"<< name <<endl;
         qDebug() << "age"<< age <<endl;
         qDebug() << "identifiers"<<identifiers<<endl;
          more.show();

    }
};
#endif // CLASSDEF_H
