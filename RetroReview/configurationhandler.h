#ifndef CONFIGURATIONHANDLER_H
#define CONFIGURATIONHANDLER_H
#include <QFile>

// This is a singleton
class ConfigurationHandler
{
public:
    static ConfigurationHandler* getInstance()
    {
        // The only instance
        // Guaranteed to be lazy initialized
        // Guaranteed that it will be destroyed correctly
        static ConfigurationHandler* instance;
        return instance;
    }
    QString getValue(QString var);
    int readConfigFile();
    bool setValue(QString var, bool value);
    bool setValue(QString var, int value);
    bool setValue(QString var, QString value);

private:
    // Private Constructor
    ConfigurationHandler();
    // Stop the compiler generating methods of copy the object
    ConfigurationHandler(ConfigurationHandler const&);      // Not Implemented
    void operator=(ConfigurationHandler const&);  // Not Implemented

};

#endif // CONFIGURATIONHANDLER_H
