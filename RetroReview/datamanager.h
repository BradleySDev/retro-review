#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QList>

typedef struct {
    QString location;
    QString username;
    QString password;
    bool verifiedConnection;
    bool active;
} SvnAccountData;

// This is a Singleton
class DataManager : public QObject
{
    Q_OBJECT

public:
    static DataManager* getInstance();
    void addSvnAccount(QString location, QString username, QString password);


private:
    // Private Constructor
    DataManager(){};
    // Stop the compiler generating methods of copy the object
    DataManager(DataManager const&);      // Not Implemented
    void operator=(DataManager const&);  // Not Implemented

    bool readStoredData(); // TODO - read binary data that has been stored (account info)

signals:
    void svnAccountsUpdated();

private:
    static DataManager* instance;
    QList<SvnAccountData> svnAccounts;
};

#endif // DATAMANAGER_H
