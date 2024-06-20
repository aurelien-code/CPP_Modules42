#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		// Iterator
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
		
		void push(const T &value);
		void pop();
		T top();
		bool empty();
		size_t size();
};

#include "MutantStack.tpp"

#endif