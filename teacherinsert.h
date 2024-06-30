#ifndef TEACHERINSERT_H
#define TEACHERINSERT_H

#include <QWidget>

namespace Ui {
class TeacherInsert;
}

class TeacherInsert : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherInsert(QWidget *parent = nullptr);
    ~TeacherInsert();
    void setindex(int i);
    bool tmpIsMajor;

private slots:
    void on_pushButton_teacherinsert_clicked();

    void on_pushButton_Return_and_Save_clicked();

    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::TeacherInsert *ui;
    int index;// 记录现在是第几个teacher
};

#endif // TEACHERINSERT_H
