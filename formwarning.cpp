#include "formwarning.h"
#include "ui_formwarning.h"

FormWarning::FormWarning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormWarning)
{
    ui->setupUi(this);

    ui->widget->styleForWarning();    
}

void FormWarning::initializeSelect()
{
    ui->widget->initializeSelect();
}

FormWarning::~FormWarning()
{
    delete ui;
}
