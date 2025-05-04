/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:31:59 by yousef            #+#    #+#             */
/*   Updated: 2025/04/26 00:35:26 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int count = 5;
    Zombie* zombie = zombieHorde(count, "Yousef");

    if (!zombie)
    {
        std::cout << "Allocation failed." << std::endl;
        return 1;
    }

    for (int i = 0; i < count; ++i)
        zombie[i].announce();

    std::cout << "Deleting the horde..." << std::endl;
    delete[] zombie;
    return 0;
}