/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:20:40 by yousef            #+#    #+#             */
/*   Updated: 2025/05/04 15:36:08 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>

int main()
{
	Harl	harl;

	std::cout << "Printing all harl could say." << std::endl << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("something else");
	std::cout << std::endl;
	std::cout << "Now you have 5 chances to make harl say something." << std::endl;
	for (int i = 0; i < 5; i++)
    {
        std::string input;
        std::cout << "input: ";
        if (!(std::cin >> input))
        {
            std::cerr << "^D" << std::endl;
            exit(0);
        }
        harl.complain(input);
        std::cout << std::endl;
    }
	return (1);
}