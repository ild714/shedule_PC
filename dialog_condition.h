#ifndef DIALOG_CONDITION_H
#define DIALOG_CONDITION_H

#include <QDialog>

namespace Ui {
class Dialog_condition;
}

class Dialog_condition : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_condition(QWidget *parent = 0);
    ~Dialog_condition();
    QString get_condition();

private:
    Ui::Dialog_condition *ui;
};

#endif // DIALOG_CONDITION_H
