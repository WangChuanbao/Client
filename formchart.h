#ifndef FORMCHART_H
#define FORMCHART_H

#include <QWidget>

namespace Ui {
class FormChart;
}

class FormChart : public QWidget
{
    Q_OBJECT

public:
    explicit FormChart(QWidget *parent = 0);
    ~FormChart();

private:
    Ui::FormChart *ui;
};

#endif // FORMCHART_H
