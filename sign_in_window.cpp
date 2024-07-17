#include "sign_in_window.h"
#include "ui_sign_in_window.h"
#include "account.h"
#include <filesystem>
#include <fstream>

std::string encrypt(QString Qplaintext);

extern MainWindow *mainPage;
extern Account *currentAccount;

extern void showWarning(QString text);

sign_in_window::sign_in_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sign_in_window)
{
    ui->setupUi(this);

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
