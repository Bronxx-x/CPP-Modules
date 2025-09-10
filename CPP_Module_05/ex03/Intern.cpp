/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:25:04 by yousef            #+#    #+#             */
/*   Updated: 2025/09/07 20:44:28 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    //std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
    //std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
}

Intern::~Intern() {
    //std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs) {
    //std::cout << "Intern assignment operator called" << std::endl;
    (void)rhs;
    return *this;
}

static AForm* createShrubbery(const std::string &target) { return new ShrubberyCreationForm(target); }
static AForm* createRobotomy(const std::string &target) { return new RobotomyRequestForm(target); }
static AForm* createPresidential(const std::string &target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string formNames[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    AForm* (*formCreators[3])(const std::string&) = { createShrubbery, createRobotomy, createPresidential };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Intern could not find the form: " << formName << std::endl;
    return NULL; // Use NULL instead of nullptr for C++98
}

