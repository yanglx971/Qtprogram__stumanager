#include "course.h"
#include <QDebug>>

Course::Course(int credits, bool isMajor, const QString& teacherName, const QString& courseName)
    : credits(credits), isMajor(isMajor), teacherName(teacherName), courseName(courseName) {}

void Course::addStudent(const QString& studentName) {
    if (!studentNames.contains(studentName)) {
        studentNames.append(studentName);
    } else {
        qDebug() << "Student" << studentName << "is already in the course.";
    }
}


void Course::setScore(const QString& studentName, int score) {
    studentScores[studentName] = score;
}

QString Course::getTeacher() const {
    return teacherName;
}

QString Course::getCourse() const {
    return courseName;
}

QList<QString> Course::getStudents() const {
    return studentNames;
}

int Course::getScore(const QString& studentName) const {
    return studentScores.value(studentName, -1);
}

void Course::saveToFile(QTextStream &out) const {
    out << courseName << '\n' << credits << '\n' << isMajor << '\n' << teacherName << '\n';
    out << studentNames.size() << '\n';
    for (const QString &student : studentNames) {
        out << student << '\n' << studentScores[student] << '\n';
    }
}

void Course::loadFromFile(QTextStream &in) {
    int numStudents;
    int tempIsMajor; // 临时变量
    in >> courseName >> credits >> tempIsMajor >> teacherName;
    isMajor = (tempIsMajor != 0); // 转换为bool类型
    in >> numStudents;
    studentNames.clear();
    studentScores.clear();
    for (int i = 0; i < numStudents; ++i) {
        QString student;
        int score;
        in >> student >> score;
        studentNames.append(student);
        studentScores[student] = score;
    }
}

bool Course::isMajorCourse() const
{
    return isMajor;
}

int Course::getCredits()const
{
    return credits;
}

int Course::findStudentScore(const QString& studentName) const
{
    if(studentScores.contains(studentName))
        return studentScores[studentName];
    else
        return -1;
}

void Course::setStudentScore(const QString & studentName, int score)
{
    studentScores[studentName] = score;
}
