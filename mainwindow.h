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
    QWidget *contentWidget;
    QVBoxLayout *layout, *scrollLayout;
    std::vector<Task *> taskOrder;
    QDateTime maxTime,minTime;
    int choosePrio;
    int chooseCtg;

    void removeLayout();
    void showLayout();

private slots:
    void on_search_button_clicked();
    void on_add_task_button_clicked();

protected:
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void auto_complete();
    void del_done_task();

    QDateTime get_minTime() const;
    QDateTime get_maxTime() const;

    void set_minTime(QDateTime new_minTime);
    void set_maxTime(QDateTime new_maxTime);

signals:
    void reorder();
};

#endif // MAINWINDOW_H
