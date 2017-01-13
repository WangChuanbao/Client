#ifndef NETWORKER_H
#define NETWORKER_H

#include <QObject>
#include <QNetworkReply>

class NetWorker : public QObject
{
    Q_OBJECT
public:
    //static NetWorker *instance();
    explicit NetWorker(QObject *parent = 0);
    ~NetWorker();

    void get(const QString &url);
    void post(const QString &url, const QString &parameter);
    /**
     * @brief requestUrl
     * @param isHistory 查询的是否是历史数据，0 否，1 是
     * @param url
     * @param parameter
     * @param method
     * @return
     */
    QNetworkReply* requestUrl(const QString &url, const QString &parameter = "", const int isHistory=0, const QString &method = "post");
signals:
    void finished(QNetworkReply *reply);
private:
    class Private;
    friend class Private;
    Private *d;

    NetWorker(const NetWorker &) Q_DECL_EQ_DELETE;
    NetWorker& operator=(NetWorker rhs) Q_DECL_EQ_DELETE;
};

#endif // NETWORKER_H
