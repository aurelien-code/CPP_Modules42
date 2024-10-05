#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string &seq)
{
	std::istringstream iss(seq);
	std::string token;
	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_s.size() < 2 || !isdigit(_s.top()))
			{
				std::cout << "Error\n";
				return;
			}
			int val2 = _s.top();
			_s.pop();
			int val1 = _s.top();
			_s.pop();
			if (token == "+")
				_s.push(val1 + val2);
			else if (token == "-")
				_s.push(val1 - val2);
			else if (token == "*")
				_s.push(val1 * val2);
			else
			{
				if (val2 == 0)
				{
					std::cout << "Error: division by zero.\n";
					return;
				}
				_s.push(val1 / val2);
			}
		}
		else
		{
			std::stringstream ss(token);
			int nb;
			ss >> nb;
			_s.push(nb);
		}
	}

	std::cout << _s.top() << std::endl;
}

RPN::RPN(const RPN &ref)
{
	*this = ref;
}

RPN &RPN::operator=(const RPN &ref)
{
	if (this != &ref)
	{
		_s = ref._s;
	}
	return (*this);
}

RPN::~RPN()
{
}

int RPN::calculate()
{
	if (_s.empty())
	{
		return 0;
	}
	return _s.top();
}