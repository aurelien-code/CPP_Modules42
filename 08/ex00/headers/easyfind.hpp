#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &haystack, int needle)
{
    typename T::iterator match = std::find(haystack.begin(), haystack.end(), needle);

    return (match != haystack.end()) ? match : haystack.end();
}