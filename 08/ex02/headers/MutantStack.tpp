#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template <typename T> 
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{}

template <typename T> 
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
    if (this == &other)
        return *this;
    std::stack<T>::operator=(other);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

template <typename T>
void MutantStack<T>::push(const T &value)
{
    std::stack<T>::push(value);
}

template <typename T>
void MutantStack<T>::pop()
{
    std::stack<T>::pop();
}

template <typename T>
T MutantStack<T>::top()
{
    return std::stack<T>::top();
}

template <typename T>
bool MutantStack<T>::empty()
{
    return std::stack<T>::empty();
}

template <typename T>
size_t MutantStack<T>::size()
{
    return std::stack<T>::size();
}
