#ifndef SPECIAL_TASK_H
#define SPECIAL_TASK_H
#include "casual_task.h"


class Special_task : public Casual_task
{
public:
    Special_task();
    Special_task(string task, string date, string category, string condition, string start_time, string end_time);
    string get_start()
    {
        return start_time;
    }
    string get_end()
    {
        return end_time;
    }
private:
    string end_time;
    string start_time;
};

#endif // SPECIAL_TASK_H
