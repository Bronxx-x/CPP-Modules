/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:07:23 by yousef            #+#    #+#             */
/*   Updated: 2025/03/24 07:13:11 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"


int main(void)
{
	PhoneBook 	PhoneBook;
	bool		run = true;
	std::string	command;

	PhoneBook.show_instruction();
	std::cout << "\033[33m$>\033[0m";
	while (run && std::getline(std::cin, command))
	{
		if (command.compare("ADD") == 0)
			PhoneBook.set_info();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.get_info();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "\033[34mHope i served you well. Good Bye.\033[0m" << std::endl;
			run = false;
			continue ;
		}
		command.clear();
		PhoneBook.show_instruction();
		std::cout << "\033[33m$>\033[0m";
	}
	return (0);
}