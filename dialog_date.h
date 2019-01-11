#ifndef DIALOG_DATE_H
#define DIALOG_DATE_H

#include <QDialog>

namespace Ui {
class Dialog_date;
}

class Dialog_date : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_date(QWidget *parent = 0);
    ~Dialog_date();
    QDate getDate();
private:
    Ui::Dialog_date *ui;
};

#endif // DIALOG_DATE_H
