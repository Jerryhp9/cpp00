#include "PhoneBook.hpp"

//:: - Scope Resolution Operator (identify and specify the identifier, class, variable or function belongs to)
//<< - Insertion Operator (used with std::cout to send data to the output)
//>> - Extraction Operator (used with std::cin to extract data from input stream into a variable),
//      It can fail to extract and causes the cin to fail and leftover contents in the buffer 
//std::string - is an object that has a dynamic size allocation

Contact	* PhoneBook::find_empty_contact(Contact *contacts)
{
	int	i = 0;

	// std::cout << pinpoint << std::endl;
	while (i < list)
	{
		if (contacts[i].first_name.empty() && contacts[i].last_name.empty()
			&& contacts[i].nickname.empty()
			&& contacts[i].phone_number.empty()
			&& contacts[i].darkest_secret.empty())
			return (&contacts[i]);
		i++;
	}
	Contact *slot = &contacts[pinpoint];
	pinpoint = (pinpoint + 1) % list;
	return (slot);
}

int	set_string(std::string name, Contact *ptr)
{
	size_t	i;
	int	flag = 0;
	std::string temp;

	while (!flag)
	{
		i = 0;
		getline(std::cin, temp);
		if (std::cin.eof())
		{
			std::cout << "Detected end of file, exiting" << std::endl;
			return (1);
		}
		if (isspace(temp[i]))
		{
			while (i < (temp.length() && isspace((temp[i]))))
				i++;
		}
		if (i == temp.length() || temp.empty())
		{
			std::cout << "Empty input, try again" << std::endl;
			continue;
		}
		for (size_t j = 0; j < temp.length(); j++)
		{
			if (temp[j] && isalnum(temp[j]))
			{
				ptr->set_contact(name, ptr, temp);
				flag = 1;
				break;
			}
		}
	}
	return (0);
}

bool	only_digits(std::string *str)
{
	for (size_t i = 0; i < str->length(); i++)
	{
		if (!isdigit((*str)[i]))
		{
			std::cout << "Required number as input, try again" << std::endl;
			return (false);
		}
	}
	return (true);
}

int	set_number(std::string name, Contact *cont)
{
	int	flag = 1;
	std::string *number;

	while (flag)
	{
		if (!getline(std::cin, *number))
		{
			std::cout << "Detected end of file, exiting" << std::endl;
			return (1);
		}
		if (only_digits(number) == true)
		{
			
			flag = 0;
		}
	}
	return (0);
}

int	PhoneBook::add()
{
	Contact	*book;
	Contact	*ptr;
	int		flag;

	book = get_contacts();
	ptr = find_empty_contact(book);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Input first name" << std::endl;
	flag = set_string("first_name", ptr);
	if (flag == 1)
		return (1);
	std::cout << "Input last name" << std::endl;
	flag = set_string("last_name", ptr);
	if (flag == 1)
		return (1);
	std::cout << "Input nickname" << std::endl;
	flag = set_string("nickname", ptr);
	if (flag == 1)
		return (1);
	std::cout << "Input phone number" << std::endl;
	flag = set_number("phone_number", ptr);
	if (flag == 1)
		return (1);
	std::cout << "Input darkest secret " << std::endl;
	flag = set_string("darkest_secret", ptr);
	if (flag == 1)
		return (1);
	return (0);
}
