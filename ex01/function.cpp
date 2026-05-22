#include "PhoneBook.hpp"

//:: - Scope Resolution Operator (identify and specify the identifier, class, variable or function belongs to)
//<< - Insertion Operator (used with std::cout to send data to the output)
//>> - Extraction Operator (used with std::cin to extract data from input stream into a variable),
//      It can fail to extract and causes the cin to fail and leftover contents in the buffer 
//std::string - is an object that has a dynamic size allocation

Contact	*find_empty_contact(Contact *contacts)
{
	int	i = 0;

	while (i < 8)
	{
		if (contacts[i].first_name.empty() && contacts[i].last_name.empty()
			&& contacts[i].nickname.empty()
			&& contacts[i].phone_number == 0
			&& contacts[i].darkest_secret.empty())
			return (&contacts[i]);
		i++;
	}
	return (&contacts[0]);
}

//!find out why when entered non-integer characters into phone number the infinite loop happens

// void	set_string(std::string string)
// {
// 	int		flag = 0;
// 	size_t	i = 0;

// 	while (!flag)
// 	{
		
// 		while (i < string.length())
// 		{
// 			if (isspace(string[i]))
// 			{
// 				std::cout << "detected whitespaces, try again" << std::endl;
// 				break;
// 			}
// 			i++;
// 		}
// 		if (i == string.length())
// 			flag = 1;
// 		else
// 			std::cin >> string;
// 	}

// }

void	set_string(std::string string)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, string);
}

void	PhoneBook::add()
{
	Contact	*ptr;

	ptr = find_empty_contact(contacts);
	std::cout << "Input first name" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, ptr->first_name);
	std::cout << "Input last name" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, ptr->last_name);
	std::cout << "Input nickname" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, ptr->nickname);
	std::cout << "Input phone number" << std::endl;
	int flag = 0;
	while (!flag)
	{
		std::cin >> ptr->phone_number;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Required number as input" << std::endl;
			std::cin >> ptr->phone_number;
		}
		if (ptr->phone_number)
			flag = 1;
	}
	std::cout << "Input darkest secret " << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, ptr->darkest_secret);

	for (int i = 0; i < 3; i++)
	{
		std::cout << "first name: " << contacts[i].first_name << std::endl;
		std::cout << "last name: " << contacts[i].last_name << std::endl;
		std::cout << "nickname: " << contacts[i].nickname << std::endl;
		std::cout << "phone number: " << contacts[i].phone_number << std::endl;
		std::cout << "darkest secret: " << contacts[i].darkest_secret << std::endl;
	}
}