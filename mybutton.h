#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QStandardItem>

class MyButton : public QPushButton
{
    Q_OBJECT

public:
    MyButton();
    ~MyButton();

    QStandardItem *item;

    QColor color;

    //void setColor(QColor &color);

    void setItem(QStandardItem *item);

signals:
    void clicked(const int row);
protected:
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // MYBUTTON_H
