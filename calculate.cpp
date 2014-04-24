#include "calculate.h"
#include "ui_calculate.h"
#include "circle.h"

Calculate::Calculate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculate)
    {
       ui->setupUi(this);
    }

Calculate::~Calculate() {
    delete ui;
}

void Calculate::on_bCircle_clicked() {
    Circle* w = new Circle;
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    this->close();
}
