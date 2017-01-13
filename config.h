#ifndef CONFIG_H
#define CONFIG_H

#include <qglobal.h>

#define INI_FILE "./config.ini"
#define TOPOLOGY_FILE "./topology_conf.ini"

namespace Config
{
    uint getPort();
    QString getUrl();
    QString getHistoryUrl();
    QString getTopology(const int index);
}
#endif // CONFIG_H
