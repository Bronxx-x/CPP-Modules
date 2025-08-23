/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:23:41 by yousef            #+#    #+#             */
/*   Updated: 2025/08/23 21:56:44 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Bureaucrat Creation ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 50);
        std::cout << alice << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Form Creation ===" << std::endl;
    try {
        Form contract("Contract", 30, 50);
        std::cout << contract << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Signing Forms ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 40);
        Form taxForm("Tax Form", 30, 20);
        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;
        bob.signForm(taxForm); // too low → should fail
        std::cout << taxForm << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Successful Signing ===" << std::endl;
    try {
        Bureaucrat carol("Carol", 20);
        Form leaveForm("Leave Form", 30, 50);
        std::cout << carol << std::endl;
        std::cout << leaveForm << std::endl;
        carol.signForm(leaveForm); // grade sufficient → success
        std::cout << leaveForm << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Form Grades ===" << std::endl;
    try 
    {
        Form invalid("Invalid", 0, 151);
    } 
    catch (const std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try 
    {
    Bureaucrat maxRank("Max", 1);
        maxRank.incrementGrade(); // should throw GradeTooHighException
    } 
    catch (const std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
    Bureaucrat minRank("Min", 150);
        minRank.decrementGrade(); // should throw GradeTooLowException
    } 
    catch (const std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}
