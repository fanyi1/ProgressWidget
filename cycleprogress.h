#ifndef CYCLEPROGRESS_H
#define CYCLEPROGRESS_H

#include <QWidget>
#include <QColor>

class CycleProgress : public QWidget
{
    Q_OBJECT

public:
    enum Orientation{ClockWise,AntiClockWise};
    explicit CycleProgress(QWidget *parent = 0, Orientation orientation = ClockWise);
    ~CycleProgress();
    Orientation orientation() const {return m_orientation;}
    void setOrientation(Orientation orientation) {m_orientation = orientation;}
    QColor& color() {return m_color;}
    void setColor(const QColor &color) {m_color = color;}
    void start(int msec);
    void stop();
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
private:
    Orientation m_orientation;
    int m_nindex;
    int m_ntimer;
    QColor m_color;
    const int COUNT ;
};

#endif // CYCLEPROGRESS_H
