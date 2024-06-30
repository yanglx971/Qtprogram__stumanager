#include "teacher.h"
#include <QDebug>>

Teacher::Teacher(int id, const QString& name) : id(id), name(name) {}

void Teacher::addCourse(QString course) {
    if(!courses.contains(course))
    {
        courses.insert(course);
    }
}

// QList<Course*> Teacher::getCourses() const {
//     return courses;
// }

QString Teacher::getName() const {
    return name;
}

QString Teacher::getCourse() const {
    QString str = "\n";
    for(const QString& course:courses)
    {

        str = str + "\n";
        str = str + course;
    }
    return str;
}

int Teacher::getid() const {
    return id;
}

void Teacher::saveToFile(QTextStream &out) const {
    out << id << '\n' << name << '\n' << courses.size() << '\n';
    for (const QString &course : courses) {
        out << course << '\n';
    }
}

void Teacher::loadFromFile(QTextStream &in) {
    int numCourses;
    in >> id >> name >> numCourses;
    courses.clear();
    for (int i = 0; i < numCourses; ++i) {
        QString courseName;
        in >> courseName;
        courses.insert(courseName);
    }
}

