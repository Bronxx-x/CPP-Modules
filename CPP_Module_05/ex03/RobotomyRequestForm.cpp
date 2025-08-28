/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:02:10 by yousef            #+#    #+#             */
/*   Updated: 2025/08/25 22:07:30 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    //std::cout << "RobotomyRequestForm default constructor called" << std::endl;
    std::srand(std::time(NULL)); // Seed for randomness
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    //std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
    std::srand(std::time(NULL)); // Seed for randomness
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : 
AForm(other), target(other.target)
{
    //std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    //std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
std::string RobotomyRequestForm::getTarget() const
{
    return target;
}
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Bzzzz... Drilling noises..." << std::endl;
    if (std::rand() % 2) // 50% chance
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "." << std::endl;
}
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
    os << "RobotomyRequestForm [Name: " << form.getName()
       << ", Target: " << form.getTarget()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute() << "]";
    return os;
}
