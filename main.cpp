#include "modewindow.h"
#include "globalteacher.h"
#include <QFile>
#include <QApplication>
QVector<Teacher> v_teacher;
QVector<Course> v_course;
QVector<Student> v_student;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModeWindow w;
    QString filePath = "D:\\Qtprogram\\data\\teacher.txt";

    // 打开文件
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return -1;
    }

    // 创建文本流
    QTextStream in(&file);


    while(!in.atEnd())
    {
        Teacher *teacher_temp = new Teacher();
        teacher_temp->loadFromFile(in);
        if(teacher_temp->getid()!=0)
            v_teacher.append(*teacher_temp);
    }
    file.close();

    //loading student
    QString filePath_stu = "D:\\Qtprogram\\data\\student.txt";

    // 打开文件
    QFile file_stu(filePath_stu);
    if (!file_stu.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file_stu.errorString();
        return -1;
    }

    // 创建文本流
    QTextStream in_stu(&file_stu);

    while(!in_stu.atEnd())
    {
        Student *student_temp = new Student();
        student_temp->loadFromFile(in_stu);
        if(student_temp->getID()!=0)
            v_student.append(*student_temp);
    }
    file_stu.close();

    //load course
    QString filePath_cou = "D:\\Qtprogram\\data\\course.txt";

    // 打开文件
    QFile file_cou(filePath_cou);
    if (!file_cou.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file_cou.errorString();
        return -1;
    }

    // 创建文本流
    QTextStream in_cou(&file_cou);

    while(!in_cou.atEnd())
    {
        Course *course_temp = new Course();
        course_temp->loadFromFile(in_cou);
        if(course_temp->getCredits()!=0)
            v_course.append(*course_temp);
    }
    file_cou.close();

    w.show();
    return a.exec();
}
