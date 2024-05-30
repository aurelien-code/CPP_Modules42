#include <iostream>

template <typename T, typename F>
void iter(T *arr, size_t size, F function)
{
	for (size_t i = 0; i < size; i++)
	{
		function(arr[i]);
	}
	
}

template <typename T>
void printval(T &value)
{
	std::cout << value << std::endl;
}

void increment(int &val)
{
	++val;
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(array) / sizeof(array[0]);

	void (*printInt)(int&) = printval<int>;

    std::cout << "Original array: \n";
    iter(array, length, printInt);
    std::cout << std::endl;

	std::cout << "Incremented array: \n";
    iter(array, length, increment);
	iter(array, length, printInt);

    std::cout << std::endl;
	return 0;
}
