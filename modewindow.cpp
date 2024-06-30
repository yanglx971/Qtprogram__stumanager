#include "modewindow.h"
#include "ui_modewindow.h"

ModeWindow::ModeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModeWindow)
{
    ui->setupUi(this);
}

ModeWindow::~ModeWindow()
{
    delete ui;
}

void ModeWindow::on_pushButton_teachermode_clicked()
{
    this->close();
    LoginWindow *pic = new LoginWindow();
    pic->settype(1);//老师用1表示
    pic->show();
}


void ModeWindow::on_pushButton_studentmode_clicked()
{
    this->close();
    LoginWindow *pic = new LoginWindow();
    pic->settype(2);//学生用2表示
    pic->show();
}


void ModeWindow::on_pushButton_school_clicked()
{
    this->close();
    SchoolEdit *pic = new SchoolEdit();
    pic->show();
}




void ModeWindow::on_pushButton_exit_clicked()
{
    this->close();
}

