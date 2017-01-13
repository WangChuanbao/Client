#include "formleftview.h"
#include "ui_formleftview.h"

FormLeftView::FormLeftView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLeftView)
{
    ui->setupUi(this);

    _rects.append(QRect(236, 62, 33, 35));
    _rects.append(QRect(271, 62, 33, 35));
    _rects.append(QRect(429, 62, 33, 35));
    _rects.append(QRect(464, 62, 33, 35));
    _rects.append(QRect(612, 62, 33, 35));
    _rects.append(QRect(647, 62, 33, 35));
    _rects.append(QRect(196, 209, 26, 43));
    _rects.append(QRect(224, 209, 26, 43));
    _rects.append(QRect(284, 209, 26, 43));
    _rects.append(QRect(312, 209, 26, 43));
    _rects.append(QRect(388, 209, 26, 43));
    _rects.append(QRect(416, 209, 26, 43));
    _rects.append(QRect(477, 209, 26, 43));
    _rects.append(QRect(505, 209, 26, 43));
    _rects.append(QRect(81, 367, 33, 35));
    _rects.append(QRect(116, 367, 33, 35));
    _rects.append(QRect(184, 367, 33, 35));
    _rects.append(QRect(219, 367, 33, 35));
    _rects.append(QRect(281, 367, 33, 35));
    _rects.append(QRect(316, 367, 33, 35));
    _rects.append(QRect(428, 367, 33, 35));
    _rects.append(QRect(463, 367, 33, 35));
    _rects.append(QRect(172, 516, 42, 28));
    _rects.append(QRect(216, 516, 42, 28));
    _rects.append(QRect(274, 516, 42, 28));
    _rects.append(QRect(316, 516, 42, 28));
    _rects.append(QRect(416, 516, 42, 28));
    _rects.append(QRect(461, 516, 42, 28));
}

FormLeftView::~FormLeftView()
{
    delete ui;
}

void FormLeftView::mouseReleaseEvent(QMouseEvent *e)
{

        QRect rect;
        for (int i=0; i<_rects.length(); i++)
        {
            rect = calculateRect(_rects[i].left(),_rects[i].top(),_rects[i].right(),_rects[i].bottom());
            if (rect.contains(e->pos()))
            {
                //qDebug() << "----" << i+1 << endl;
                emit topologyClick(i+1);
            }
        }
}

void FormLeftView::resizeEvent(QResizeEvent *e)
{
    QRect rect = ui->widget->geometry();
    rect.setSize(e->size());
    ui->widget->setGeometry(rect);
}

QRect FormLeftView::calculateRect(int left, int top, int right, int bottom)
{
    QRect rect = this->geometry();
    QPoint lt(left/G_WIDTH*rect.width(),top/G_HEIGHT*rect.height());
    QPoint rb(right/G_WIDTH*rect.width(),bottom/G_HEIGHT*rect.height());
    QRect r(lt,rb);
    return r;
}
