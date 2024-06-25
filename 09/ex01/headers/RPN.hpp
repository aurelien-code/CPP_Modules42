#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

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

/*
	TOOD :
		- Handle crash cases like : 0 0 /
		- Handle bad cases 
			=> numbers over 10
			=> negative numbers 
			=> forbidden character likes () {} ...
*/