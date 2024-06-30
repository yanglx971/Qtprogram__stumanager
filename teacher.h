#ifndef TEACHER_H
#define TEACHER_H

#include <QString>
#include <QList>
#include <QSet>
#include "course.h"

class Teacher {
public:
    Teacher(int id = 0, const QString& name = "");
    void addCourse(QString course);
    // QList<Course*> getCourses() const;
    int getid() const;
    QString getName() const;
    QString getCourse() const;
    void saveToFile(QTextStream &out) const;
    void loadFromFile(QTextStream &in);

private:
    int id;
    QString name;
    QSet<QString> courses;
};

#endif // TEACHER_H
