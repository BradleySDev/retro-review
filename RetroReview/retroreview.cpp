#include "retroreview.h"
#include "ui_retroreview.h"
#include "QDebug"


RetroReview::RetroReview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RetroReview)
{
    ui->setupUi(this);

    createConnections();

}

RetroReview::~RetroReview()
{
    delete ui;
}

void RetroReview::createConnections()
{
    connect (ui->settingsButton, SIGNAL(clicked()), this, SLOT(showSettingsDlg()));
}

void RetroReview::showSettingsDlg()
{
    settingsDlg.show();
}
