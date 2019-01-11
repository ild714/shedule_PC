#ifndef STATISTIC_H
#define STATISTIC_H

#include <QDialog>

namespace Ui {
class Statistic;
}

class Statistic : public QDialog
{
    Q_OBJECT

public:
    explicit Statistic(QWidget *parent = 0);
    ~Statistic();

private:
    Ui::Statistic *ui;
};

#endif // STATISTIC_H
