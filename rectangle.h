#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QDialog>

namespace Ui {
class Rectangle;
}

class Rectangle : public QDialog
{
    Q_OBJECT

public:
    explicit Rectangle(QWidget *parent = 0);
    ~Rectangle();

private slots:
    void on_bBack_clicked();

    void on_checkBox_toggled(bool checked);

    void on_lBase_textEdited(const QString &arg1);

private:
    Ui::Rectangle *ui;
};

#endif // RECTANGLE_H
