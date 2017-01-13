#ifndef RECVMSGOBJECT_H
#define RECVMSGOBJECT_H

#include <QObject>
#include <QTcpServer>

class RecvMsgObject : public QObject
{
    Q_OBJECT
public:
    explicit RecvMsgObject(QObject *parent = 0);
    ~RecvMsgObject();

    static RecvMsgObject *instance();

    void dealData();
    void loadLocalData();
signals:
    void sigNewTrigger(const QString &strTime,
                       const QString &strText,
                       const QString &strStatus,
                       const QString &strSeverity);

    void sigAddWarning(const QString &strTime,
                       const QString &strText,
                       const QString &strStatus,
                       const QString &strSeverity,
                       const QColor &color);

    void sigRemoveWarning(const QString &strTime,
                          const QString &strText,
                          const QString &strStatus,
                          const QString &strSeverity);

    void sigError(const QString &strError);

    void sigPreUpdateData(const QDateTime &upDateTime);
    void sigEndUpdateData(const QDateTime &upDateTime);

private slots:
    void onAcceptConnection();
    void onReadClient();

private:
    void dealOneWarning(const QString &text);

private:
    QTcpServer *m_pTcpServer;
    uint m_nPort;

    QString _body;
    char m_szBody[1025];
    char m_szBodyLenth[21];
};

#endif // RECVMSGOBJECT_H
