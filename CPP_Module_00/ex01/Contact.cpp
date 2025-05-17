/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 06:09:48 by yousef            #+#    #+#             */
/*   Updated: 2025/05/17 21:16:53 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::fields[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};

Contact::Contact(void)
{
    for (int i = 0; i < 11; i++)
        info[i] = "";
    return ;
}
Contact::~Contact(void)
{
    return ;
}
bool Contact::set_contact()

{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter " << fields[i] << ": ";
        while ( !(std::getline(std::cin, this->info[i])) || this->info[i].length() == 0)
		{
			if (std::cin.eof() == true)
			{
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else if (this->info[i].length() == 0)
			{
				this->info[i].clear();
				std::cout << "\033[31mEmpty contact information not allowed.\033[0m" << std::endl;
				std::cout << "Please enter the " << Contact::fields[i] << ":\n+";
			}
		}
    }
    return (true);
}
void	Contact::get_contact(int index)const
{
    std::cout << std::setw(10) << index << "|";
    for (int i = 0; i < 3; i++)
    {
        if (info[i].length() > 10)
            std::cout << info[i].substr(0, 9) << "." << "|";
        else
            std::cout << std::setw(10) << info[i] << "|";
    }
    std::cout << std::endl;
    return ;
}

void	Contact::get_fullcontact(int index)const
{
    std::cout << "Contact " << index << ":" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << fields[i] << ": " << info[i] << std::endl;
    return ;
}

void Contact::clear_contact(void)
{
	for (int i = 0; i < 5; i++)
		this->info[i].clear();
}
