#include "rectangle.h"
#include "ui_rectangle.h"
#include "calculate.h"

bool rhombus = false;

Rectangle::Rectangle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rectangle) {
        ui->setupUi(this);
    }

Rectangle::~Rectangle() {
    delete ui;
}

void Rectangle::on_bBack_clicked() {
    Calculate* w = new Calculate;
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    this->close();
}

void Rectangle::on_checkBox_toggled(bool checked) {
    if (checked) {
        ui->lAlt->setReadOnly(true);
        QPalette palette = ui->lAlt->palette();
        palette.setColor(QPalette::Base, QColor(230,230,230));
        ui->lAlt->setPalette(palette);
        ui->tBase->setText("One side:");
        ui->lArea->setText("");
        ui->lPeri->setText("");
        ui->lAlt->setText("");
        rhombus = true;
    }
    else {
        ui->lAlt->setReadOnly(false);
        QPalette palette = ui->lAlt->palette();
        palette.setColor(QPalette::Base, QColor(255,255,255));
        ui->lAlt->setPalette(palette);
        ui->tBase->setText("Base (Width):");
        ui->lArea->setText("");
        ui->lPeri->setText("");
        rhombus = false;
    }
}

void Rectangle::on_lBase_textEdited(const QString &arg1) {
    if (rhombus) {
        double baseImput = arg1.toDouble();
        ui->lPeri->setText(QString::number(baseImput * 4));
        ui->lArea->setText(QString::number(baseImput * baseImput));
    }
}
