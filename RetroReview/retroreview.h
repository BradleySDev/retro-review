#ifndef RETROREVIEW_H
#define RETROREVIEW_H

#include <QMainWindow>
#include "settingsdialog.h"
#include "configurationhandler.h"

namespace Ui {
class RetroReview;
}

class RetroReview : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RetroReview(QWidget *parent = 0);
    ~RetroReview();

public slots:
    void showSettingsDlg();

private:
    void createConnections();
    
private:
    Ui::RetroReview *ui;
    SettingsDialog settingsDlg;
    ConfigurationHandler configHandler;
};

#endif // RETROREVIEW_H
