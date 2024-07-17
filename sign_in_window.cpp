#include "sign_in_window.h"
#include "ui_sign_in_window.h"
#include "account.h"
#include <filesystem>
#include <fstream>
#include <QVBoxLayout>
#include <QHBoxLayout>

std::string encrypt(QString Qplaintext);

extern MainWindow *mainPage;
extern Account *currentAccount;

#define _FONT(s) QFont("Times New Roman", (s))
#define FONT _FONT(10)

extern void showWarning(QString text);

void sign_in_window::setLayout(){
    this->setFixedSize(300,350);
    this->setWindowTitle("登录");

    ui->logo->setFixedSize(180,60);
    ui->logo->move(70,20);

    ui->username_label->move(25,113);
    ui->password_label->move(35,183);

    ui->username_label->setFont(FONT);
    ui->password_label->setFont(FONT);

    QVBoxLayout *editLineLayout = new QVBoxLayout;
    ui->lineEdit_username->setFixedSize(180,40);
    ui->lineEdit_username->move(70,100);
    ui->lineEdit_username->setFont(FONT);
    ui->lineEdit_username->setStyleSheet("QLineEdit{border-radius:10px;}");
    editLineLayout->addWidget(ui->lineEdit_username);
    ui->lineEdit_password->setFixedSize(180,40);
    ui->lineEdit_password->move(70,170);
    ui->lineEdit_password->setFont(FONT);
    ui->lineEdit_password->setStyleSheet("QLineEdit{border-radius:10px;}");
    editLineLayout->addWidget(ui->lineEdit_password);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    ui->sign_in_Button->setFixedSize(80,30);
    ui->sign_in_Button->move(40,270);
    ui->sign_in_Button->setFont(FONT);
    ui->sign_in_Button->setStyleSheet("QPushButton{border-radius:8px;background-color:#148AFF;color:#FFFFFF;}");
    buttonLayout->addWidget(ui->sign_in_Button);
    ui->sign_up_button->setFixedSize(80,30);
    ui->sign_up_button->move(180,270);
    ui->sign_up_button->setFont(FONT);
    ui->sign_up_button->setStyleSheet("QPushButton{border-radius:8px;background-color:#148AFF;color:#FFFFFF;}");
    buttonLayout->addWidget(ui->sign_up_button);
}

sign_in_window::sign_in_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sign_in_window)
{
    ui->setupUi(this);

    setLayout();

    Account::readAccountList();

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    connect(ui->sign_in_Button,&QPushButton::clicked,[=](){\
        QString userName = ui->lineEdit_username->text();
        QString passWord = ui->lineEdit_password->text();
        bool existName=Account::isNameExist(userName);
        bool samePassword=false;
        if (existName)
        {
            std::filesystem::path acc_path = ROOTDIR + "/data/" + userName.toStdString() + "/.acc";
            std::ifstream fin(acc_path);
            if (!fin.is_open())
                qDebug() << "Fail to open" << QString::fromStdString(acc_path.string());
            else
            {
                qDebug() << "[File" << acc_path.string() << "opened to read.]";
                std::string s, encryptedPass;
                fin >> s >> encryptedPass;
                if (encryptedPass == encrypt(passWord))
                    samePassword = true;
                fin.close();
                qDebug() << "[File" << acc_path.string() << "closed.]";
            }
        }
        if(existName&&!userName.isEmpty()&&!passWord.isEmpty()&&samePassword){
            currentAccount = new Account(userName);
            mainPage = new MainWindow;
            mainPage->show();
            this->close();
        }
        else{
            if(userName.isEmpty()) showWarning("用户名不能为空！");
            else if(!existName) showWarning("用户名不存在！");
            else showWarning("密码错误！");
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
