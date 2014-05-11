#ifndef CALCULATE_H
#define CALCULATE_H

#include <QMainWindow>

namespace Ui {
class Calculate;
}

class Calculate : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculate(QWidget *parent = 0);
    ~Calculate();

private slots:
    void on_bCircle_clicked();

    void on_bRect_clicked();

    void on_bCircle_2_clicked();

private:
    Ui::Calculate *ui;
};

#endif // CALCULATE_H
