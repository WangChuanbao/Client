#ifndef TEST_H
#define TEST_H

#include <QObject>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = 0);

signals:

public slots:
    void onTest(const QString &strTime,
                const QString &strName,
                const QString &strDescription,
                const QString &strSeverity,
                const QColor &color);
};

#endif // TEST_H
