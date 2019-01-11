#ifndef MASSIVE_2_H
#define MASSIVE_2_H
#include "special_task.h"

class Massive_2
{
public:
    Massive_2();
    Massive_2(int length);
    ~Massive_2();
    void remove(int index);
    void insert(Special_task &value, int index);
    void resize(int newLength);
    void reallocate(int newLength);
    void clear();
    Special_task &getTask(int pos);
    int getLength()
    {
        return m_length;
    }
    void add(Special_task &obj);

private:
    int m_length;
    Special_task *m_data;
};

#endif // MASSIVE_H
