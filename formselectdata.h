#ifndef FORMSELECTDATA_H
#define FORMSELECTDATA_H

#include <QWidget>

namespace Ui {
class FormSelectData;
}

class FormSelectData : public QWidget
{
    Q_OBJECT

public:
    enum Style {
        styleHome,
        stylechart
    } style;

    explicit FormSelectData(QWidget *parent = 0);
    ~FormSelectData();

    void styleForHome();
    void styleForGraph();

    void changeButtonColor(QWidget *widget, QString &name);

    void initializeButtonColor();

signals:
    void selected(QString name, QString title);

    void selectedDateTime(long startTime, long endTime);

private slots:
    void on_dateFrom_dateTimeChanged(const QDateTime &dateTime);

    void on_dateTo_dateTimeChanged(const QDateTime &dateTime);

    void on_dateTo_2_dateTimeChanged(const QDateTime &dateTime);

    void on_dateFrom_2_dateTimeChanged(const QDateTime &dateTime);

protected:
    virtual void resizeEvent(QResizeEvent *e);
    bool eventFilter( QObject *, QEvent * );

private:
    Ui::FormSelectData *ui;

    long _startTime;
    long _endTime;

    /**
     * @brief 为此视图中的按钮安装事件过滤器
     */
    void installFilter(QWidget *);
    void buttonClicked(QString name, QString title);

    /**
     * @brief 判断 时间不为空，且开始时间早于结束时间。否则时间段选择不合法
     */
    void checkDateTime();

};

#endif // FORMSELECTDATA_H
