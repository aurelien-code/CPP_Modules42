#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class RPN
{
	private:
		std::stack<int>	_s;

	public:
		RPN();
		RPN(std::string &seq);
		RPN(const RPN &ref);
		RPN &operator=(const RPN &ref);
		~RPN();

		int calculate(void);

};

#endif