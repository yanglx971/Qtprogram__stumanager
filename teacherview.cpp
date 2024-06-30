#include "teacherview.h"
#include "ui_teacherview.h"
#include <QString>
#include "globalteacher.h"
#include "modewindow.h"
#include <QMessageBox>
#include "teachersearch.h"
#include "globalcourse.h"

TeacherView::TeacherView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherView)
{
    ui->setupUi(this);

}

TeacherView::~TeacherView()
{
    delete ui;
}

void TeacherView::on_pushButton_insert_clicked()
{
    this->close();
    TeacherInsert *pic = new TeacherInsert();
    pic->setindex(index);
    pic->show();
}

void TeacherView::setindex(int i)
{
    index = i;
    QString str = v_teacher[index].getName();
    // ui->textBrowser->setPlainText(str);
    str = str + v_teacher[index].getCourse();
    ui->textBrowser->setPlainText(str);
}


void TeacherView::on_pushButton_return_clicked()
{
    this->close();
    ModeWindow *pic = new ModeWindow();
    pic->show();
}

int TeacherView::getIndex(QString coursename)
{
    bool tag = false;
    for(int i=0;i<v_course.size();++i)// 这个类里的index是指当前登录的是哪个教师，在v_teacher里位于第index个
    {
         if(v_course[i].getCourse() == coursename)// v_course类似于v_teacher的实现，是一个课程的vector，用于存储所有的课程
         {                                        // 这段代码用于找到名为coursename的课程在v_course里的位置
             tag = true;
             qDebug()<<"\n"<<i;
             return i;
         }
     }
    if(!tag)
        return -1;
}


void TeacherView::on_pushButton_search_clicked()
{
    QString course = ui->lineEdit_search->text();
    int i = getIndex(course);
    TeacherSearch *pic = new TeacherSearch();
    pic->setindex(i);
    pic->set_t_index(index);
    this->close();
    pic->show();
}

