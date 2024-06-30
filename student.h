#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QList>
#include <QSet>
#include "course.h"

class Student {
public:
    Student(int id = 0, const QString& name = "");
    void addCourse(QString coursename);
    QSet<QString> getCourses() const;
    QString getName() const;
    int getID() const;
    void saveToFile(QTextStream &out) const;
    void loadFromFile(QTextStream &in);
    QString findNameById(int id);
    int findIdByName(const QString &name);

private:
    int id;
    QString name;
    QSet<QString> courses;
};

#endif // STUDENT_H
