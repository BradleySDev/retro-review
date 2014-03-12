#include "retroreview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RetroReview w;
    w.show();
    
    return a.exec();
}
