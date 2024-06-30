#include "studentview.h"
#include "ui_studentview.h"
#include "globalteacher.h"
#include "globalcourse.h"
#include "course.h"
#include "student.h"
#include <QString>
#include <QDebug>
#include "modewindow.h"
#include <QMessageBox>>

StudentView::StudentView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentView)
{
    ui->setupUi(this);

}

StudentView::~StudentView()
{
    delete ui;
}

void StudentView::setindex(int id)
{
    index = id;
    QString str = v_student[index].getName();
    // ui->textBrowser->setPlainText(str);
    ui->textBrowser->setPlainText(str);
    int classnum;
    classnum = v_student[index].getCourses().size();
    qDebug()<<v_student[index].getName();

    // 设置行数和列数
    ui->tableWidget->setRowCount(classnum);
    ui->tableWidget->setColumnCount(4);

    // 设置表头
    QStringList headers = {"课程名称", "是否专业课", "学分", "成绩"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // 填充数据

    int row=0;
    for(QString tmpcourse:v_student[index].getCourses()){
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(tmpcourse));
        for(Course& course:v_course){
            if(course.getCourse()==tmpcourse){
                ui->tableWidget->setItem(row, 1, new QTableWidgetItem(course.isMajorCourse()?"是":"否"));
                ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(course.getCredits())));
                ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(course.getScore(v_student[index].getName()))));
            }
        }
        row++;
    }
}

void StudentView::on_pushButton_return_clicked()
{
    this->close();
    ModeWindow *pic = new ModeWindow();
    pic->show();
}


void StudentView::on_pushButton_search_clicked()
{
    QString coursename = ui->lineEdit_search->text();
    int c_index = -1;
    for(int i=0;i<v_course.size();++i)
    {
        if(v_course[i].getCourse() == coursename)
        {
            c_index = i;
        }
    }
    if(c_index<0)
        QMessageBox::critical(0,"失败","你未选择本课");
    else
    {
        float score = v_course[c_index].findStudentScore(v_student[index].getName());//根据学生名字返回成绩,否则返回-1
        bool isMajor = v_course[c_index].isMajorCourse();
        int credits = v_course[c_index].getCredits();
        QString str = "成绩：" + QString::number(score);
        str += '\n';
        QString str1 = isMajor?"专业课":"通选课";
        str += str1;
        str += '\n';
        str += "学分：";
        str += QString::number(credits);
        QMessageBox::information(0,"成功",str);
    }

}

