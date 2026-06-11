#ifndef PHONEBOOK_HPP
#include <limits>
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib>

#define list 8

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void	display_info(long index, Contact *cont);
		void	print_details(int index, Contact cont);
		bool	contact_is_empty(Contact cont);
		void	set_contact(std::string name, Contact *ptr, std::string result);
};

class PhoneBook {
	private:
		int pinpoint;
		Contact contacts[8];
	public:
		int			add();
		int			search();
		Contact		*find_empty_contact(Contact *contacts);
		Contact		*get_contacts() {
			return (contacts);
		}
		void		setpinpoint(int numb) {
			pinpoint = numb;
		}
};

bool	only_digits(std::string str);

#endif