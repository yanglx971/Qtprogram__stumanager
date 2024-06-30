#include "schooledit.h"
#include "ui_schooledit.h"
#include "globalteacher.h"
#include <QFile>

SchoolEdit::SchoolEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SchoolEdit)
{
    ui->setupUi(this);
}

SchoolEdit::~SchoolEdit()
{
    delete ui;
}


void SchoolEdit::on_pushButton_addteacher_clicked()
{
    QString name = ui->lineEdit_name->text();
    int id = ui->lineEdit_id->text().toInt();
    bool tag = false;
    for(const Teacher & teacher_temp:v_teacher)
    {
        if(teacher_temp.getid() == id)
        {
            tag = true;
            break;
        }
    }
    if(!tag && id!=0)
    {
        Teacher teacher_temp = Teacher(id,name);
        v_teacher.append(teacher_temp);
    }
}


void SchoolEdit::on_pushButton_return_clicked()
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

    // 关闭文件

    for(int i=0;i<v_teacher.size();++i)
    {
        v_teacher[i].saveToFile(out);
    }
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
    file.close();

    this->close();
    ModeWindow *pic = new ModeWindow();
    pic->show();
}


void SchoolEdit::on_pushButton_addstudent_clicked()
{
    QString name = ui->lineEdit_name->text();
    int id = ui->lineEdit_id->text().toInt();

    bool tag = false;
    for(const Student & student_temp:v_student)
    {
        if(student_temp.getID() == id)
        {
            tag = true;
            break;
        }
    }
    if(!tag && id!=0)
    {
        Student student_temp = Student(id,name);
        qDebug()<<student_temp.getID()<<" "<<student_temp.getName();
        v_student.append(student_temp);
    }
}

