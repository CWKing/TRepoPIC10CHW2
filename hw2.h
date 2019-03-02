#ifndef HW2_H
#define HW2_H

#include <QMainWindow>

namespace Ui {
class hw2;
}

int sum_sans_min(const int[]);

class hw2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit hw2(QWidget *parent = nullptr);
    ~hw2();

signals:
    void compute_overall();

public slots:
    void update_overall(int);
    void update_hw_score(int, int);
    void update_mt_score(int, int);
    void update_final_score(int);

private:
    Ui::hw2 *ui;
    int hw_scores[9] = {9,0};
    int mt_scores[3] = {3,0};
    int final_score[2] = {2,0};
    int grades[2] = {0};
};

#endif // HW2_H
