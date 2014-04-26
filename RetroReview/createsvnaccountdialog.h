#ifndef CREATESVNACCOUNTDIALOG_H
#define CREATESVNACCOUNTDIALOG_H

#include <QWidget>

namespace Ui {
class CreateSvnAccountDialog;
}

class CreateSvnAccountDialog : public QWidget
{
    Q_OBJECT
    
public:
    explicit CreateSvnAccountDialog(QWidget *parent = 0);
    ~CreateSvnAccountDialog();
    void initDialog(const QString& nickname, const QString& location, const QString& username, const QString& password);

public slots:
    void acceptSvnData();
    void cancelSvnData();

private:
    void createConnections();
    
private:
    Ui::CreateSvnAccountDialog *ui;
    QString* svnLocation;
    QString* svnUsername;
    QString* svnPassword;
    QString* svnNickname;
};

#endif // CREATESVNACCOUNTDIALOG_H
