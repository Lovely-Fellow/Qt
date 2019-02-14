#ifndef UTILS_H
#define UTILS_H
#include <QObject>

class Utils
{
public:
   Q_INVOKABLE Utils();
   static  QObject* fromJson(const QMetaObject* meta, QJsonObject& jsonObject);
   static  QObject* fromJson(const QMetaObject meta, QString& json);
   static  QVariant jsonValueToProperty(QObject* object, QMetaProperty& property, QJsonValue value);

};

#endif // UTILS_H
