/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:03:40 by yousef            #+#    #+#             */
/*   Updated: 2025/05/24 22:10:02 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    std::cout << "\n-- Alpha attacks Beta --" << std::endl;
    a.attack("Beta");
    b.takeDamage(0);  // since default attackDamage is 0

    std::cout << "\n-- Beta repairs itself --" << std::endl;
    b.beRepaired(5);

    std::cout << "\n-- Beta attacks Alpha --" << std::endl;
    b.attack("Alpha");
    a.takeDamage(0);  // same here

    std::cout << "\n-- Overkill Alpha --" << std::endl;
    a.takeDamage(100);  // force Alpha to 0 HP

    std::cout << "\n-- Try to repair Alpha (should fail) --" << std::endl;
    a.beRepaired(10);

    std::cout << "\n-- Try to attack with Alpha (should fail) --" << std::endl;
    a.attack("Beta");

    return 0;
}