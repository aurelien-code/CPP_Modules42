
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