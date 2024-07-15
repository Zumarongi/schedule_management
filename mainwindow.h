#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "account.h"
#include <QCompleter>
#include "task_info_window.h"
#include <QVBoxLayout>
#include <vector>
#include "create_task_window.h"
#include <QDebug>
#include "get_time_range.h"
#include "remindthread.h"

extern Account *currentAccount;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void auto_complete();
    void showButton();
    void removeButton();
    void del_done_task();

    QDateTime get_minTime() const;
    QDateTime get_maxTime() const;

    void set_minTime(QDateTime new_minTime);
    void set_maxTime(QDateTime new_maxTime);

private slots:
    void on_search_button_clicked();
    void on_add_task_button_clicked();

private:
    Ui::MainWindow *ui;
    QWidget *contentWidget;
    QVBoxLayout *layout;
    QDateTime maxTime,minTime;
    int choosePrio;
    int chooseCtg;
};

#endif // MAINWINDOW_H
