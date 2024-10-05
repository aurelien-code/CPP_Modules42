#include "pMergeMe.hpp"


template <typename C>
void    PMergeMe::create_pairs(C& seq, pair_list& pairs)
{
	typename C::iterator	it = seq.begin();

	while (it != seq.end())
	{
		int first = *it;
		++it;
		if (it != seq.end())
		{
			int second = *it;
			pairs.push_back(std::make_pair(first, second));
			++it;
		}
		else
		{
			pairs.push_back(std::make_pair(first, first));
		}
	}

}

template <typename C>
void	PMergeMe::merge_pairs(C& seq, const pair_list& pairs)
{
	seq.clear();
	pair_list::const_iterator itt = pairs.begin();
	
	while (itt != pairs.end())
	{
		seq.push_back(itt->first);
		if (itt->first != itt->second)
			seq.push_back(itt->second);
		++itt;
	}
}

template <typename C>
void	PMergeMe::sort(C& seq)
{
	if (seq.size() <= 1)
		return ;

	pair_list	pairs;
	create_pairs(seq, pairs);
	pairs.sort(compare_pairs);
	merge_pairs(seq, pairs);
	insertion_sort(seq);
}

template <typename C>
double	PMergeMe::sort_with_time(C& seq)
{
	clock_t	start = clock();
	sort(seq);
	clock_t	end = clock();
	return static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC;
}


template <typename C>
void	PMergeMe::print_seq(const C& seq) const
{
	typename C::const_iterator itt = seq.begin();
    while (itt != seq.end())
    {
        std::cout << *itt << " ";
        ++itt;
    }
    std::cout << std::endl;
}

template <typename C>
bool	PMergeMe::is_seq_sorted(const C& seq)
{
	if (seq.size() < 2)
        return (true);

    typename C::const_iterator it = seq.begin();
    typename C::const_iterator next_it = it;
    ++next_it;

    for (; next_it != seq.end(); ++it, ++next_it)
    {
        if (*it > *next_it)
            return (false);
    }
    return (true);
}