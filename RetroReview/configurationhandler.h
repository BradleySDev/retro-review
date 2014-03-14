#ifndef CONFIGURATIONHANDLER_H
#define CONFIGURATIONHANDLER_H

#include <QFile>

class ConfigurationHandler
{
public:
    ConfigurationHandler();
    QString getValue(QString var);
    int readConfigFile();
    bool setValue(QString var, bool value);
    bool setValue(QString var, int value);
    bool setValue(QString var, QString value);
};

#endif // CONFIGURATIONHANDLER_H
