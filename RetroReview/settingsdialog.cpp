#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "createsvnaccountdialog.h"
#include <QDebug>

#define STRING_LENGTH 100

SettingsDialog::SettingsDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    dataMgr = DataManager::getInstance();

    createConnections();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::createConnections()
{
    connect(ui->createSvnAccountButton, SIGNAL(clicked()), this, SLOT(createSvnAccount()));

}

void SettingsDialog::createSvnAccount()
{
    QString location;
    QString username;
    QString password;

    CreateSvnAccountDialog* csd = new CreateSvnAccountDialog();
    csd->initDialog(location, username, password);

    while (csd->isVisible())
    {
        qApp->processEvents();
    }

    dataMgr->addSvnAccount(location, username, password);

}
