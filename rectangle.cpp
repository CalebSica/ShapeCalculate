#include "rectangle.h"
#include "ui_rectangle.h"
#include "calculate.h"
#include "math.h"

bool square = false;

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
        square = true;
    }
    else {
        ui->lAlt->setReadOnly(false);
        QPalette palette = ui->lAlt->palette();
        palette.setColor(QPalette::Base, QColor(255,255,255));
        ui->lAlt->setPalette(palette);
        ui->tBase->setText("Base (Width):");
        ui->lArea->setText("");
        ui->lPeri->setText("");
        square = false;
    }
}

void Rectangle::on_lBase_textEdited(const QString &arg1) {
    if (square) {
        double baseImput = arg1.toDouble();
        ui->lPeri->setText(QString::number(baseImput * 4));
        ui->lArea->setText(QString::number(baseImput * baseImput));
    }
    else {
        if ((ui->lAlt->text() == "") && (ui->lArea->text() == "") && (ui->lPeri->text() == "")) {
            ui->lAlt->setPlaceholderText("Not enough info");
            ui->lArea->setPlaceholderText("Not enough info");
            ui->lPeri->setPlaceholderText("Not enough info");
        }
    }
}

void Rectangle::on_lArea_textEdited(const QString &arg1) {
    if (square) {
        double areaImput = arg1.toDouble();
        double side = sqrt(areaImput);
        ui->lBase->setText(QString::number(side));
        ui->lPeri->setText(QString::number(side * 4));
    }
    else {
        if ((ui->lAlt->text() == "") && (ui->lBase->text() == "") && (ui->lPeri->text() == "")) {
            ui->lAlt->setPlaceholderText("Not enough info");
            ui->lBase->setPlaceholderText("Not enough info");
            ui->lPeri->setPlaceholderText("Not enough info");
        }
    }
}

void Rectangle::on_lPeri_textEdited(const QString &arg1) {
    if (square) {
        double periImput = arg1.toDouble();
        double side = periImput / 4;
        ui->lBase->setText(QString::number(side));
        ui->lArea->setText(QString::number(side * side));
    }
    else {
        if ((ui->lAlt->text() == "") && (ui->lArea->text() == "") && (ui->lBase->text() == "")) {
            ui->lAlt->setPlaceholderText("Not enough info");
            ui->lArea->setPlaceholderText("Not enough info");
            ui->lBase->setPlaceholderText("Not enough info");
        }
    }
}

void Rectangle::on_lAlt_textEdited(const QString &arg1) {
    if (square) {}
    else {
        if ((ui->lBase->text() == "") && (ui->lBase->text() == "") && (ui->lPeri->text() == "")) {
            ui->lBase->setPlaceholderText("Not enough info");
            ui->lBase->setPlaceholderText("Not enough info");
            ui->lPeri->setPlaceholderText("Not enough info");
        }
    }
}
