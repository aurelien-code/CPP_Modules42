#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _span;
    
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &ref);
        Span &operator=(const Span &ref);
        ~Span();

        void addNumber(int value);
        //I stands for iterator
        template <typename I>
        void addNumbers(I start, I end);
        int shortestSpan();
        int longestSpan();
};

#include "Span.tpp"

#endif