#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "account.h"
#include <QCompleter>
#include <QVBoxLayout>
#include <vector>
#include <QDebug>

extern Account *currentAccount;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QVBoxLayout *mainLayout, *scrollLayout;
    QWidget *contentWidget;
    std::vector<Task *> taskOrder;
    QDateTime maxTime,minTime;
    int choosePrio;
    int chooseCtg;

    void setupInitValues();
    void setupMainLayout();
    void setupRemindThread();

    void taskFiltering();
    void taskOrdering();

    void removeTaskButton();
    void setupTaskButton();

private slots:
    void on_search_button_clicked();
    void on_add_task_button_clicked();
    void on_min_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);
    void on_max_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);
    void on_choose_order_currentIndexChanged(int index);
    void on_choose_priority_currentIndexChanged(int index);
    void on_choose_category_currentIndexChanged(int index);

protected:
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showButton();
    void removeButton();
    void del_done_task();

    QDateTime get_minTime() const;
    QDateTime get_maxTime() const;

    void set_minTime(QDateTime new_minTime);
    void set_maxTime(QDateTime new_maxTime);

signals:
    void reorder();
};

#endif // MAINWINDOW_H
