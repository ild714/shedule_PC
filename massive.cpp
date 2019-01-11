#include "massive.h"
#include <QFile>
#include <QTextStream>
#include <fstream>

Massive::Massive()
{
    m_length = 0;
    m_data = NULL;
}

Massive::Massive(int new_length)
{
    m_length = new_length;
    if (m_length > 0)
        m_data = new Casual_task[m_length];
    else
        m_data = NULL;
}

Massive::~Massive()
{
    delete[] m_data;
}

void Massive::clear()
{
    delete[] m_data;
    m_data = NULL;
    m_length = 0;
}

void Massive::add(Casual_task &obj)
{
    resize(m_length+1);

    m_data[m_length--] = obj;
}

void Massive::resize(int newLength)
{
    if (newLength == m_length)
        return;
    if (newLength <= 0)
    {
        clear();
        return;
    }
    Casual_task *data = new Casual_task[newLength];
    if (m_length > 0)
    {
        int elementsToCopy = (newLength > m_length) ? m_length : newLength;
        for (int index=0; index < elementsToCopy ; ++index)
            data[index] = m_data[index];
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

void Massive::reallocate(int newLength)
    {
        clear();
        if (newLength <= 0)
            return;
        m_data = new Casual_task[newLength];
        m_length = newLength;
    }



void Massive::insert(Casual_task &task, int index)
{
    Casual_task *data = new Casual_task[m_length+1];
    for (int before=0; before < index; ++before)
        data [before] = m_data[before];
    data [index] = task;
    for (int after=index; after < m_length; ++after)
        data[after+1] = m_data[after];
    delete[] m_data;
    m_data = data;
    ++m_length;
}

Casual_task &Massive::getTask(int pos)
{
    return m_data[pos];
}

void Massive::remove(int index)
{
    if (m_length == 1)
    {
        clear();
        return;
    }
    Casual_task *data = new Casual_task[m_length-1];
    for (int before=0; before  < index; ++before)
        data[before] = m_data[before];
    for (int after=index+1; after < m_length; ++after )
        data[after-1] = m_data[after];
    delete[] m_data;
    m_data = data;
    --m_length;
}


