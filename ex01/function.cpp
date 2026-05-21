#include "PhoneBook.hpp"

Contact	init_contacts(Contact contacts)
{
	contacts.phone_number = 0;
	return (contacts);
}

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

void	PhoneBook::add()
{
	Contact	*ptr;
	int		pnum;

	pnum = 0;
	for (int i = 0; i < 8; i++)
		contacts[i] = init_contacts(contacts[i]);
	ptr = find_empty_contact(contacts);
	std::cout << "Input first name" << std::endl;
	std::cin >> ptr->first_name;
	std::cout << "Input last name" << std::endl;
	std::cin >> ptr->last_name;
	std::cout << "Input nickname" << std::endl;
	std::cin >> ptr->nickname;
	std::cout << "Input phone number" << std::endl;
	std::cin >> pnum;
	if (std::isdigit(pnum) == 0)
		ptr->phone_number = pnum;
	else
	{
		std::cout << "Required number as input" << std::endl;
		std::cin >> pnum;
		ptr->phone_number = pnum;
	}
	// std::cout << "isdigit return " << std::isdigit(pnum) << std::endl;
	std::cout << "Input darkest secret " << std::endl;
	std::cin >> ptr->darkest_secret ;

	for (int i = 0; i < 2; i++)
	{
		std::cout << "first name: " << contacts[i].first_name << std::endl;
		std::cout << "last name: " << contacts[i].last_name << std::endl;
		std::cout << "nickname: " << contacts[i].nickname << std::endl;
		std::cout << "phone number: " << contacts[i].phone_number << std::endl;
		std::cout << "darkest secret: " << contacts[i].darkest_secret << std::endl;
	}
}