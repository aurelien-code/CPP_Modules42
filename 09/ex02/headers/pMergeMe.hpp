#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <ctime>

/*	In this code, "typename C" stands for Containers*/

class PMergeMe
{
	private:
		typedef std::pair<int, int> pair_type;
		typedef std::list<pair_type> pair_list;

		static bool	compare_pairs(const pair_type& a, const pair_type& b);
		void	insertion_sort(std::vector<int>& seq);
		void	insertion_sort(std::list<int>& seq);
		
		template <typename C>
		void	create_pairs(C& seq, pair_list& pairs);
		
		template <typename C>
		void	merge_pairs(C& seq, const pair_list& pairs);
		
	public:
		PMergeMe();
		PMergeMe(const PMergeMe& ref);
		PMergeMe &operator=(const PMergeMe& ref);
		~PMergeMe();

		template <typename C>
		void	sort(C& seq);

		template <typename C>
		double	sort_with_time(C& seq);

		template <typename C>
		void	print_seq(const C& seq) const;
		
		template <typename C>
		bool	is_seq_sorted(const C& seq);

};


#include "../sources/pMergeMe.tpp"