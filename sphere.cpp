#include "sphere.h"
#include "ui_sphere.h"
#include "calculate.h"

const double pi = 3.14159;

Sphere::Sphere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sphere) {
        ui->setupUi(this);
    }

Sphere::~Sphere() {
    delete ui;
}

void Sphere::on_pushButton_clicked() {
    Calculate* w = new Calculate;
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    this->close();
}

void Sphere::on_lRadius_textEdited(const QString& arg1) {
    double r = arg1.toDouble();
    ui->lArea->setText(QString::number((4/3) * pi * r * r));
    ui->lCir->setText(QString::number(2 * pi * r));
    ui->lVolume->setText(QString::number(4 * pi * r * r));
}
