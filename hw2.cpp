#include "hw2.h"
#include "ui_hw2.h"

/*
 * connect(ComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxCourseLoadValues(int, int)));
 * connect(comboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
    [&](int index){ comboBoxCourseLoadValues(index, yourDefinedSecondParameter); });
 */

hw2::hw2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hw2)
{
    ui->setupUi(this);
    QObject::connect(ui->HW1Slider,static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged),
                     [&](int val){update_hw_score(val, 1); });

    QObject::connect(ui->HW2Slider,SIGNAL(valueChanged(int)),
        this,SLOT(update_hw_score(int, 2)));

    QObject::connect(ui->HW3Slider,SIGNAL(valueChanged(int)),
        this,SLOT(update_hw_score(int, 3)));

    QObject::connect(ui->HW4Slider,SIGNAL(valueChanged(int)),
        this,SLOT(update_hw_score(int, 4)));

    QObject::connect(ui->HW5Slider,SIGNAL(valueChanged(int)),
        this,SLOT(update_hw_score(int, 5)));

    QObject::connect(ui->HW6Slider,SIGNAL(valueChanged(int)),
        this,SLOT(update_hw_score(int, 6)));

    QObject::connect(ui->HW7Slider,SIGNAL(valueChanged(int)),
        this,SLOT(update_hw_score(int, 7)));

    QObject::connect(ui->HW8Slider,SIGNAL(valueChanged(int)),
        this,SLOT(update_hw_score(int, 8)));

    QObject::connect(ui->MT1Dial,SIGNAL(valueChanged(int)),
        this,SLOT(update_mt_score(int, 1)));

    QObject::connect(ui->MT2Dial,SIGNAL(valueChanged(int)),
        this,SLOT(update_mt_score(int, 2)));

    QObject::connect(ui->FEDial,SIGNAL(valueChanged(int)),
        this,SLOT(update_final_score(int)));

    QObject::connect(ui->CalculateButton,SIGNAL(clicked()),
    this,SLOT(update_overall()));
}

hw2::~hw2()
{
    delete ui;
}

int sum_sans_min(int toSum[]) {
    int min = toSum[1], sum = 0;
    for (int i = 1; i < toSum[0]; ++i) {
        if (toSum[i] < min) min = toSum[i];
        sum += toSum[i];
    };
    sum -= min;
    return sum;
};

void hw2::update_overall(){
    double HW_Score = sum_sans_min(hw_scores);
    grades[0] = (5.0 / 28) * HW_Score + (1.0 / 5) * (mt_scores[1] + mt_scores[2]) + (7.0 / 20) * final_score[1];
    grades[1] = (5.0 / 28) * HW_Score + (3.0 / 10) * sum_sans_min(mt_scores) + (11.0 / 25) * final_score[1];

    if(ui->SchemaAButton->isChecked()) ui->OverallScoreLCD->display(grades[0]);
    else ui->OverallScoreLCD->display(grades[1]);

    return;
}

void hw2::update_hw_score(int score, int hw_number){
    this->hw_scores[hw_number] = score;
};

void hw2::update_mt_score(int score, int mt_number){
    this->mt_scores[mt_number] = score;
};

void hw2::update_final_score(int score) {
  this->final_score[1] = score;
};

