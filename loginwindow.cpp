#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "globalteacher.h"
#include <QFile>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    if(type == 1)//老师
    {

        int id = ui->lineEdit_account->text().toInt();
        QString name = ui->lineEdit_password->text();
        bool tag = false;
        for(int i=0;i<v_teacher.size();++i)
        {
            if(v_teacher[i].getid() == id && v_teacher[i].getName() == name)
            {
                tag = true;
                this->close();
                TeacherView *pic = new TeacherView();
                pic->setindex(i);
                qDebug() << i;
                pic->show();
            }
        }
        if(!tag)
            QMessageBox::critical(0,"登录失败","id或姓名错误");
    }
    else if(type == 2)//学生
    {
        int id = ui->lineEdit_account->text().toInt();
        QString name = ui->lineEdit_password->text();
        bool tag = false;
        for(int i = 0;i<v_student.size();++i){
            if(v_student[i].getID() == id && v_student[i].getName() == name){
                this->close();
                tag = true;
                StudentView *pic = new StudentView();
                pic->setindex(i);
                pic->show();
            }
        }
        if(!tag)
            QMessageBox::critical(0,"登录失败","id或姓名错误");
    }
}

