#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>

class Spider : public QWidget
{
    Q_OBJECT

public:
    Spider(QWidget *parent = 0);
    ~Spider();
private:
    QCursor* spCursor;
};

#endif // SPIDER_H
