//
// Created by onni on 23.8.2023.
//

#pragma once
#include <iostream>
#include <algorithm>

template<typename T>
class DynamicArray
{
public:
    void Add(T item);
    void Remove(size_t index);
    T Get(size_t index) const;
    [[nodiscard]] size_t Length() const;
    DynamicArray();
    bool Contains(T item) const;
    DynamicArray(const DynamicArray<T>& other);
    DynamicArray& operator=(DynamicArray<T> other);
    ~DynamicArray() { delete[] m_array; }
private:
    void Grow();
    void Shrink();
    int m_top;
    int m_capacity;
    T* m_array;
};

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
        : m_top(other.m_top), m_capacity(other.m_capacity), m_array(new T[other.m_capacity])
{
    std::copy(other.array, other.array + other.top, m_array);
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T> other)
{
    std::swap(m_top, other.m_top);
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_array, other.m_array);
    return *this;
}

template<typename T>
DynamicArray<T>::DynamicArray()
{
    m_top = -1;
    m_array = new T[4];
    m_capacity = 4;
}

template<typename T>
void DynamicArray<T>::Add(T item)
{
    if (m_top + 1 == m_capacity) { Grow(); }
    m_array[++m_top] = item;
}

template<typename T>
void DynamicArray<T>::Grow()
{
    m_capacity *= 2;

    T* newArray = new T[m_capacity];

    for (int i = 0; i <= m_top; ++i)
    {
        newArray[i] = m_array[i];
    }

    delete[] m_array;
    m_array = newArray;
}

template<typename T>
size_t DynamicArray<T>::Length() const
{
    return m_top + 1;
}

template<typename T>
T DynamicArray<T>::Get(size_t index) const
{
    if (index <= m_top)
    {
        return m_array[index];
    }
    else
    {
        throw std::out_of_range("index out of bounds");
    }
}

template<typename T>
void DynamicArray<T>::Remove(size_t index)
{
    if (index <= m_top)
    {
        for (size_t i = index; i < m_top; ++i)
        {
            m_array[i] = m_array[i + 1];
        }
        --m_top;

        if (m_top < m_capacity / 4)
        {
            Shrink();
        }
    }
    else
    {
        throw std::out_of_range("index out of bounds");
    }
}

template<typename T>
void DynamicArray<T>::Shrink()
{
    if (m_top < m_capacity / 4)
    {
        m_capacity /= 2;
        T* newArray = new T[m_capacity];

        for (int i = 0; i <= m_top; ++i)
        {
            newArray[i] = m_array[i];
        }

        delete[] m_array;
        m_array = newArray;
    }
}

template<typename T>
bool DynamicArray<T>::Contains(T item) const
{
    for (int i = 0; i <= m_top; i++)
    {
        if (m_array[i] == item) { return true; }
    }

    return false;
}