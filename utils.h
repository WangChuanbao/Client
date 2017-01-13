#ifndef UTILS_H
#define UTILS_H
#include <qglobal.h>
#include <QStringList>

#define LOG_FILE "./log.txt"
#define LOCALDATA_FILE "./localdata.txt"
#define IGNOREDATA_FILE "./ignoredata.txt"

namespace Utils
{
    bool fileExist(const QString &filePath);
    void ignoreData(const QString &strLog);
    QStringList readIgnoreData();
    void clearIgnoreData();
    void recordData(const QString &strLog);
    QStringList readData();
    void clearData();
    void log(const QString &strLog);
    void log(int nLog);
    void log(int nLog, const QString &strLog);
    void log( const QString &strLog, int nLog);
    void log( const QString &strLog1, const QString &strLog2);
    void logText(const char *szText);
    void logFile(const QString &szText, const QString &szFile);
    void logFile(const QString &szText1, const QString &szText2, const QString &szFile);
    void logFile(const QString &szText1, int nText2, const QString &szFile);
}

#endif // UTILS_H
