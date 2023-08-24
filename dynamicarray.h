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
    int Length() const;
    DynamicArray();
    bool Contains(T item) const;
    DynamicArray(const DynamicArray<T>& other);
    DynamicArray& operator=(DynamicArray<T> other);
    ~DynamicArray() { delete[] array; }
private:
    void Grow();
    void Shrink();
    int top;
    int capacity;
    T* array;
};

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
        : top(other.top), capacity(other.capacity), array(new T[other.capacity])
{
    std::copy(other.array, other.array + other.top, array);
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T> other)
{
    std::swap(top, other.top);
    std::swap(capacity, other.capacity);
    std::swap(array, other.array);
    return *this;
}


template<typename T>
DynamicArray<T>::DynamicArray()
{
    top = -1;
    array = new T[4];
    capacity = 4;
}

template<typename T>
void DynamicArray<T>::Add(T item)
{
    if (top + 1 == capacity) { Grow(); }
    array[++top] = item;
}

template<typename T>
void DynamicArray<T>::Grow()
{
    capacity *= 2;

    T* newArray = new T[capacity];

    for (int i = 0; i <= top; ++i) 
    {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
}

template<typename T>
int DynamicArray<T>::Length() const
{
    return top + 1;
}

template<typename T>
T DynamicArray<T>::Get(size_t index) const
{
    if (!(index > top))
    {
        return array[index];
    }
    else
    {
        throw std::out_of_range("index out of bounds");
    }
}

template<typename T>
void DynamicArray<T>::Remove(size_t index)
{
    if (!(index > top))
    {
        for (int i = index; i < top; ++i)
        {
            array[i] = array[i + 1];
        }
        --top;

        if (top < capacity / 4)
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
    if (top < capacity / 4)
    {
        capacity /= 2;
        T* newArray = new T[capacity];

        for (int i = 0; i <= top; ++i) 
        {
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray;
    }
}

template<typename T>
bool DynamicArray<T>::Contains(T item) const
{
    for (int i = 0; i <= top; i++)
    {
        if (array[i] == item) { return true; }
    }

    return false;
}