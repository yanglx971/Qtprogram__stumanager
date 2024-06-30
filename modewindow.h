#ifndef MODEWINDOW_H
#define MODEWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"
#include "schooledit.h"
#include "teacher.h"
#include "course.h"
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ModeWindow;
}
QT_END_NAMESPACE

class ModeWindow : public QMainWindow
{
    Q_OBJECT

public:
    ModeWindow(QWidget *parent = nullptr);
    ~ModeWindow();

private slots:
    void on_pushButton_teachermode_clicked();

    void on_pushButton_studentmode_clicked();

    void on_pushButton_school_clicked();


    void on_pushButton_exit_clicked();

private:
    Ui::ModeWindow *ui;
};
#endif // MODEWINDOW_H
