#ifndef PHONEBOOK_HPP
#include <limits>
#include <iostream>
#include <iomanip>
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
		Contact contacts[8];
	int	add();
	int	search();
	// void	search();
};
#endif