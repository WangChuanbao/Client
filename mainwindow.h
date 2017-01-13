#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QStackedLayout>
#include <QNetworkReply>
#include "recvmsgobject.h"
#include "formwarning.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void newWarning();
    void newWarning_all();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    long _warningCount_all;
    long _warningCount;
    QStackedLayout *_stack;
    //RecvMsgObject m_recvMsgObject;
    FormWarning *warning;
    void changeButtonColor(int index);
    void changeWarningPrompt();
};

#endif // MAINWINDOW_H
