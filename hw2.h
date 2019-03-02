#ifndef HW2_H
#define HW2_H

#include <QMainWindow>

namespace Ui {
class hw2;
}

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

private:
    Ui::hw2 *ui;
};

#endif // HW2_H
