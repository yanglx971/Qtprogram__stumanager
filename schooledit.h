#ifndef SCHOOLEDIT_H
#define SCHOOLEDIT_H

#include <QWidget>
#include "modewindow.h"

namespace Ui {
class SchoolEdit;
}

class SchoolEdit : public QWidget
{
    Q_OBJECT

public:
    explicit SchoolEdit(QWidget *parent = nullptr);
    ~SchoolEdit();

private slots:
    void on_pushButton_addteacher_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_addstudent_clicked();

private:
    Ui::SchoolEdit *ui;
};

#endif // SCHOOLEDIT_H
