#include "cycleprogress.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CycleProgress w(NULL,CycleProgress::Orientation::ClockWise);
    w.setColor(Qt::gray);
    w.show();
    w.start(100);
    return a.exec();
}
