#ifndef FORMPOLY_H
#define FORMPOLY_H

#include <QWidget>
#include <QGridLayout>
#include "networker.h"
#include "formselectdata.h"
#include "qcustomplot.h"

namespace Ui {
class FormPoly;
}

class FormPoly : public QWidget
{
    Q_OBJECT

public:
    explicit FormPoly(QWidget *parent = 0);
    ~FormPoly();

private slots:
    void netWorkerResponse(QNetworkReply *reply);

    void timeSelected(QString name, QString title);

    void selectDateTime(long startTime, long endTime);

    void timeUpDate();

    void on_comboBox_currentIndexChanged(int index);

protected:
    virtual void resizeEvent(QResizeEvent *e);

private:
    Ui::FormPoly *ui;
    QGridLayout *_glayout;
    FormSelectData *_selectData;

    NetWorker *_netWorker;
    QVector<QString> _graphidList;  //存储图形ID
    QMap<int, QCustomPlot *> _graphMap; //存储图形
    /**
     * 用于区分网络请求,value: 100:聚合图形分组    101:聚合图形    <100：聚合图形中的折线图
     **/
    QMap<QNetworkReply *, int> _replyMap;

    QTimer *_timer;
    long _period;   //距离当前时间的秒数
};

#endif // FORMPOLY_H
