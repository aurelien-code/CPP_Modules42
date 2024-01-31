#include <fstream>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &ref);
		~Fixed();
		Fixed &operator=(const Fixed &ref);
		// also work with:
		// friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);