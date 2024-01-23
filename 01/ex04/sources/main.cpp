// string::substr
#include <iostream>
#include <string>

int main()
{
	std::string str = "We think in generalities, but we live in details.";
	std::string needle = "live";

	std::size_t pos = str.find(needle);
	if (pos != std::string::npos)
	{
		// Check if the found string is an exact match
		bool isExactMatch = true;
		if (pos != 0 && isalnum(str[pos - 1]))
		{
			isExactMatch = false; // Character before is alphanumeric
		}
		if (pos + needle.length() < str.length() && isalnum(str[pos + needle.length()]))
		{
			isExactMatch = false; // Character after is alphanumeric
		}

		if (isExactMatch)
		{
			std::cout << "Exact match found at position: " << pos << std::endl;
		}
		else
		{
			std::cout << "Match found, but it's not an exact match." << std::endl;
		}
	}
	else
	{
		std::cout << "No match found." << std::endl;
	}
}