#include <fstream>

#ifndef FIXED_HPP
#define FIXED_HPP

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

		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
		
		Fixed &operator=(const Fixed &ref);
		Fixed &operator+(const Fixed &ref);
		Fixed &operator-(const Fixed &ref);
		Fixed &operator*(const Fixed &ref);
		Fixed &operator/(const Fixed &ref);


		bool operator>(const Fixed &ref);
		bool operator>(const Fixed &ref) const;
		bool operator<(const Fixed &ref);
		bool operator<(const Fixed &ref) const;
		bool operator>=(const Fixed &ref);
		bool operator<=(const Fixed &ref);
		bool operator==(const Fixed &ref) const;
		bool operator!=(const Fixed &ref);

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		const static Fixed &min(const Fixed &a, const Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);

		int getRawBits(void) const;
		void setRawBits(int raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif