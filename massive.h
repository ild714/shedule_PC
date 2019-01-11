#ifndef MASSIVE_H
#define MASSIVE_H
#include "casual_task.h"

class Massive
{
public:
    Massive();
    Massive(int length);
    ~Massive();
    void remove(int index);
    void insert(Casual_task &value, int index);
    void resize(int newLength);
    void reallocate(int newLength);
    void clear();
    Casual_task &getTask(int pos);
    int getLength()
    {
        return m_length;
    }
    void add(Casual_task &obj);

private:
    int m_length;
    Casual_task *m_data;
};

#endif // MASSIVE_H
