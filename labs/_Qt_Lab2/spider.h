#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>
#include <QMouseEvent>

class Spider : public QWidget
{
    Q_OBJECT

public:
    Spider(QWidget *parent = 0);
    ~Spider();
private:
    QCursor* spCursor;
    bool isDrawing;
    bool isDrawing2; // for ex6 - draw Rect

    QPoint m_startPoint;
    QPoint m_curPoint;

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent * event);
};

#endif // SPIDER_H
