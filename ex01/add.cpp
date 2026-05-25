#include "PhoneBook.hpp"

//:: - Scope Resolution Operator (identify and specify the identifier, class, variable or function belongs to)
//<< - Insertion Operator (used with std::cout to send data to the output)
//>> - Extraction Operator (used with std::cin to extract data from input stream into a variable),
//      It can fail to extract and causes the cin to fail and leftover contents in the buffer 
//std::string - is an object that has a dynamic size allocation

Contact	*find_empty_contact(Contact *contacts)
{
	int	i = 0;

	while (i < list)
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

int	set_string(std::string *string)
{
	size_t	i;
	int	flag = 0;

	while (!flag)
	{
		i = 0;
		getline(std::cin, *string);
		if (std::cin.eof())
		{
			std::cout << "Detected end of file, exiting" << std::endl;
			return (1);
		}
		if (isspace((*string)[i]))
		{
			while (i < (*string).length() && isspace((*string)[i]))
				i++;
		}
		if (i == (*string).length() || (*string).empty())
		{
			std::cout << "Empty input, try again" << std::endl;
			continue;
		}
		for (size_t j = 0; j < (*string).length(); j++)
		{
			if ((*string)[j] && isalnum((*string)[j]))
			{
				flag = 1;
				break;
			}
		}
	}
	return (0);
}

int	set_number(int *number)
{
	int flag = 0;

	while (!flag)
	{
		std::cin >> *number;
		if (std::cin.eof())
		{
			std::cout << "Detected end of file, exiting" << std::endl;
			return (1);
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Required number as input, try again" << std::endl;
			std::cin >> *number;
		}
		if (*number)
			flag = 1;
	}
	return (0);
}

int	PhoneBook::add()
{
	Contact	*ptr;
	int		flag;

	ptr = find_empty_contact(contacts);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Input first name" << std::endl;
	flag = set_string(&ptr->first_name);
	if (flag == 1)
		return (1);
	std::cout << "Input last name" << std::endl;
	flag = set_string(&ptr->last_name);
	if (flag == 1)
		return (1);
	std::cout << "Input nickname" << std::endl;
	flag = set_string(&ptr->nickname);
	if (flag == 1)
		return (1);
	std::cout << "Input phone number" << std::endl;
	flag = set_number(&ptr->phone_number);
	if (flag == 1)
		return (1);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Input darkest secret " << std::endl;
	flag = set_string(&ptr->darkest_secret);
	if (flag == 1)
		return (1);
	return (0);
}
