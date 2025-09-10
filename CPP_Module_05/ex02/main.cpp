/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:23:41 by yousef            #+#    #+#             */
/*   Updated: 2025/09/07 20:06:33 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Create Bureaucrats
        Bureaucrat low("LowRank", 150);
        Bureaucrat mid("MidRank", 50);
        Bureaucrat high("HighRank", 1);

        std::cout << "\n=== Bureaucrats ===\n";
        std::cout << low << std::endl;
        std::cout << mid << std::endl;
        std::cout << high << std::endl;

        // Create Forms
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "\n=== Forms Before Signing ===\n";
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n=== Signing Forms ===\n";
        shrub.getIsSigned() ? std::cout << "ShrubberyCreationForm is already signed.\n" : std::cout << "ShrubberyCreationForm is not signed yet.\n";
        //shrub.execute(low);
        low.signForm(shrub);   // fail, grade too low
        mid.signForm(shrub);   // succeed
        mid.signForm(robot);   // fail
        high.signForm(robot);  // succeed
        low.signForm(pardon);  // fail
        high.signForm(pardon); // succeed

        std::cout << "\n=== Forms After Signing ===\n";
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n=== Execution Tests ===\n";
        low.executeForm(shrub);   // fail, grade too low
        mid.executeForm(shrub);   // succeed, creates "garden_shrubbery"

        mid.executeForm(robot);   // fail, not signed or grade too low
        high.executeForm(robot);  // succeed, 50% chance success

        mid.executeForm(pardon);  // fail, grade too low
        high.executeForm(pardon); // succeed, prints pardon message

        std::cout << "\n=== Invalid Forms Creation ===\n";
        try {
            ShrubberyCreationForm invalid("invalid_target");
            invalid.execute(low); // Not signed
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cerr << "Exception: ------------------------"<< std::endl;
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed ===\n";
    return 0;
}
