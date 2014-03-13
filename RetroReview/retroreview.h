#ifndef RETROREVIEW_H
#define RETROREVIEW_H

#include <QMainWindow>
#include "settingsdialog.h"

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
};

#endif // RETROREVIEW_H
