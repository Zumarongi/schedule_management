#include "sign_up_window.h"
#include "ui_sign_up_window.h"
#include "sign_in_window.h"
#include "account.h"
#include <filesystem>
#include <QVBoxLayout>
#include <QHBoxLayout>


extern void showWarning(QString text);

void sign_up_window::setLayout(){
    this->setFixedSize(300,350);

    ui->username_label->move(30,73);
    ui->password_label->move(40,133);
    ui->confirm_label->setFixedSize(60,20);
    ui->confirm_label->move(15,190);

    QHBoxLayout *editLineLayout = new QHBoxLayout;              //输入栏布局
    {
        ui->lineEdit_username->setFixedSize(180,40);
        ui->lineEdit_username->move(75,60);
        ui->lineEdit_username->setStyleSheet("QLineEdit{border-radius:10px;}");
        editLineLayout->addWidget(ui->lineEdit_username);
        ui->lineEdit_password->setFixedSize(180,40);
        ui->lineEdit_password->move(75,120);
        ui->lineEdit_password->setStyleSheet("QLineEdit{border-radius:10px;}");
        editLineLayout->addWidget(ui->lineEdit_password);
        ui->lineEdit_confirm_password->setFixedSize(180,40);
        ui->lineEdit_confirm_password->move(75,180);
        ui->lineEdit_confirm_password->setStyleSheet("QLineEdit{border-radius:10px;}");
        editLineLayout->addWidget(ui->lineEdit_confirm_password);
    }

    QHBoxLayout *buttonLayout = new QHBoxLayout;                //按钮布局
    {
        ui->sign_up_button->setFixedSize(80,30);
        ui->sign_up_button->move(40,270);
        ui->sign_up_button->setStyleSheet("QPushButton{border-radius:8px;background-color:#148AFF;color:#FFFFFF;}");
        buttonLayout->addWidget(ui->sign_up_button);
        ui->cancel_button->setFixedSize(80,30);
        ui->cancel_button->move(180,270);
        ui->cancel_button->setStyleSheet("QPushButton{border-radius:8px;background-color:#148AFF;color:#FFFFFF;}");
        buttonLayout->addWidget(ui->cancel_button);
    }
}

sign_up_window::sign_up_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sign_up_window)
{
    ui->setupUi(this);
    sign_in_window *sign_in_page=new sign_in_window;

    setLayout();

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_confirm_password->setEchoMode(QLineEdit::Password);
    connect(ui->sign_up_button,&QPushButton::clicked,[=](){
        QString userName=ui->lineEdit_username->text();
        QString passWord=ui->lineEdit_password->text();
        QString confPassword=ui->lineEdit_confirm_password->text();
        bool existName=Account::isNameExist(userName);
        if(!existName&&(passWord==confPassword)&&!userName.isEmpty()&&!passWord.isEmpty()&&!confPassword.isEmpty()){
            Account *newAccount=new Account(userName, passWord);    //合法信息，注册成功，写入文件
            Account::addToList(userName);
            Account::saveAccountList();

            std::filesystem::path dir = ROOTDIR + "/data/" + userName.toStdString();
            std::filesystem::create_directories(dir);
            newAccount->saveToFile();

            delete newAccount;

            sign_in_page->show();
            this->close();
        }
        else{                   //注册失败提示
            if(userName.isEmpty()) showWarning("用户名不能为空！");
            else if(existName) showWarning("用户名已存在！");
            else if(passWord.isEmpty()) showWarning("密码不能为空！");
            else if(confPassword.isEmpty()) showWarning("请确认密码！");
            else showWarning("两次输入密码不相同！");
        }
    });
    connect(ui->cancel_button,&QPushButton::clicked,[=](){
        sign_in_page->show();               //取消按钮绑定槽函数
        this->close();
    });
}

sign_up_window::~sign_up_window()
{
    delete ui;
}
