#include "sign_in_window.h"
#include "ui_sign_in_window.h"
#include "account.h"
#include <filesystem>
#include <fstream>

std::string encrypt(QString Qplaintext);

MainWindow *mainPage;
Account *currentAccount;

sign_in_window::sign_in_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sign_in_window)
{
    ui->setupUi(this);

    Account::readAccountList();

    ui->empty_password_warning->hide();
    ui->empty_username_warning->hide();
    ui->error_password_warning->hide();
    ui->notfind_username_warning->hide();
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
                std::string s, encryptedPass;
                fin >> s >> encryptedPass;
                if (encryptedPass == encrypt(passWord))
                    samePassword = true;
                fin.close();
            }
        }
        if(existName&&!userName.isEmpty()&&!passWord.isEmpty()&&samePassword){
            currentAccount = new Account(userName);
            mainPage = new MainWindow;
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
