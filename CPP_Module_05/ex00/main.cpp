/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:23:41 by yousef            #+#    #+#             */
/*   Updated: 2025/08/23 20:42:58 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Valid Creation ===" << std::endl;
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Grade Too High on Creation ===" << std::endl;
    try {
        Bureaucrat b("Bob", 0); // invalid
        std::cout << b << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Grade Too Low on Creation ===" << std::endl;
    try {
        Bureaucrat c("Charlie", 200); // invalid
        std::cout << c << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Increment Grade ===" << std::endl;
    try {
        Bureaucrat d("Diana", 2);
        std::cout << d << std::endl;
        d.incrementGrade();
        std::cout << d << std::endl;
        d.incrementGrade();
        std::cout << d << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Increment Beyond Limit ===" << std::endl;
    try {
        Bureaucrat e("Edward", 150);
        std::cout << e << std::endl;
        e.incrementGrade(); // should throw
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Decrement Beyond Limit ===" << std::endl;
    try {
        Bureaucrat f("Frank", 1);
        std::cout << f << std::endl;
        f.decrementGrade(); // should throw
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}