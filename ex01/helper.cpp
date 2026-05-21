#include "PhoneBook.hpp"

Contact	add(PhoneBook conts)
{
	Contact	ptr;

	for (int i = 0; i < 8; i++)
	{
		if (!conts.contacts[i].first_name 
			|| !conts.contacts[i].last_name
			|| !conts.contacts[i].nickname
			|| !conts.contacts[i].phone_number
			|| !conts.contacts[i].darkest_secret)
		{
			ptr = conts.contacts[i];
			return (ptr);
		}
	}
}