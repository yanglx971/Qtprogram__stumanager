#include "student.h"
#include "globalstudent.h"

Student::Student(int id, const QString& name) : id(id), name(name) {}

void Student::addCourse(QString coursename) {
    courses.insert(coursename);
}

QSet<QString> Student::getCourses() const {
    return courses;
}

QString Student::getName() const {
    return name;
}

QString Student::findNameById(int id) {
    for (const Student &student : v_student) {
        if (student.getID() == id) {
            return student.getName();
        }
    }
    return ""; // 如果未找到，返回空字符串
}

int Student::findIdByName(const QString &name) {
    for (const Student &student : v_student) {
        if (student.getName() == name) {
            return student.getID();
        }
    }
    return -1; // 如果未找到，返回 -1
}

int Student::getID() const{
    return id;
}

void Student::saveToFile(QTextStream &out) const {
    out << id << '\n' << name << '\n' << courses.size() << '\n';
    for (const QString &course : courses) {
        out << course << '\n';
    }
}

void Student::loadFromFile(QTextStream &in) {
    int numCourses;
    in >> id >> name >> numCourses;
    courses.clear();
    for (int i = 0; i < numCourses; ++i) {
        QString courseName;
        in >> courseName;
        courses.insert(courseName);
    }
}
