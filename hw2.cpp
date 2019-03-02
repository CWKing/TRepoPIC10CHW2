#include "hw2.h"
#include "ui_hw2.h"

hw2::hw2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hw2)
{
    ui->setupUi(this);
    QObject::connect(ui->HW1Slider,SIGNAL(valueChanged(int)),
    this,SLOT(update_overall(int)));
}

hw2::~hw2()
{
    delete ui;
}

void hw2::update_overall(int unused){
    double score = static_cast<double>(unused);

    ui->OverallScoreLCD->display(score);

    return;
}
