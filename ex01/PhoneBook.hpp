#ifndef PHONEBOOK_HPP
#include <iostream>
#include <cctype>

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
	void	add();
	// void	search();
};
#endif