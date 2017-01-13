#ifndef FORMWARNING_H
#define FORMWARNING_H

#include <QWidget>

namespace Ui {
class FormWarning;
}

class FormWarning : public QWidget
{
    Q_OBJECT

public:
    explicit FormWarning(QWidget *parent = 0);
    ~FormWarning();

    void initializeSelect();

private:
    Ui::FormWarning *ui;
};

#endif // FORMWARNING_H
