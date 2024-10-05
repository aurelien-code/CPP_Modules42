#include "pMergeMe.hpp"

PMergeMe::PMergeMe()
{
}

PMergeMe::PMergeMe(const PMergeMe& ref)
{
    *this = ref;
}

PMergeMe &PMergeMe::operator=(const PMergeMe& ref)
{
    if (this != &ref)
    {
       
    }
    return *this;
}

PMergeMe::~PMergeMe()
{
}

bool	PMergeMe::compare_pairs(const pair_type& a, const pair_type& b)
{
	return (a.second < b.second);
}

void	PMergeMe::insertion_sort(std::vector<int>& seq)
{
	int key;
	int	j;

	for (size_t i = 1; i < seq.size(); ++i)
	{
		key = seq[i];
		j = i - 1;
		while (j >= 0 && seq[j] > key)
		{
			seq[j + 1] = seq[j];
			--j;
		}
		seq[j + 1] = key;
	}
}

void	PMergeMe::insertion_sort(std::list<int>& seq)
{
	std::list<int>::iterator	i, it_2;
	int							key;

	for (i = ++seq.begin(); i != seq.end(); ++i)
	{
		key = *i;
        it_2 = i;

        while (it_2 != seq.begin())
        {
            std::list<int>::iterator prev = it_2;
            --prev;
            if (*prev <= key)
                break;
            *it_2 = *prev;
            it_2 = prev;
        }

        *it_2 = key;
	}
}
