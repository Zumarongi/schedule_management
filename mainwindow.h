#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "account.h"
#include <QCompleter>
#include "task_info_window.h"
#include <QVBoxLayout>
#include <vector>
#include <ctime>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Account *currentAccount;

public:
    MainWindow(Account *getAccount,QWidget *parent = nullptr);
    ~MainWindow();
    void auto_complete();
    void showButton();
    void removeButton();
    void del_done_task();

private slots:
    void on_search_button_clicked();
    void on_add_task_button_clicked();

private:
    Ui::MainWindow *ui;
    QWidget *contentWidget;
    QVBoxLayout *layout;
    std::vector<Task *> taskOrder;
};
#endif // MAINWINDOW_H
