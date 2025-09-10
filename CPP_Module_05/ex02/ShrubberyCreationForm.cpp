/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:01:45 by yousef            #+#    #+#             */
/*   Updated: 2025/09/07 20:12:37 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
    //std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    //std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
    //std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        this->target = other.target;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    //std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned()){
        std::cout << "Form not signed, cannot execute." << std::endl;
        throw AForm::GradeTooLowException();
    }
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "Error creating file: " << target + "_shrubbery" << std::endl;
        return;
    }

    outfile << "       _-_\n";
    outfile << "    /~~   ~~\\\n";
    outfile << " /~~         ~~\\\n";
    outfile << "{               }\n";
    outfile << " \\  _-     -_  /\n";
    outfile << "   ~  \\\\ //  ~\n";
    outfile << "_- -   | | _- _\n";
    outfile << "  _ -  | |   -_\n";
    outfile << "      // \\\\\n";

    outfile.close();
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
    os << "ShrubberyCreationForm: " << form.getName() << ", Target: " << form.getTarget()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}