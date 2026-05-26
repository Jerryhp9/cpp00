#include "PhoneBook.hpp"

void	display_info(int index, Contact *cont)
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

int	print_full_contact(Contact *cont)
{
	int	index = 0;
	int flag = 0;

	std::cout << "Input index to entry" << std::endl;
	while (!flag)
	{
		if (!(std::cin >> index) || std::cin.fail())
		{
			if (std::cin.eof())
			{
				std::cout << "Detected end of file, exiting" << std::endl;
				return (1);
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else
		{
			if (index > 8 || index < 1)
				std::cout << "index out of range, try again" << std::endl;
			else
			{
				display_info(index, cont);
				flag = 1;
			}
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
			&& contacts[i].phone_number == 0
			&& contacts[i].darkest_secret.empty())
			break;
		print_details(i + 1, contacts[i]);
	}
	if (print_full_contact(contacts) == 1)
		return (1);
	return (0);
}
