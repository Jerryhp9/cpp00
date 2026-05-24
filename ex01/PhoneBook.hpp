#ifndef PHONEBOOK_HPP
#include <limits>
#include <iostream>
#include <cctype>

#define list 8
class Contact {
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		int			phone_number;
		std::string	darkest_secret;
};

class PhoneBook {
	public:
		Contact contacts[3];
	void	add();
	// void	search();
};
#endif