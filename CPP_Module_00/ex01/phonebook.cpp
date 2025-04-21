/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 06:48:29 by yousef            #+#    #+#             */
/*   Updated: 2025/04/21 09:55:14 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


PhoneBook::PhoneBook(void)
{
    index = 0;
    full = false;
    return ;
}
PhoneBook::~PhoneBook(void)
{
    return ;
}
void	PhoneBook::set_info(void)
{
    if (index == 8)
    {
        full = true;
        index = 0;
    }
    if (contacts[index].set_contact())
        index++;
    return ;
}
void	PhoneBook::get_info(void)const
{
    if (index == 0)
    {
		std::cout << "\033[31mPlease add at least one contact before searching.\033[0m" << std::endl;
        return ;
    }
    else
        for (int i = 0; i < index; i++)
            contacts[i].get_contact(i);
    std::cout << "\033[31mPlease choose the contact you want by index.\033[0m" << std::endl;
        int selected = -1;

    while (true)
    {
        std::cout << "> ";
        std::cin >> selected;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[31mInvalid input. Please enter a valid number.\033[0m" << std::endl;
            continue;
        }

        if (selected >= 0 && selected < index)
        {
            std::cin.ignore();
            contacts[selected].get_fullcontact(selected);
            break;
        }
        else
        {
            std::cout << "\033[31mIndex out of range. Please try again (0 to " << index - 1 << ").\033[0m" << std::endl;
        }
    }
}
void	PhoneBook::show_instruction(void)
{
    std::cout << "Enter ADD to add a contact, SEARCH to search for a contact, EXIT to exit the program" << std::endl;
    return ;
}