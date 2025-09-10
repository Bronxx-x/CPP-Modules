/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:23:41 by yousef            #+#    #+#             */
/*   Updated: 2025/09/07 20:39:36 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        // Existing Bureaucrat and Forms tests...
        Bureaucrat low("LowRank", 150);
        Bureaucrat mid("MidRank", 50);
        Bureaucrat high("HighRank", 1);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        // Signing and execution tests as before
        low.signForm(shrub);   
        mid.signForm(shrub);   
        mid.signForm(robot);   
        high.signForm(robot);  
        low.signForm(pardon);  
        high.signForm(pardon); 

        mid.executeForm(shrub);   
        high.executeForm(robot);  
        high.executeForm(pardon); 

        // === Intern Tests ===
        std::cout << "\n=== Intern Form Creation Tests ===\n";
        Intern someIntern;
        AForm* form1 = someIntern.makeForm("shrubbery creation", "backyard");
        AForm* form2 = someIntern.makeForm("robotomy request", "Bender");
        AForm* form3 = someIntern.makeForm("presidential pardon", "Marvin");
        AForm* formInvalid = someIntern.makeForm("unknown form", "Nobody");

        // Optional: execute forms created by the intern
        if (form1) {
            high.signForm(*form1);
            high.executeForm(*form1);
            delete form1;
        }
        if (form2) {
            high.signForm(*form2);
            high.executeForm(*form2);
            delete form2;
        }
        if (form3) {
            high.signForm(*form3);
            high.executeForm(*form3);
            delete form3;
        }
        if (formInvalid)
            delete formInvalid;

    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed ===\n";
    return 0;
}

