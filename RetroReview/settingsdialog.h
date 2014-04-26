#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QWidget>
#include "datamanager.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QWidget
{
    Q_OBJECT
    
public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

public slots:

    void createSvnAccount();

private:
    void createConnections();
    
private:
    Ui::SettingsDialog *ui;
    DataManager* dataMgr;
};

#endif // SETTINGSDIALOG_H
