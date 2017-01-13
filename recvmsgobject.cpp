#include "recvmsgobject.h"
#include <QDebug>
#include <QTcpSocket>
#include <QColor>
#include <QDateTime>
#include "str.h"
#include "utils.h"
#include <QTextStream>

#define BUFFER_HEAD_LEN 20

#include "config.h"
#include <QDebug>

RecvMsgObject *RecvMsgObject::instance()
{
    static RecvMsgObject *netWorker = new RecvMsgObject();
    return netWorker;
}

RecvMsgObject::RecvMsgObject(QObject *parent) :
    QObject(parent)
{
    memset(m_szBody, 0, 1025);
    memset(m_szBodyLenth, 0, 21);

    m_nPort = Config::getPort();
    m_pTcpServer = new QTcpServer(this);
    connect(m_pTcpServer, SIGNAL(newConnection()), this, SLOT(onAcceptConnection()));
    if(false == m_pTcpServer->listen(QHostAddress::Any, m_nPort))
    {
        QString strError = QString("打开端口%1失败").arg(m_nPort);
        emit sigError(strError);
    }
}

RecvMsgObject::~RecvMsgObject()
{
    m_pTcpServer->close();
}

void RecvMsgObject::loadLocalData()
{
    QDateTime now = QDateTime::currentDateTime();
    emit sigPreUpdateData(now);
    if (Utils::fileExist(LOCALDATA_FILE))
    {
        QStringList list = Utils::readData();
        for(int i=0; i<list.length(); i++)
        {
            QString string = list.value(i);
            if (string == "")
                return;

//            qDebug() << "++++++++++" << string << endl;
//            QByteArray array = string.toLatin1();
//            char *str = array.data();
//            strcat_s(m_szBody, str);
            _body = string;
            dealData();
        }
    }
}

void RecvMsgObject::onAcceptConnection()
{
    //QTextStream cout(stdout, QIODevice::WriteOnly);
    QTcpSocket *clientConnection = m_pTcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(onReadClient()), Qt::QueuedConnection);
}

void RecvMsgObject::dealData()
{
    dealOneWarning(_body);
    memset(m_szBody, 0, 1025);
    memset(m_szBodyLenth, 0, 21);
}

void RecvMsgObject::onReadClient()
{
    qDebug()<<"nReadClient()"<<endl;
    static bool dealing = false;
    if(dealing == true)
    {
        return;
    }

    QTcpSocket *clientConnection = qobject_cast<QTcpSocket*>(sender());
    while (clientConnection->bytesAvailable())
    {
        if (strlen(m_szBodyLenth) < BUFFER_HEAD_LEN)
        {
            char strLen[21] = {0};
            clientConnection->read(strLen, BUFFER_HEAD_LEN-strlen(m_szBodyLenth));
            //strcat_s(m_szBodyLenth, strLen);
            strcat(m_szBodyLenth, strLen);

            QString strLog = QString("  =--head len--%1,%2,%3=").arg(strLen)
                    .arg(m_szBodyLenth).arg(strlen(m_szBodyLenth));
            memset(m_szBody, 0, 1025);

            continue;
        }

        bool ok = true;
        int nLen = QString(m_szBodyLenth).trimmed().toUInt(&ok);
        if(ok == false)
        {
            memset(m_szBody, 0, 1025);
            memset(m_szBodyLenth, 0, 21);
            continue;
        }

        if(nLen == 0)
        {
            memset(m_szBody, 0, 1025);
            memset(m_szBodyLenth, 0, 21);
            continue;
        }

        char buffer[1024] = {0};
        clientConnection->read(buffer, nLen-strlen(m_szBody));

        QString strLog = "";
        strLog = QString("  =--start--%1, %2, %3-=").arg(nLen-strlen(m_szBody)).arg(nLen).arg(strlen(m_szBody));
        //strcat_s(m_szBody, buffer);
        strcat(m_szBody, buffer);
        strLog = QString("  =-- =--body end---=--%1, %2, %3-=")
                .arg(nLen-strlen(m_szBody)).arg(nLen).arg(strlen(m_szBody));

        if ((int)strlen(m_szBody) == (int)nLen)//one full body
        {
            if(strcmp(m_szBody, "start") == 0)
            {
                Utils::clearData();
                memset(m_szBody, 0, 1025);
                memset(m_szBodyLenth, 0, 21);
                QDateTime now = QDateTime::currentDateTime();
                emit sigPreUpdateData(now);
            }
            else if(strcmp(m_szBody, "end") == 0)
            {
                memset(m_szBody, 0, 1025);
                memset(m_szBodyLenth, 0, 21);
                QDateTime now = QDateTime::currentDateTime();
                emit sigEndUpdateData(now);
            }
            else
            {
                Utils::recordData(QString::fromUtf8(m_szBody));
                _body = QString::fromUtf8(m_szBody);
                QTextStream cout(stdout, QIODevice::WriteOnly);
                cout << "newDATA ：" << _body << endl;
                dealData();
            }
        }
    }
    dealing = false;
}

void RecvMsgObject::dealOneWarning(const QString &text)
{
    Utils::log("-----dealOneWarning");
    Utils::log(text);
    QColor color;
    QStringList strList = text.split("|");
    QString strTime = strList.at(0);
    QString strName = strList.at(1);
    QString strDescription = strList.at(2);
    int nPriority = strList.at(3).toInt();
    QString strSeverity = "";

    if (nPriority == 0)
    {
        strSeverity = QString::fromLocal8Bit("未知");
        color = QColor("#C0C0C0");
    }
    else if(nPriority == 1)
    {
        strSeverity = QString::fromLocal8Bit("信息");
        color = QColor(89, 219, 143);
    }
    else if(nPriority == 2)
    {
        strSeverity = QString::fromLocal8Bit("警告");
        color = QColor("#FFC859");
    }
    else if(nPriority == 3)
    {
        strSeverity = QString::fromLocal8Bit("一般");
        color = QColor("#FFA059");
    }
    else if(nPriority == 4)
    {
        strSeverity = QString::fromLocal8Bit("严重");
        color = QColor("#E97659");
    }
    else if(nPriority == 5)
    {
        strSeverity = QString::fromLocal8Bit("灾难");
        color = QColor("#FF00FF");
    }
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //cout << "signal ----" << strName << " " << strDescription << " " << strTime << endl;
    emit sigAddWarning(strTime, strName, strDescription, strSeverity, color);
    //cout << "signal +++++++++++" <<endl;
}
