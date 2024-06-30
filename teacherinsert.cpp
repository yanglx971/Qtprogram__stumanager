#include "teacherinsert.h"
#include "ui_teacherinsert.h"
#include "teacher.h"
#include "globalteacher.h"
#include "teacherview.h"
#include <QFile>
#include "globalcourse.h"

TeacherInsert::TeacherInsert(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherInsert)
{
    ui->setupUi(this);
}

TeacherInsert::~TeacherInsert()
{
    delete ui;
}

void TeacherInsert::on_pushButton_teacherinsert_clicked()
{
    QString coursename = ui->lineEdit_course->text();
    int creditnum = ui->lineEdit_credit->text().toInt(); // 需要一个输入学分的lineEdit
    int score = ui->lineEdit_score->text().toInt();
    int id = -1;
    int studentid = ui->lineEdit_studentid->text().toInt();
    // 添加老师
    v_teacher[index].addCourse(coursename);

    //添加课程
    bool tag = false;
    for(int i=0;i<v_course.size();++i)
    {
        if(v_course[i].getCourse() == coursename)
        {
            id = i;
            tag = true;
            break;
        }
    }
    if(!tag)
    {
        id = v_course.size();
        v_course.append(Course(creditnum, tmpIsMajor, v_teacher[index].getName(), coursename));
    }
    QString studentname = ui->lineEdit_studentname->text();
    v_course[id].addStudent(studentname);
    v_course[id].setStudentScore(studentname, score);
    qDebug()<<v_course[id].getCourse()<<' '<<studentname<<' '<<v_course[id].findStudentScore(studentname)<<' '<<v_course[id].getCredits()<<' '<<v_course[id].isMajorCourse();

    //添加学生
    for(Student& student:v_student){
        if(student.getID()==studentid){
            student.addCourse(coursename);
        }
    }
}

void TeacherInsert::setindex(int i)
{
    index=i;
}

void TeacherInsert::on_pushButton_Return_and_Save_clicked()
{
    // 文件路径
    QString filePath = "D:\\Qtprogram\\data\\teacher.txt";

    // 打开文件
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    // 创建文本流
    QTextStream out(&file);

    for(const Teacher & teacher_temp:v_teacher)
    {
        teacher_temp.saveToFile(out);
    }

    // 关闭文件
    file.close();

    // save student data
    // 文件路径
    QString filePath_stu = "D:\\Qtprogram\\data\\student.txt";

    // 打开文件
    QFile file_stu(filePath_stu);
    if (!file_stu.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file_stu.errorString();
        return;
    }

    // 创建文本流
    QTextStream out_stu(&file_stu);

    // 关闭文件

    for(int i=0;i<v_student.size();++i)
    {
        v_student[i].saveToFile(out_stu);
    }
    file_stu.close();

    // save course data
    // 文件路径
    QString filePath_cou = "D:\\Qtprogram\\data\\course.txt";

    // 打开文件
    QFile file_cou(filePath_cou);
    if (!file_cou.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file_cou.errorString();
        return;
    }

    // 创建文本流
    QTextStream out_cou(&file_cou);

    // 关闭文件

    for(int i=0;i<v_course.size();++i)
    {
        v_course[i].saveToFile(out_cou);
    }
    file_cou.close();

    this->close();
    TeacherView *pic = new TeacherView();
    pic->setindex(index);
    pic->show();
}

//用两个radio_button选择是否是专业课
void TeacherInsert::on_yesButton_clicked()
{
    tmpIsMajor = true;
}


void TeacherInsert::on_noButton_clicked()
{
    tmpIsMajor = false;
}

