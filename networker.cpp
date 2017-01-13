#include "networker.h"
#include "config.h"
#include <QNetworkAccessManager>
#include <QTextStream>

class NetWorker::Private
{
public:
    Private(NetWorker *q) :
        manager(new QNetworkAccessManager(q))
    {}

    QNetworkAccessManager *manager;
};

/*
NetWorker *NetWorker::instance()
{
    static NetWorker netWorker;
    return &netWorker;
}
*/

NetWorker::NetWorker(QObject *parent) :
    QObject(parent),
    d(new NetWorker::Private(this))
{
    connect(d->manager, &QNetworkAccessManager::finished,
            this, &NetWorker::finished);
}

NetWorker::~NetWorker()
{
    delete d;
    d = 0;
}

void NetWorker::get(const QString &url)
{
    d->manager->get(QNetworkRequest(QUrl(url)));
}

void NetWorker::post(const QString &url, const QString &parameter)
{
    QByteArray data;
    data.append(parameter);
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/x-www-form-urlencoded"));
    d->manager->post(request, data);
}

QNetworkReply *NetWorker::requestUrl(const QString &url, const QString &parameter, const int isHistory, const QString &method)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    QString str;
    if (isHistory == 0)
    {
        str = Config::getUrl();
    }
    else {
        str = Config::getHistoryUrl();
    }
    str.append(url);

    if (method == "get")
    {
        str.append(parameter);
        cout << str << endl;
        return d->manager->get(QNetworkRequest(QUrl(str)));
    }
    else if (method == "post")
    {
       QByteArray data ;
       data.append(parameter);
       QNetworkRequest request;
       request.setUrl(QUrl(str));
       request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/x-www-form-urlencoded"));
       return d->manager->post(request, data);
    }
    return NULL;
}

