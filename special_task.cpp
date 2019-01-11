#include "special_task.h"

Special_task::Special_task() : Casual_task()
{
    start_time = "";
    end_time = "";
}

Special_task::Special_task(string task, string date, string category, string condition, string new_start_time, string new_end_time) : Casual_task(date, task, category, condition)
{
    start_time = new_start_time;
    end_time = new_end_time;
}
