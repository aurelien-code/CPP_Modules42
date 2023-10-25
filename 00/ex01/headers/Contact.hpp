#include <string>
//first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkest_secret;
	public:
		Contact(/* args */);
		~Contact();
		void set_first_name(std::string val);
		void set_last_name(std::string val);
		void set_nickname(std::string val);
		void set_phonenumber(std::string val);
		void set_darkest_secret(std::string val);
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phonenumber();
		std::string get_darkest_secret();
	    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);
};
