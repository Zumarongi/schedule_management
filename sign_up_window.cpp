#include "sign_up_window.h"
#include "ui_sign_up_window.h"
#include "sign_in_window.h"
#include "account.h"
#include <filesystem>

sign_up_window::sign_up_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sign_up_window)
{
    ui->setupUi(this);
    sign_in_window *sign_in_page=new sign_in_window;
    ui->username_warning->hide();
    ui->conf_warning->hide();
    ui->empty_confpw_warning->hide();
    ui->emptyID_warning->hide();
    ui->emptypw_warning->hide();
    connect(ui->sign_up_button,&QPushButton::clicked,[=](){
        QString userName=ui->lineEdit_username->text();
        QString passWord=ui->lineEdit_password->text();
        QString confPassword=ui->lineEdit_confirm_password->text();
        bool existName=Account::isNameExist(userName);
        if(!existName&&(passWord==confPassword)&&!userName.isEmpty()&&!passWord.isEmpty()&&!confPassword.isEmpty()){
            Account *creAccount=new Account(userName,passWord);
            Account::addToList(userName);
            Account::saveAccountList();

            std::filesystem::path dir = ROOTDIR + "/data/" + userName.toStdString();
            std::filesystem::create_directories(dir);
            creAccount->saveToFile();

            sign_in_page->show();
            this->close();
        }
        else{
            if(userName.isEmpty()){
                ui->emptyID_warning->show();
                ui->username_warning->hide();
            }
            else if(existName){
                ui->username_warning->show();
                ui->emptyID_warning->hide();
            }
            else if(passWord.isEmpty()){
                ui->emptypw_warning->show();
                ui->emptyID_warning->hide();
                ui->username_warning->hide();
            }
            else if(confPassword.isEmpty()){
                ui->conf_warning->hide();
                ui->empty_confpw_warning->show();
                ui->emptypw_warning->hide();
                ui->emptyID_warning->hide();
                ui->username_warning->hide();
            }
            else{
                ui->conf_warning->show();
                ui->empty_confpw_warning->hide();
                ui->emptypw_warning->hide();
                ui->emptyID_warning->hide();
                ui->username_warning->hide();
            }
        }
    });
    connect(ui->cancel_button,&QPushButton::clicked,[=](){
        sign_in_page->show();
        this->close();
    });
}

sign_up_window::~sign_up_window()
{
    delete ui;
}
