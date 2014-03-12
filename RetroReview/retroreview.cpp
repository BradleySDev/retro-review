#include "retroreview.h"
#include "ui_retroreview.h"

RetroReview::RetroReview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RetroReview)
{
    ui->setupUi(this);
}

RetroReview::~RetroReview()
{
    delete ui;
}
