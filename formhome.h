#ifndef FORMHOME_H
#define FORMHOME_H

#include <QWidget>
#include <QRect>
#include <QPushButton>

namespace Ui {
class FormHome;
}

class FormHome : public QWidget
{
    Q_OBJECT

public:
    explicit FormHome(QWidget *parent = 0);
    ~FormHome();

signals:
    void newWarning_all();  //有新告警数据发送
    void newWarning();      //有新告警数据，并且不是筛选条件发送

protected:
    virtual void resizeEvent(QResizeEvent *e);
    //void mouseReleaseEvent(QMouseEvent *e);

private slots:
    /**
     * @brief 点击缩小右侧视图，再次点击恢复
     */
    void on_leftButton_clicked();

    /**
     * @brief 点击缩小左侧视图，再次点击恢复
     */
    void on_rightButton_clicked();

    void selectItem(const int index);

    void receiveNewWarning_all();  //有新告警数据发送
    void receiveNewWarning();      //有新告警数据，并且不是筛选条件发送
    void selectedHost(QString hostName);

    void topologyClicked(const int index);

private:
    Ui::FormHome *ui;

    /**
     * @brief 记录左侧按钮是否以点击（右侧视图是否缩小）
     */
    bool _leftBtnClicked;

    /**
     * @brief 记录右侧按钮是否点击
     */
    bool _rightBtnClicked;

    /**
     * @brief 记录右侧视图原位置和大小
     */
    QRect _oldReightViewRT;

    /**
     * @brief _oldLeftBtnRt
     */
    QRect _oldLeftViewRt;

    /**
     * @brief 缩放视图
     * @param w
     */
    void zoomView(QWidget *w);

    /**
     * @brief 还原视图
     * @param w
     */
    void resumeView();

    /**
     * @brief 设置按钮图标
     * @param btn
     * @param 图片地址
     */
    void setIcon(QPushButton *btn, QString &path);

    void setRightBtnClicked(bool r);
    void setLeftBtnClicked(bool r);
};

#endif // FORMHOME_H
