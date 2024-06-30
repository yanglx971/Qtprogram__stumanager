#include "teachersearch.h"
#include "ui_teachersearch.h"
#include <QMessageBox>
#include "teacherview.h"
#include "globalcourse.h"
#include "globalteacher.h"

TeacherSearch::TeacherSearch(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherSearch)
{
    ui->setupUi(this);
}

TeacherSearch::~TeacherSearch()
{
    delete ui;
}

void TeacherSearch::setindex(int i)
{
    index = i;//第i门课
    // 创建一个 QStandardItemModel 对象
    model = new QStandardItemModel(this);

    // 设置列数
    model->setColumnCount(3);

    // 设置表头
    model->setHeaderData(0, Qt::Horizontal, "姓名");
    model->setHeaderData(1, Qt::Horizontal, "学号");
    model->setHeaderData(2, Qt::Horizontal, "成绩");

    // 将模型设置到 QTableView 中

    for(QString studentname:v_course[i].getStudents())
    {
        int row = model->rowCount();

        float score = v_course[index].findStudentScore(studentname);//根据学生名字返回成绩为float，这个类里index是由之前teacherview里找到的课程位置传入，等于之前那个循环里的i，可以由index直接访问某门课，你实现一门课如何根据学生姓名查成绩就行
                                // t_index是记录当前是哪个老师登录，用于返回上一个界面，如果找不到学生返回值设为-1，后面写了相关判断。
        int id = -1;//根据学生名字返回id
        for(int j=0;j<v_student.size();++j)
        {
            if(v_student[j].getName() == studentname)
            {
                id = v_student[j].getID();
            }
        }


        // 在新行添加数据
        qDebug()<<studentname<<' '<<id<<' '<<score<<'\n';
        model->setItem(row, 0, new QStandardItem(studentname));
        model->setItem(row, 1, new QStandardItem(QString::number(id)));
        model->setItem(row, 2, new QStandardItem(QString::number(score)));
    }ui->tableView->setModel(model);
}

void TeacherSearch::set_t_index(int i)
{
    t_index = i;
}

void TeacherSearch::on_pushButton_search_clicked()
{
    QString studentname = ui->lineEdit->text();
    float score = v_course[index].findStudentScore(studentname);//根据学生名字返回成绩,否则返回-1
    if(score>0)
        QMessageBox::information(0,"成功",QString::number(score));
    else
        QMessageBox::critical(0,"失败","该学生不在本校或未选择本课");
}


void TeacherSearch::on_pushButton_return_clicked()
{
    this->close();
    TeacherView *pic = new TeacherView();
    pic->setindex(t_index);
    pic->show();
}

