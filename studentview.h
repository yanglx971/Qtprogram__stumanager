#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QWidget>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class StudentView; }
QT_END_NAMESPACE

class StudentView : public QWidget
{
    Q_OBJECT

public:
    StudentView(QWidget *parent = nullptr);
    ~StudentView();

    void setindex(int id);

private slots:
    void on_pushButton_return_clicked();

    void on_pushButton_search_clicked();

private:
    Ui::StudentView *ui;
    int index;
};

#endif // STUDENTVIEW_H
