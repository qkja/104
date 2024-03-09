#include "form_small.h"
#include "ui_form_small.h"

Form_small::Form_small(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_small)
{
    ui->setupUi(this);
    void(QSpinBox::* spsignale)(int) =&QSpinBox::valueChanged;

    connect(ui->spinBox, spsignale,ui->verticalSlider, &QSlider::setValue);
    connect(ui->spinBox_2, spsignale,ui->verticalSlider_2, &QSlider::setValue);
    connect(ui->verticalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
    connect(ui->verticalSlider_2, &QSlider::valueChanged, ui->spinBox_2, &QSpinBox::setValue);
}

Form_small::~Form_small()
{
    delete ui;
}

void Form_small::setValse(Value v)
{
    ui->spinBox->setValue(v.max_val);
    ui->verticalSlider->setValue(v.max_val);
    ui->spinBox_2->setValue(v.min_val);
    ui->verticalSlider_2->setValue(v.min_val);
}

Value Form_small::getValse()
{
    Value v;
    v.max_val =  ui->spinBox->value();
    v.min_val =   ui->spinBox_2->value();
    return  v;
}
