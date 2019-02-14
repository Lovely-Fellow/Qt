#include <QCoreApplication>
#include <QtCore/qglobal.h>
#include <QJsonValue>
#include <QMetaProperty>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QDebug>
#include "classdef.h"
#include "utils.h"

QObject* Utils::fromJson(const QMetaObject meta, QString& json)
{
    auto jsonObject = QJsonDocument::fromJson(json.toLatin1()).object();
    return fromJson(&meta, jsonObject);
}

QObject* Utils::fromJson(const QMetaObject* meta, QJsonObject& jsonObject)
{
    QObject* object = meta->newInstance();

    int propertyStart = QObject::staticMetaObject.propertyCount();
    for (int i = propertyStart; i < meta->propertyCount(); ++i) {
        QMetaProperty property = meta->property(i);
        if (!property.isWritable())
            continue;
        if (!jsonObject.contains(property.name()))
            continue;

        auto value = jsonValueToProperty(object, property, jsonObject.value(property.name()));
        property.write(object, value);
    }
    return object;
}

QVariant Utils::jsonValueToProperty(QObject* object, QMetaProperty& property, QJsonValue value)
{
    auto type = property.userType();
    auto typeName = QString(property.typeName());
    if (value.isArray()) {
        //todo array
        return QVariant::fromValue(value);
    } else if (value.isObject()) {
        switch (type) {
        default:
            auto  jsonObject = value.toObject();
            return QVariant::fromValue(fromJson(&FMoreInfo::staticMetaObject, jsonObject));
            break;
        }
        //todo other meta object types
    } else {
        //primitive types
        return value.toVariant();
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString json = "{"
                   "  \"name\": \"Andrew1\","
                   "  \"age\": 39,"
                   "  \"identifiers\": [32, 45, 67, 78],"
                   "  \"more\": {"
                   "    \"gps\": \"44.9064 W073 59.0735\","
                   "    \"valid\": true"
                   "  }"
                   "}";

    FPersonInfo*  person = (FPersonInfo*) Utils::fromJson(FPersonInfo::staticMetaObject, json);
    return a.exec();
}
