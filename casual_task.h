#ifndef CASUAL_TASK_H
#define CASUAL_TASK_H
#include <string>
#include <QString>
#include <QDateTime>
using namespace std;

class Casual_task
{
public:
    Casual_task();
    Casual_task(string task, string date, string category, string condition);
    string get_date()
    {
        return date;
    }
    string get_task()
    {
        return task;
    }
    string get_category()
    {
        return category;
    }
    string get_condition()
    {
        return condition;
    }
    void set_condition(string new_condition)
    {
        condition = new_condition;
    }
protected:
    string task;
    string date;
    string condition;
    string category;
};

#endif // CASUAL_TASK_H
