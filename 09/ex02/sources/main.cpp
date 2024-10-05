#include "pMergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <climits> 
#include <set>
#include <cstdlib>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define WHT "\e[0;37m"

int main(int ac, char **av)
{
	if (ac < 2) {
        std::cerr << RED << "Error: No input provided" << WHT << std::endl;
        return 1;
    }

    std::vector<int> vec_input;
    std::list<int> list_input;
    std::set<int>  seen_values;
    
    for (int i = 1; i < ac; ++i)
    {
        char *end;
        long num = std::strtol(av[i], &end, 10);

        if (*end != '\0') {
            std::cerr << RED << "Error: Invalid input '" << av[i] << "'" << WHT << std::endl;
            return 1;
        }

        if (num > INT_MAX) {
            std::cerr << RED << "Error: Value '" << av[i] << "' exceeds INT_MAX (" << INT_MAX << ")" << WHT << std::endl;
            return 1;
        }
        if (num < 0)
        {
            std::cerr << RED << "Error: Negative values are not allowed" << WHT << std::endl;
            return 1;
        }

        if (seen_values.find(num) != seen_values.end())
        {
            std::cerr << RED << "Error: Duplicate value '" << num << "' found"  << WHT << std::endl;
            return 1;
        }

        seen_values.insert(num);
        vec_input.push_back(num);
        list_input.push_back(num);
    }

    PMergeMe sorter;

    std::cout << "Sequence before sorting: ";
    sorter.print_seq(list_input);

	double vecTime = sorter.sort_with_time(vec_input);
    double listTime = sorter.sort_with_time(list_input);

    if (vecTime >= 0 && listTime >= 0)
    {
        std::cout << "Vector after sorting:\t";
        sorter.print_seq(vec_input);

        std::cout << "List after sorting:\t";
        sorter.print_seq(list_input);

        std::cout << "Time taken to sort vector: " << vecTime << " µseconds" << std::endl;
        std::cout << "Time taken to sort list: " << listTime << " µseconds" << std::endl;
    }

    if (sorter.is_seq_sorted(vec_input) && sorter.is_seq_sorted(list_input))
    {
        std::cout << GRN << "Sequence successfully sorted" << WHT << std::endl;
    }
	return (0);
}
