/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:31:59 by yousef            #+#    #+#             */
/*   Updated: 2025/05/21 02:38:14 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "Memory address of the string variable: " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR:      " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:      " << &stringREF << std::endl;

    std::cout << "Value of the string variable:          " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR:         " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:         " << stringREF << std::endl;

    return 0;
}
