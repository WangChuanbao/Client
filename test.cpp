#include "test.h"
#include <QDebug>
test::test(QObject *parent) :
    QObject(parent)
{
}

void test::onTest(const QString &strTime,
            const QString &strName,
            const QString &strDescription,
            const QString &strSeverity,
            const QColor &color)
{
    qDebug()<<"------------------"<<strTime<<strName<<endl;
}
