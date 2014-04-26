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

    updateSvnTable();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::createConnections()
{
    connect(ui->createSvnAccountButton, SIGNAL(clicked()), this, SLOT(createSvnAccount()));
    connect(dataMgr, SIGNAL(svnAccountsUpdated()), this, SLOT(updateSvnTable()));
}

void SettingsDialog::createSvnAccount()
{
    QString nickname;
    QString location;
    QString username;
    QString password;

    CreateSvnAccountDialog* csd = new CreateSvnAccountDialog();
    csd->initDialog(nickname, location, username, password);

    while (csd->isVisible())
    {
        qApp->processEvents();
    }

    dataMgr->addSvnAccount(nickname, location, username, password);

}

void SettingsDialog::updateSvnTable()
{
    QList<SvnAccountData> svnAccountList = dataMgr->getSvnAccounts();

    QStringList headers;
    headers.append("Nickname");
    headers.append("Active");
    headers.append("Status");
    ui->svnAccountTable->setColumnCount(headers.count());
    for (int i = 0; i < headers.count(); i++)
    {
        ui->svnAccountTable->setHorizontalHeaderItem(i, new QTableWidgetItem(headers.at(i)));
    }

    QHeaderView *headerView = new QHeaderView(Qt::Horizontal);
    ui->svnAccountTable->setHorizontalHeader(headerView);
    headerView->setSectionResizeMode(0, QHeaderView::Stretch);
    headerView->setSectionResizeMode(1, QHeaderView::Fixed);
    headerView->resizeSection(1, 60);
    headerView->setSectionResizeMode(2, QHeaderView::Fixed);
    headerView->resizeSection(2, 60);

    ui->svnAccountTable->setRowCount(svnAccountList.count());

    QList<SvnAccountData>::iterator i;
    int currentRow = 0;
    for (i = svnAccountList.begin(); i != svnAccountList.end(); ++i)
    {
        SvnAccountData currentData =(*i);
        ui->svnAccountTable->setItem(currentRow, 0, new QTableWidgetItem(currentData.nickname));
        QString isActive = currentData.active ? "FALSE" : "TRUE";
        ui->svnAccountTable->setItem(currentRow, 1, new QTableWidgetItem(isActive));
        QString isVerified = currentData.verifiedConnection ? "FALSE" : "TRUE";
        ui->svnAccountTable->setItem(currentRow, 2, new QTableWidgetItem(isVerified));
    }
    currentRow++;
}
