#ifndef RETROREVIEW_H
#define RETROREVIEW_H

#include <QMainWindow>

namespace Ui {
class RetroReview;
}

class RetroReview : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RetroReview(QWidget *parent = 0);
    ~RetroReview();
    
private:
    Ui::RetroReview *ui;
};

#endif // RETROREVIEW_H
