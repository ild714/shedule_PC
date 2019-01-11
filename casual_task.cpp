#include "casual_task.h"

Casual_task::Casual_task()
{
    task = "";
    date = "00.00.0000";
    category = "";
    condition =  "";
}

Casual_task::Casual_task(string new_date, string new_task, string new_category, string new_condition)
{
    task = new_task;
    date = new_date;
    category = new_category;
    condition =  new_condition;
}
