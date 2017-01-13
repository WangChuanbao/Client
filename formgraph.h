#ifndef FORMGRAPH_H
#define FORMGRAPH_H

#include <QWidget>
#include <QScrollBar>
#include <QStandardItemModel>
#include "formselectdata.h"
#include "networker.h"
#include "qcustomplot.h"
#include "recvmsgobject.h"

//即时数据存储的时长，超过此时长则查询历史库
#define INSTANT_CYCLE 3600*2
namespace Ui {
class FormGraph;
}

class FormGraph : public QWidget
{
    Q_OBJECT

public:
    QStandardItemModel *model;

    /**
     * @brief 用于区分网络请求
     */
    enum RemoteRequest {
        requestHostGroup,   //请求主机群组数据
        requestHost,        //请求主机数据
        requestItem,        //请求监控项
        requestWarning,     //请求告警
        requestChart,       //请求图表
        requestChart_history
    };
    explicit FormGraph(QWidget *parent = 0);
    ~FormGraph();

    /**
     * @brief 首页
     */
    void styleForHome();

    /**
     * @brief 图表
     */
    void styleForChart();

    /**
     * @brief 告警
     */
    void styleForWarning();

    /**
     * @brief 隐藏告警列表视图
     * @param hidden    true：隐藏    false：显示
     */
    void hiddenWarning(bool hidden);

    /**
     * @brief 隐藏图表视图
     * @param hidden    true：隐藏    false：显示
     */
    void hiddenGraph(bool hidden);
    void hiddenWarningTitle(bool hidden);
    void hiddenGraphTitle(bool hidden);

    void initializeSelect();
    void setCurrenHost(QString str);

    //绘制曲线图
    static void linegraph(QCustomPlot *customPlot, QVariantMap dataMap);
    static void piechart(QCustomPlot *customPlot, QVariantMap dataMap);

    static QVariantMap analyzeJson(QNetworkReply *reply);

    typedef struct {
    int r;
    int g;
    int b;
    } rgb ;

    rgb colorSwichRGB(const int color);

signals:
    void selectItem(const int index);
    void newWarning_all();  //有新告警数据发送
    void newWarning();      //有新告警数据，并且不是筛选条件发送
    void selectedHost(QString hostName);

private slots:
    void timeSelected(QString name, QString title);

    void selectDateTime(long startTime, long endTime);

    void timeUpDate();

    void on_allButton_clicked();

    void on_hostGroupBox_currentIndexChanged(const int index);

    void on_hostBox_currentIndexChanged(const int index);

    void on_graphBox_currentIndexChanged(const int index);

    void netWorkerResponse(QNetworkReply *);

    void onAddWaring(const QString &strTime,
                     const QString &strName,
                     const QString &strDescription,
                     const QString &strSeverity,
                     const QColor &color);

    void onPreUpdateData(const QDateTime& time);
    void onEndUpdateData(const QDateTime& time);

/*
    void onError(const QString &strError);
*/

    void solve_button_click(const int row);
    void ignore_button_click(const int row);
protected:
    virtual void resizeEvent(QResizeEvent *e);

private:
    Ui::FormGraph *ui;
    FormSelectData *_selectData;
    NetWorker *_netWorker;
    QMap<QNetworkReply *, RemoteRequest> _replyMap;
    QMap<RemoteRequest, QVariantMap> _graphData;

    QTimer *_timer;

    long _period;   //距离当前时间的秒数（早于当前时间）
    bool _isNew;    //记录数据是否是新数据
    long _lastWarningTime;  //当前数据最晚告警时间
    int _maxWidth;   //告警列表中最长告警信息的长度
    int _isHistory;     //记录是否查询历史库 0 未查询 ； 1 查询

    QString _currentGraphID;
    QString _currentHostName;

    QString m_lastUpdateTime;

    void getHostGroups();
    void getHosts(QString &group_id);
    void getItems(QString &host_id);
    void getWarning(QString &parameter);
    void getGraph(QString &parameter, const int isHistory = 0);
    void mergeData(QVariantMap map1, QVariantMap map2);
};

#endif // FORMGRAPH_H
