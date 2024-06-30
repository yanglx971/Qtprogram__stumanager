#ifndef TEACHERVIEW_H
#define TEACHERVIEW_H

#include <QWidget>
#include "teacherinsert.h"

namespace Ui {
class TeacherView;
}

class TeacherView : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherView(QWidget *parent = nullptr);
    ~TeacherView();
    void setindex(int i);

    int getIndex(QString coursename);

private slots:
    void on_pushButton_insert_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_search_clicked();

private:
    Ui::TeacherView *ui;
    int index;

};

#endif // TEACHERVIEW_H
