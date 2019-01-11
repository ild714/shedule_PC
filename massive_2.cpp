#include "Massive_2.h"
#include <QFile>
#include <QTextStream>
#include <fstream>

Massive_2::Massive_2()
{
    m_length = 0;
    m_data = NULL;
}

Massive_2::Massive_2(int new_length)
{
    m_length = new_length;
    if (m_length > 0)
        m_data = new Special_task[m_length];
    else
        m_data = NULL;
}

Massive_2::~Massive_2()
{
    delete[] m_data;
}

void Massive_2::clear()
{
    delete[] m_data;
    m_data = NULL;
    m_length = 0;
}

void Massive_2::add(Special_task &obj)
{
    resize(m_length+1);

    m_data[m_length--] = obj;
}

void Massive_2::resize(int newLength)
{
    if (newLength == m_length)
        return;
    if (newLength <= 0)
    {
        clear();
        return;
    }
    Special_task *data = new Special_task[newLength];
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

void Massive_2::reallocate(int newLength)
    {
        clear();
        if (newLength <= 0)
            return;
        m_data = new Special_task[newLength];
        m_length = newLength;
    }



void Massive_2::insert(Special_task &task, int index)
{
    Special_task *data = new Special_task[m_length+1];
    for (int before=0; before < index; ++before)
        data [before] = m_data[before];
    data [index] = task;
    for (int after=index; after < m_length; ++after)
        data[after+1] = m_data[after];
    delete[] m_data;
    m_data = data;
    ++m_length;
}

Special_task &Massive_2::getTask(int pos)
{
    return m_data[pos];
}

void Massive_2::remove(int index)
{
    if (m_length == 1)
    {
        clear();
        return;
    }
    Special_task *data = new Special_task[m_length-1];
    for (int before=0; before  < index; ++before)
        data[before] = m_data[before];
    for (int after=index+1; after < m_length; ++after )
        data[after-1] = m_data[after];
    delete[] m_data;
    m_data = data;
    --m_length;
}

