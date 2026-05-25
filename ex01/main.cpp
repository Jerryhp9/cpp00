#include "PhoneBook.hpp"

Contact	init_contacts(Contact contacts)
{
	contacts.phone_number = 0;
	return (contacts);
}

int main()
{
	std::string	command;
	int			exit;
	PhoneBook	book;

	exit = 0;
	for (int i = 0; i < list; i++)
		book.contacts[i] = init_contacts(book.contacts[i]);
	while (exit != 1)
	{
		std::cout << "---WELCOME TO MY PHONEBOOK---" << std::endl << std::endl;
		std::cout << "Input commands (ADD, SEARCH, EXIT)" << std::endl;
		if (!(std::cin >> command))
		{
			if (std::cin.eof())
			{
				std::cout << "Detected end of file, exiting" << std::endl;
				exit = 1;
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else
		{
			if (command == "EXIT")
				exit = 1;
			if (command == "ADD")
			{
				if (book.add() == 1)
					break;
			}
			if (command == "SEARCH")
				book.search();
			if (command != "ADD" && command != "SEARCH" && command != "EXIT")
			{
				std::cout << "invalid command: " << command;
				std::cout << ", try again" << std::endl;
			}
			else if (command.empty())
				std::cout << "empty command, try again" << std::endl;
		}
	}
	return (0);
}