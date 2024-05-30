#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T *items;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &ref);
        Array &operator=(const Array &ref);
        ~Array();

        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;

        unsigned int size() const; 
};

#include "Array.tpp"

#endif