#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_nb_of_contacts;
		int		_phonebook_size;
		bool	is_valid_phonenumber(std::string phone);
		std::string truncate_and_format(std::string str);
		void	ask_prompt(std::string str_field, std::string &var);
	public:
		PhoneBook(/* args */);
		~PhoneBook();
		void add();
		void search();
};

