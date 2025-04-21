/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 06:09:48 by yousef            #+#    #+#             */
/*   Updated: 2025/04/21 09:52:26 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

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
        std::getline(std::cin, info[i]);
    }
    return (true);
}
void	Contact::get_contact(int index)const
{
    std::cout << std::setw(10) << index << "|";
    for (int i = 0; i < 3; i++)
    {
        if (info[i].length() > 10)
            std::cout << info[i].substr(0, 9) << ".";
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