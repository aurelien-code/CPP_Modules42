#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <map>
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

class BitcoinExchange
{
	private:
		const std::string		_data_file_path;
		std::string				_input_file_path;
		std::map<int, float>	_data_parsed;

		bool		is_date_valid(std::string& date) const;
		int			epoch_encoder(std::string& date) const;
		std::string epoch_decoder(int& timestamp) const;
		void		parse_data(void);
		float		find_closest_values(int& timestamp, float &nb_of_btc) const;

	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string& input_file);
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange &operator=(const BitcoinExchange& ref);
		~BitcoinExchange(void);

		void run(void);
};

#endif