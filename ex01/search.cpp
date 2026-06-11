#include "PhoneBook.hpp"

void	display_info(long index, Contact *cont)
{
	std::cout << std::endl << "|-----";
	std::cout << "information";
	std::cout << "------|" << std::endl;
	std::cout << "index - " << index << std::endl;
	std::cout << "first name - " << cont[index - 1].first_name << std::endl;
	std::cout << "last name - " << cont[index - 1].last_name << std::endl;
	std::cout << "nickname - " << cont[index - 1].nickname << std::endl;
	std::cout << "phone number - " << cont[index - 1].phone_number << std::endl;
	std::cout << "darkest secret - " << cont[index - 1].darkest_secret << std::endl << std::endl;
}

void	string_resize(std::string *str)
{
	if (str->size() > 10)
	{
		(*str).resize(10);
		(*str)[9] = '.';
	}
}

void	print_details(int index, Contact cont)
{
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << index;
	std::cout << "|";
	string_resize(&cont.first_name);
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << cont.first_name;
	std::cout << "|";
	string_resize(&cont.last_name);
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << cont.last_name;
	std::cout << "|" << std::endl;
}

bool	only_in_range(std::string index)
{
	if (!only_digits(&index))
		return (false);
	long value = strtol((&index)->c_str(), NULL, 10);
	if (value < 1 || value > list)
	{
		std::cout << "index out of range, try again" << std::endl;
		return (false);
	}
	return (true);
}

int	print_full_contact(Contact *cont)
{
	std::string	index;
	int flag = 0;

	std::cout << "Input index to entry" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!flag)
	{
		if (!getline(std::cin, index))
		{
			std::cout << "Detected end of file, exiting" << std::endl;
				return (1);
		}
		if (only_in_range(index))
		{
			long value = strtol((&index)->c_str(), NULL, 10);
			if (cont[value - 1].first_name.empty() && cont[value  - 1].last_name.empty()
				&& cont[value].nickname.empty()
				&& cont[value - 1].phone_number.empty()
				&& cont[value - 1].darkest_secret.empty())
			{
				std::cout << "contact is empty, please fill in the contact" << std::endl << std::endl;
				break;
			}
			else
				display_info(value, cont);
			flag = 1;
		}
	}
	return (0);
}


int	PhoneBook::search()
{
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "index";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "first name";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "last name";
	std::cout << "|" << std::endl;
	for (int i = 0; i < list; i++)
	{
		
		if (contacts[i].first_name.empty() && contacts[i].last_name.empty()
			&& contacts[i].nickname.empty()
			&& contacts[i].phone_number.empty()
			&& contacts[i].darkest_secret.empty())
			break;
		print_details(i + 1, contacts[i]);
	}
	if (print_full_contact(contacts) == 1)
		return (1);
	return (0);
}
