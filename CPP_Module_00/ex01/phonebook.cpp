/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 06:48:29 by yousef            #+#    #+#             */
/*   Updated: 2025/03/24 07:20:21 by yousef           ###   ########.fr       */
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
    for (int i = 0; i < index; i++)
        contacts[i].get_contact(i);
    return ;
}
void	PhoneBook::show_instruction(void)
{
    std::cout << "Enter ADD to add a contact, SEARCH to search for a contact, EXIT to exit the program" << std::endl;
    return ;
}