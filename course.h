#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QList>
#include <QHash>
#include <QTextStream>
#include <QMap>

class Course {
public:
    Course(int credits = 0, bool isMajor = false, const QString& teacherName = "", const QString& courseName = "");
    void addStudent(const QString& studentName);
    void setScore(const QString& studentName, int score);
    QString getTeacher() const;
    QString getCourse() const;
    QList<QString> getStudents() const;
    int getScore(const QString& studentName) const;
    void saveToFile(QTextStream &out) const;
    void loadFromFile(QTextStream &in);
    int findStudentScore(const QString& studentName) const;//利用学生名字查询分数函数，失败返回-1
    void setStudentScore(const QString & studentName, int score);//录入学生分数
    bool isMajorCourse()const;
    int getCredits()const;

private:
    int credits;
    bool isMajor;
    QString teacherName;
    QString courseName;
    QList<QString> studentNames;
    QMap<QString, int>studentScores;
};

#endif // COURSE_H

