#ifndef PHONEBOOK_HPP
#include <iostream>
#include <cstring>

class Contact {
	public:
		char	*first_name;
		char	*last_name;
		char	*nickname;
		int		phone_number;
		char	*darkest_secret;
};

class PhoneBook {
	public:
		Contact contacts[8];
	void	add();
	void	search();
	void	exit();
};
#endif