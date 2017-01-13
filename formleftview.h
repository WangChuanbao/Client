#ifndef FORMLEFTVIEW_H
#define FORMLEFTVIEW_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>

#define G_WIDTH 766.0
#define G_HEIGHT 798.0

namespace Ui {
class FormLeftView;
}

class FormLeftView : public QWidget
{
    Q_OBJECT

public:
    explicit FormLeftView(QWidget *parent = 0);
    ~FormLeftView();

protected:
    void mouseReleaseEvent(QMouseEvent *e);
    void resizeEvent(QResizeEvent *e);

signals:
    void topologyClick(const int index);

private:
    Ui::FormLeftView *ui;

    QVector<QRect> _rects;

    QRect calculateRect(int left, int top, int right, int bottom);
};

#endif // FORMLEFTVIEW_H
