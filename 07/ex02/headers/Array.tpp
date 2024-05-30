#include "Array.hpp"
#include <iostream>
#include <exception>

template <typename T>
Array<T>::Array(): items(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n): items(new T[n]), _size(n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        items[i] = T();
    }
}

template <typename T>
Array<T>::Array(const Array &ref): items(NULL), _size(0)
{
    *this = ref;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &ref)
{
    if (this != &ref)
    {
        delete[] items;
        _size = ref._size;
        if (_size > 0)
        {
            items = new T(_size);
            for (unsigned int i = 0; i < _size; i++)
            {
                items[i] = ref.items[i];
            }
        }
        else
        {
            items = NULL;
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] items;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw std::out_of_range("Index out of range");
    }
    return (items[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
    {
        throw std::out_of_range("Index out of range");
    }
    return (items[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}