#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "account.h"
#include <QCompleter>
#include "task_info_window.h"
#include <QVBoxLayout>

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

private slots:
    void on_search_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
