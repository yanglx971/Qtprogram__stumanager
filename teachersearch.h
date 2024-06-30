#ifndef TEACHERSEARCH_H
#define TEACHERSEARCH_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class TeacherSearch;
}

class TeacherSearch : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherSearch(QWidget *parent = nullptr);
    ~TeacherSearch();
    void setindex(int i);
    void set_t_index(int i);

private slots:
    void on_pushButton_search_clicked();

    void on_pushButton_return_clicked();

private:
    Ui::TeacherSearch *ui;
    int index;
    int t_index;
    QStandardItemModel *model;
};

#endif // TEACHERSEARCH_H
