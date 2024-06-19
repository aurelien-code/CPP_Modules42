#include "Span.hpp"

#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

Span::Span(): _n(0)
{}

Span::Span(unsigned int N): _n(N)
{}

Span::Span(const Span &ref): _n(ref._n), _span(ref._span)
{}

Span &Span::operator=(const Span &ref)
{
	if (this != &ref)
	{
		_n = ref._n;
		_span = ref._span;
	}
	return (*this);
}

Span::~Span()
{}

void Span::addNumber(int value)
{
	if (_span.size() >= _n)
	{
		throw std::out_of_range("Span is already full");
	}
	_span.push_back(value);
}

template <typename I>
void Span::addNumbers(I start, I end)
{
	size_t dist = std::distance(start, end);
	if (dist + _span.size() > _n)
	{
		throw std::out_of_range("distance exceed max size available in Span");
	}
	_span.insert(_span.end(), start, end);
}

int Span::shortestSpan()
{
	const int INT_MAX = 2147483647;
	if (_span.size() < 2) {
        throw std::logic_error("Span size is too small to find the shortest");
    }
    std::vector<int> sorted = _span;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan()
{
	if (_span.size() < 2) {
        throw std::logic_error("Span size is too small to find the longest");
    }
    int minNumber = *std::min_element(_span.begin(), _span.end());
    int maxNumber = *std::max_element(_span.begin(), _span.end());
    return maxNumber - minNumber;
}