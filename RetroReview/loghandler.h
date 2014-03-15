#ifndef LOGHANDLER_H
#define LOGHANDLER_H
#include <QString>


// This is a singleton
class LogHandler
{
public:
    static LogHandler* getInstance()
    {
        // The only instance
        // Guaranteed to be lazy initialized
        // Guaranteed that it will be destroyed correctly
        static LogHandler* instance;
        return instance;
    }
    bool write(QString message);

private:

    // Private Constructor
    LogHandler();
    // Stop the compiler generating methods of copy the object
    LogHandler(LogHandler const&);      // Not Implemented
    void operator=(LogHandler const&);  // Not Implemented

};

#endif // LOGHANDLER_H
