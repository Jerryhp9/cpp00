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
		void set_contact(std::string name, Contact *ptr, std::string result){
			if (name == "first_name")
				ptr->first_name = result;
			else if (name == "last_name")
				ptr->last_name = result;
			else if (name == "nickname")
				ptr->nickname = result;
			else if (name == "phone_number")
				ptr->phone_number = result;
			else if (name == "darkest_secret")
				ptr->darkest_secret = result;
		};
};

class PhoneBook {
	private:
		int pinpoint;
		Contact contacts[8];
	public:
		int	add();
		int	search();
		Contact *get_contacts(){
			return (contacts);
		}
		Contact	*find_empty_contact(Contact *contacts);
		void	setpinpoint(int numb){
			pinpoint = numb;
		}
	// void	search();
};

bool	only_digits(std::string *str);

#endif