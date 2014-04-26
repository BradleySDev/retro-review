#include "datamanager.h"

DataManager* DataManager::instance = NULL;

DataManager* DataManager::getInstance()
{
    // The only instance
    // Guaranteed to be lazy initialized
    // Guaranteed that it will be destroyed correctly
    if (!instance)
    {
       instance = new DataManager;
    }

    return instance;
}

void DataManager::addSvnAccount(QString nickname, QString location, QString username, QString password)
{
    SvnAccountData temp;
    temp.nickname = QString(nickname);
    temp.location = QString(location);
    temp.username = QString(username);
    temp.password = QString(password);
    temp.verifiedConnection = false;
    temp.active = true;

    svnAccounts.append(temp);

    emit svnAccountsUpdated();
}

QList<SvnAccountData> DataManager::getSvnAccounts()
{
    return svnAccounts;
}
