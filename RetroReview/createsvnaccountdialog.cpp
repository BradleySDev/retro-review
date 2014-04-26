#include "createsvnaccountdialog.h"
#include "ui_createsvnaccountdialog.h"

CreateSvnAccountDialog::CreateSvnAccountDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateSvnAccountDialog)
{
    ui->setupUi(this);
    createConnections();
}

CreateSvnAccountDialog::~CreateSvnAccountDialog()
{
    delete ui;
}

void CreateSvnAccountDialog::acceptSvnData()
{
    svnLocation->append(ui->svnLocationEdit->text());
    svnUsername->append(ui->svnUsernameEdit->text());
    svnPassword->append(ui->svnPasswordEdit->text());

    this->close();
}

void CreateSvnAccountDialog::cancelSvnData()
{
    this->close();
}

void CreateSvnAccountDialog::createConnections()
{
    connect(ui->acceptButton, SIGNAL(clicked()), this, SLOT(acceptSvnData()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancelSvnData()));
}

void CreateSvnAccountDialog::initDialog(const QString& location, const QString& username, const QString& password)
{
    this->show();

    svnLocation = const_cast<QString*>(&location);
    svnUsername = const_cast<QString*>(&username);
    svnPassword = const_cast<QString*>(&password);

}
