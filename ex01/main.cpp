#include "PhoneBook.hpp"

int main()
{
	std::string	command;
	int			exit;

	exit = 0;
	while (exit != 1)
	{

		std::cout << "---WELCOME TO MY PHONEBOOK---" << std::endl << std::endl;
		std::cout << "Input commands (ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> command;
		if (command == "EXIT")
			exit = 1;
		if (command == "ADD" || command == "SEARCH")
			
		if (command != "ADD" && command != "SEARCH" && command != "EXIT")
		{
			std::cout << "invalid command: " << command;
			std::cout << ", try again" << std::endl;
		}

	}
	return (0);
}