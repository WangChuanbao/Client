#include "config.h"
#include <QSettings>
#include <QDebug>

uint Config::getPort()
{
    int nRet = -1;
    QSettings setting(INI_FILE, QSettings::IniFormat);
    setting.beginGroup("socket");
    nRet = setting.value("port", "6000").toUInt();
    setting.endGroup();
    return nRet;
}

QString Config::getUrl()
{
    QSettings setting(INI_FILE, QSettings::IniFormat);
    setting.beginGroup("url");
    QString nRet = setting.value("url", "http://42.62.125.182:8080/zabbix/daping.php").toString();
    setting.endGroup();
    return nRet;
}

QString Config::getHistoryUrl()
{
    QSettings setting(INI_FILE, QSettings::IniFormat);
    setting.beginGroup("history-url");
    QString nRet = setting.value("history_url", "http://42.62.125.182:8080/zabbix/daping.php").toString();
    setting.endGroup();
    return nRet;
}


QString Config::getTopology(const int index)
{
    qDebug() << index << "====" << QString::number(index) << endl;
    QSettings setting(TOPOLOGY_FILE, QSettings::IniFormat);
    setting.beginGroup("ip");
    QString nRet = setting.value(QString::number(index), "").toString();
    setting.endGroup();
    return nRet;
}
