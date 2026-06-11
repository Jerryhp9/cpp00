#include "PhoneBook.hpp"

//:: - Scope Resolution Operator (identify and specify the identifier, class, variable or function belongs to)
//<< - Insertion Operator (used with std::cout to send data to the output)
//>> - Extraction Operator (used with std::cin to extract data from input stream into a variable),
//      It can fail to extract and causes the cin to fail and leftover contents in the buffer 
//std::string - is an object that has a dynamic size allocation

Contact	* PhoneBook::find_empty_contact(Contact *contacts)
{
	int	i = 0;


	while (i < list)
	{
		if (contacts[i].contact_is_empty(contacts[i]) == true)
			return (&contacts[i]);
		i++;
	}
	Contact *slot = &contacts[pinpoint];
	pinpoint = (pinpoint + 1) % list;
	return (slot);
}

void Contact::set_contact(std::string name, Contact *ptr, std::string result)
{
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
			while (i < temp.length() && isspace((temp[i])))
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

bool	only_digits(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
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
	std::string number;
	size_t i;

	while (flag)
	{
		i = 0;
		if (!getline(std::cin, number))
		{
			std::cout << "Detected end of file, exiting" << std::endl;
			return (1);
		}
		if (isspace(number[i]))
		{
			while (i < number.length() && isspace((number[i])))
				i++;
		}
		if (i == number.length() || number.empty())
		{
			std::cout << "Empty input, try again" << std::endl;
			continue;
		}
		if (only_digits(number) == true)
		{
			cont->set_contact(name, cont, number);
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
