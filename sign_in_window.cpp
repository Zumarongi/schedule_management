#include "sign_in_window.h"
#include "ui_sign_in_window.h"
#include"account.h"

sign_in_window::sign_in_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sign_in_window)
{
    ui->setupUi(this);
    //从各文件夹的名字中读取用户名，存入accouLists
    ui->empty_password_warning->hide();
    ui->empty_username_warning->hide();
    ui->error_password_warning->hide();
    ui->notfind_username_warning->hide();
    connect(ui->sign_in_Button,&QPushButton::clicked,[=](){\
        QString userName = ui->lineEdit_username->text();
        QString passWord = ui->lineEdit_password->text();
        bool existName=false,samePassword=false;
        for(int i=0;i<Account::accountLists.size();++i){
            if(userName==Account::accountLists[i]->Username){
                existName=true;
                if(Account::accountLists[i]->encryptedPass==passWord) samePassword=true;
            }
        }
        if(existName&&!userName.isEmpty()&&!passWord.isEmpty()&&samePassword){
            MainWindow *mainPage=new MainWindow;
            mainPage->show();
            this->close();
        }
        else{
            if(userName.isEmpty()){
                ui->empty_username_warning->show();
                ui->notfind_username_warning->hide();
            }
            else if(!existName){
                ui->notfind_username_warning->show();
                ui->empty_username_warning->hide();
            }
            else{
                if(passWord.isEmpty()){
                    ui->empty_password_warning->show();
                    ui->error_password_warning->hide();
                    ui->notfind_username_warning->hide();
                    ui->empty_username_warning->hide();
                }
                else{
                    ui->error_password_warning->show();
                    ui->empty_password_warning->hide();
                    ui->notfind_username_warning->hide();
                    ui->empty_username_warning->hide();
                }
            }
        }
    });
    connect(ui->sign_up_button,&QPushButton::clicked,[=](){
        sign_up_window *sign_up_Page=new sign_up_window;
        sign_up_Page->show();
        this->close();
    });
}

sign_in_window::~sign_in_window()
{
    delete ui;
}
