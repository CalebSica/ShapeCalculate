#include "rectangle.h"
#include "ui_rectangle.h"
#include "calculate.h"
#include "math.h"

bool square = false;
bool oneChecked = false;
bool twoChecked = true;

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
    double baseImput = arg1.toDouble();
    if (square) {
        ui->lPeri->setText(QString::number(baseImput * 4));
        ui->lArea->setText(QString::number(baseImput * baseImput));
    }
    else {
        //double altImput = ui->lAlt->text().toDouble();
        //ui->lArea->setText(QString::number(baseImput * altImput));
        //ui->lPeri->setText(QString::number((baseImput + altImput) * 2));
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

    }
}

void Rectangle::on_lAlt_textEdited(const QString &arg1) {
    double altImput = arg1.toDouble();
    if (!square) {
        if ((ui->lBase->text() == "") && (ui->lBase->text() == "") && (ui->lPeri->text() == "")) {
            ui->lBase->setPlaceholderText("Not enough info");
            ui->lArea->setPlaceholderText("Not enough info");
            ui->lPeri->setPlaceholderText("Not enough info");
            ui->lAlt->setPlaceholderText("Not enough info");
        }
        else {
            //double baseImput = ui->lBase->text().toDouble();
            //ui->lArea->setText(QString::number(baseImput * altImput));
            //ui->lPeri->setText(QString::number((baseImput + altImput) * 2));
        }
    }
}
