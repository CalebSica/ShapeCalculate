#ifndef SPHERE_H
#define SPHERE_H

#include <QDialog>

namespace Ui {
class Sphere;
}

class Sphere : public QDialog
{
    Q_OBJECT

public:
    explicit Sphere(QWidget *parent = 0);
    ~Sphere();

private slots:
    void on_pushButton_clicked();

    void on_lRadius_textEdited(const QString &arg1);

private:
    Ui::Sphere *ui;
};

#endif // SPHERE_H
