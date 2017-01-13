#include "utils.h"
#include <QFile>
#include <QDebug>

bool Utils::fileExist(const QString &filePath)
{
    QFile file(filePath);
    return file.exists();
}

void Utils::ignoreData(const QString &strLog)
{
    QFile file(IGNOREDATA_FILE);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
//        QMessageBox::critical(NULL, QString::fromLocal8Bit("提示"),
//                              QString::fromLocal8Bit("无法创建文件"));
        qDebug()<<"create local data file "<<IGNOREDATA_FILE<<" failed!!!"<<endl;
        return;
    }

    QTextStream out(&file);
    out<<strLog<<endl;
    out.flush();
    file.close();
}

QStringList Utils::readIgnoreData()
{
    QStringList fonts;
    QFile f(IGNOREDATA_FILE);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"open local data file "<<IGNOREDATA_FILE<<" failed!!!"<<endl;
        return fonts;
    }

    QTextStream data(&f);
    QString line;
    while (!data.atEnd())
    {
          line = data.readLine();
          line.remove('\n');
          fonts<<line;
    }
    return fonts;
}

void Utils::clearIgnoreData()
{
    QFile File(IGNOREDATA_FILE);
    File.resize(0);
}

void Utils::recordData(const QString &strLog)
{
    QFile file(LOCALDATA_FILE);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
//        QMessageBox::critical(NULL, QString::fromLocal8Bit("提示"),
//                              QString::fromLocal8Bit("无法创建文件"));
        qDebug()<<"create local data file "<<LOCALDATA_FILE<<" failed!!!"<<endl;
        return;
    }
    QTextStream out(&file);
    //out.setCodec("UTF-8");
    out<<strLog<<endl;
    out.flush();
    file.close();
}

QStringList Utils::readData()
{
    QStringList fonts;
    QFile f(LOCALDATA_FILE);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"open local data file "<<LOCALDATA_FILE<<" failed!!!"<<endl;
        return fonts;
    }

    QTextStream data(&f);
    //data.setCodec("UTF-8");
    //data.setCodec("GBK");
    QString line;
    while (!data.atEnd())
    {
          line = data.readLine();
          line.remove('\n');
          fonts<<line;
    }
    return fonts;
}

void Utils::clearData()
{
    QFile File(LOCALDATA_FILE);
    File.resize(0);
}

void Utils::log(const QString &strLog)
{
    QFile file(LOG_FILE);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
//        QMessageBox::critical(NULL, QString::fromLocal8Bit("提示"),
//                              QString::fromLocal8Bit("无法创建文件"));
        qDebug()<<"create log file "<<LOG_FILE<<" failed!!!"<<endl;
        return;
    }

    QTextStream out(&file);
    out<<strLog<<endl;
    out.flush();
    file.close();
}

void Utils::log(int nLog)
{
    QFile file(LOG_FILE);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
//        QMessageBox::critical(NULL, QString::fromLocal8Bit("提示"),
//                              QString::fromLocal8Bit("无法创建文件"));
        qDebug()<<"create log file "<<LOG_FILE<<" failed!!!"<<endl;
        return;
    }

    QTextStream out(&file);
    out<<nLog<<endl;
    out.flush();
    file.close();
}


void Utils::log(int nLog, const QString &strLog)
{
    QFile file(LOG_FILE);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
        qDebug()<<"create log file "<<LOG_FILE<<" failed!!!"<<endl;
        return;
    }

    QTextStream out(&file);
    out<<nLog<<" "<<strLog<<endl;
    out.flush();
    file.close();
}


void Utils::log(const QString &strLog, int nLog)
{
    QFile file(LOG_FILE);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
        qDebug()<<"create log file "<<LOG_FILE<<" failed!!!"<<endl;
        return;
    }

    QTextStream out(&file);
    out<<strLog<<" "<<nLog<<endl;
    out.flush();
    file.close();
}


void Utils::log(const QString &strLog1, const QString &strLog2)
{
    QFile file(LOG_FILE);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
        qDebug()<<"create log file "<<LOG_FILE<<" failed!!!"<<endl;
        return;
    }

    QTextStream out(&file);
    out<<strLog1<<" "<<strLog2<<endl;
    out.flush();
    file.close();
}

void Utils::logText(const char *szText)
{
    FILE* pFile = 0;
    //fopen_s(&pFile, LOG_FILE, "a");
    if(pFile == 0)
    {
        qDebug()<<"create log file "<<LOG_FILE<<" failed!!!"<<endl;
        return ;
    }
    fprintf(pFile, "%s\n",szText);
    fclose(pFile);
}


void Utils::logFile(const QString &szText, const QString &szFile)
{
    QFile file(szFile);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
        qDebug()<<"create log file "<<LOG_FILE<<" failed!!!"<<endl;
        return;
    }

    QTextStream out(&file);
    out<<szText<<endl;
    out.flush();
    file.close();
}


void Utils::logFile(const QString &szText1, const QString &szText2, const QString& szFile)
{
    QFile file(szFile);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
        qDebug()<<"create log file "<<LOG_FILE<<" failed!!!"<<endl;
        return;
    }

    QTextStream out(&file);
    out<<szText1<<"  "<<szText2<<endl;
    out.flush();
    file.close();
}


void Utils::logFile(const QString &szText1, int nText2, const QString &szFile)
{
    QFile file(szFile);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
        qDebug()<<"create log file "<<LOG_FILE<<" failed!!!"<<endl;
        return;
    }

    QTextStream out(&file);
    out<<szText1<<"  "<<nText2<<endl;
    out.flush();
    file.close();
}
