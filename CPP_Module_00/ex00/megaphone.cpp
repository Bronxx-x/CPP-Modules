/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:37:26 by yousef            #+#    #+#             */
/*   Updated: 2025/03/20 02:40:13 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     toupp(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

void    megaphone(char *str)
{
    int i = 0;
    while (str[i])
    {
        std::cout << (char)toupp(str[i]);
        i++;
    }
}

int     main(int ac, char **av)
{
    if (ac > 1)
    {
        for (int i = 1; i < ac; i++)
            megaphone(av[i]);
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}