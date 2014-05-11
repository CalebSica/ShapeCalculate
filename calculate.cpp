#include "calculate.h"
#include "ui_calculate.h"
#include "circle.h"
#include "rectangle.h"
#include "sphere.h"

Calculate::Calculate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculate) {
       ui->setupUi(this);
    }

Calculate::~Calculate() {
    delete ui;
}

void Calculate::on_bCircle_clicked() {
    Circle* w = new Circle;
    w->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    this->close();
}

void Calculate::on_bRect_clicked() {
    Rectangle* w = new Rectangle();
    w->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    this->close();
}

void Calculate::on_bCircle_2_clicked() {
    Sphere* w = new Sphere();
    w->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    this->close();
}
