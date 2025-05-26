/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:03:40 by yousef            #+#    #+#             */
/*   Updated: 2025/05/25 14:20:41 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- Testing ClapTrap ---" << std::endl;
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
    }
    std::cout << "\n--- Testing ScavTrap ---" << std::endl;
    {
        std::cout << "--- Creating ScavTrap ---" << std::endl;
        ScavTrap st("GateBot");

        std::cout << "--- Attacking ---" << std::endl;
        st.attack("intruder");

        std::cout << "--- Using special ability ---" << std::endl;
        st.guardGate();

        std::cout << "--- Copying ScavTrap ---" << std::endl;
        ScavTrap st2 = st;

        std::cout << "--- Assigning ScavTrap ---" << std::endl;
        ScavTrap st3;
        st3 = st;

        std::cout << "--- Destructors will now be called automatically ---" << std::endl;
    }
}