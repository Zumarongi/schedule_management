#include "sign_up_window.h"
#include "ui_sign_up_window.h"
#include "sign_in_window.h"
#include "account.h"
#include <filesystem>

extern void showWarning(QString text);

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
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_confirm_password->setEchoMode(QLineEdit::Password);
    connect(ui->sign_up_button,&QPushButton::clicked,[=](){\
        QString userName=ui->lineEdit_username->text();
        QString passWord=ui->lineEdit_password->text();
        QString confPassword=ui->lineEdit_confirm_password->text();
        bool existName=Account::isNameExist(userName);
        if(!existName&&(passWord==confPassword)&&!userName.isEmpty()&&!passWord.isEmpty()&&!confPassword.isEmpty()){
            Account *newAccount=new Account(userName, passWord);
            Account::addToList(userName);
            Account::saveAccountList();

            std::filesystem::path dir = ROOTDIR + "/data/" + userName.toStdString();
            std::filesystem::create_directories(dir);
            newAccount->saveToFile();

            delete newAccount;

            sign_in_page->show();
            this->close();
        }
        else{
            if(userName.isEmpty()) showWarning("用户名不能为空！");
            else if(existName) showWarning("用户名已存在！");
            else if(passWord.isEmpty()) showWarning("密码不能为空！");
            else if(confPassword.isEmpty()) showWarning("请确认密码！");
            else showWarning("两次输入密码不相同！");
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
