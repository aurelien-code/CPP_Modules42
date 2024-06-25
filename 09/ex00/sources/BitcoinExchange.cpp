#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(void)
{
	throw std::logic_error("Class BitcoinExchange cannot be instancied without an input file");
}

BitcoinExchange::BitcoinExchange(std::string &input_file): _data_file_path("./data.csv")
{
	this->_input_file_path = input_file;
	try
	{
		parse_data();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
	*this = ref;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
	if (this != & ref)
	{
		_input_file_path = ref._input_file_path;
		_data_parsed = ref._data_parsed;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

bool BitcoinExchange::is_date_valid(std::string &date) const
{
	if (date.length() != 10) {
		return false;
	}
	if (date[4] != '-' || date[7] != '-') {
		return false;
	}

	int year, month, day;

	std::stringstream(date.substr(0, 4)) >> year;
	std::stringstream(date.substr(5, 2)) >> month;
	std::stringstream(date.substr(8, 2)) >> day;

	if (year < 0 || year > 2024|| month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}

	if (month == 2 && day > 29) {
		return false;
	}
	if (month == 2 && day == 29) {
		if (year % 4 != 0) {
			return false;
		}
		if (year % 100 == 0 && year % 400 != 0) {
			return false;
		}
	}
	return true;
}

int BitcoinExchange::epoch_encoder(std::string &date) const
{
	if (!is_date_valid(date)) {
		std::cout << "Invalid date format: " << date <<  std::endl;
		throw std::invalid_argument("Invalid date format");
	}

	int year, month, day;

	std::stringstream(date.substr(0, 4)) >> year;
	std::stringstream(date.substr(5, 2)) >> month;
	std::stringstream(date.substr(8, 2)) >> day;

	struct std::tm timeinfo = {};
	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;
	std::time_t epoch_time = std::mktime(&timeinfo);

	return epoch_time;
}

std::string BitcoinExchange::epoch_decoder(int &timestamp) const
{
	std::time_t temp = static_cast<time_t>(timestamp);
    std::tm *timeinfo = std::localtime(&temp);

    if (!timeinfo) {
        throw std::invalid_argument("Invalid timestamp");
    }

    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return std::string(buffer);
}

void BitcoinExchange::parse_data(void)
{
	std::string line;
	std::ifstream file;

	file.open(_data_file_path.c_str(), std::ios::in);
	if (!file.is_open()) {
		throw std::invalid_argument("Invalid file path");
	}
	std::getline(file, line);
    while (std::getline(file, line)) {
        std::string date = line.substr(0, 10);
        std::string value = line.substr(11);
        
		try
		{
			int timestamp = epoch_encoder(date);
			float bitcoin_value;

			std::stringstream ss(value);
			ss >> bitcoin_value;

			_data_parsed[timestamp] = bitcoin_value;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
    }
}

float BitcoinExchange::find_closest_values(int &timestamp, float &nb_of_btc) const
{
	std::map<int, float>::const_iterator it = _data_parsed.lower_bound(timestamp);
	if (it == _data_parsed.begin()) {
		throw std::invalid_argument("No data available before the input timestamp");
	}
	--it;
	int closest_timestamp = it->first;
	float bitcoin_value = it->second;
	try
	{
		std::string closest_date = epoch_decoder(closest_timestamp);
		std::cout << "Closest date before " << epoch_decoder(timestamp) << ": " << closest_date << " => " << nb_of_btc << " = " << nb_of_btc * bitcoin_value << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return bitcoin_value;
}

void BitcoinExchange::run(void)
{
	std::string line;
	std::ifstream file;

	file.open(_input_file_path.c_str(), std::ios::in);
	if (!file.is_open()) {
		throw std::invalid_argument("Invalid file path");
	}
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string date;
		std::string value;
		float number_of_btc;
		int timestamp;

		if (line.length() < 10 || line.length() < 12)
		{
			std::cout << "[Error] Invalid line format: " << line << std::endl;
			continue;
		}
		else
		{ 
			date = line.substr(0, 10);
			value = line.substr(12);
		}

		if (is_date_valid(date) == false)
		{
			std::cout << "[Error] Invalid date : " << date << std::endl;
			continue;
		}
		
		std::stringstream ss(value);
		ss >> number_of_btc;
		
		if (number_of_btc < 0) 
		{
			std::cout << "[Error] number is too small (" << number_of_btc << ")" << std::endl;
			continue;
		}
		else if (number_of_btc > 1000)
		{
			std::cout << "[Error] number is too large (" << number_of_btc << ")" << std::endl;
			continue;
		}
		
		try
		{
			timestamp = epoch_encoder(date);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		

		if (_data_parsed.find(timestamp) == _data_parsed.end())
		{
			try
			{
				find_closest_values(timestamp, number_of_btc);
			}
			catch (std::invalid_argument &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			float bitcoin_value = _data_parsed[timestamp] * number_of_btc;
			std::cout << "Date: " << date << " => " << number_of_btc << " = " << bitcoin_value << std::endl;
		}
	}
}