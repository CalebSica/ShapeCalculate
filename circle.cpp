#include "circle.h"
#include "ui_circle.h"
#include "math.h"

const double pi = 3.14159;

Circle::Circle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Circle)
    {
        ui->setupUi(this);
    }

Circle::~Circle()
{
    delete ui;
}

void Circle::on_radius_textEdited(const QString &arg1) {
    double radImput = ui->radius->text().toDouble();
    double area = pi * radImput * radImput;
    if (area == 0) {
        ui->area->setText("");
    }
    else {
        ui->area->setText(QString::number(area));
    }

    double cir = 2 * pi * radImput;
    if (cir == 0) {
        ui->circum->setText("");
    }
    else {
        ui->circum->setText(QString::number(cir));
    }
}

void Circle::on_circum_textEdited(const QString &arg1) {
    double area = (ui->circum->text().toDouble() * ui->circum->text().toDouble()) / (4 * pi);
    if (area == 0) {
        ui->area->setText("");
    }
    else {
        ui->area->setText(QString::number(area));
    }

    double radius = ui->circum->text().toDouble() / (2 * pi);
    if (radius == 0) {
        ui->radius->setText("");
    }
    else {
        ui->radius->setText(QString::number(radius));
    }
}

void Circle::on_area_textEdited(const QString &arg1) {
    double areaImput = ui->area->text().toDouble();
    double cir = 2 * sqrt(pi * areaImput);
    if (cir == 0) {
        ui->circum->setText("");
    }
    else {
        ui->circum->setText(QString::number(cir));
    }

    double radius = sqrt(areaImput / pi);
    if (radius == 0) {
        ui->radius->setText("");
    }
    else {
        ui->radius->setText(QString::number(radius));
    }
}
