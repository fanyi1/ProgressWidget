#include "cycleprogress.h"
#include "ui_cycleprogress.h"
#include <QPainter>
#include <QBrush>
CycleProgress::CycleProgress(QWidget *parent, Orientation orientation ) :
    QWidget(parent),
    m_orientation(orientation),
    m_nindex(1),
    COUNT(12),
    m_color(Qt::blue),
    m_ntimer(-1)
{
}

CycleProgress::~CycleProgress()
{
}
void CycleProgress::start(int msec)
{
    if(m_ntimer < 0)
        m_ntimer = startTimer(msec);
}
void CycleProgress::stop()
{
    if(m_ntimer >= 0 )
    {
        killTimer(m_ntimer);
        m_ntimer = -1;
    }
}
void CycleProgress::timerEvent(QTimerEvent *event)
{
    if(++m_nindex > COUNT)
    {
        m_nindex = 1;
    }
    update();
}
void CycleProgress::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setBrush(m_color);
    painter.setPen(Qt::NoPen);
    painter.setWindow(-100,-100,200,200);
    for ( int i = m_nindex; i!= m_nindex - 1 && i <= COUNT ; )
    {
        painter.drawEllipse(0,-80,2.5*(COUNT - i),2.5*(COUNT - i));
        if(m_orientation == ClockWise)
            painter.rotate(-360 / COUNT);
        else
            painter.rotate(360 / COUNT);
        if(i == COUNT)
        {
            i = 0;
            continue;
        }
        i++;
    }
}
