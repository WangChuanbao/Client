#include "mybutton.h"
#include <QTextStream>

MyButton::MyButton()
{

}

MyButton::~MyButton()
{

}

void MyButton::setItem(QStandardItem *item)
{
    this->item = item;
}

void MyButton::mouseReleaseEvent(QMouseEvent *e)
{
    QPushButton::mouseReleaseEvent(e);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //cout << item->row() << "========" << endl;
    emit clicked(item->row());
}
