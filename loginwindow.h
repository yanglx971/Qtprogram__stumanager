#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "studentview.h"
#include "teacherview.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    void settype(int i)
    {
        type = i;
    }

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::LoginWindow *ui;
    int type;
};

#endif // LOGINWINDOW_H
