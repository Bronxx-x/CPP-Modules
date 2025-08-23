/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:14:18 by yousef            #+#    #+#             */
/*   Updated: 2025/08/23 21:58:43 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) 
{
    //std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
    {
        //std::cout << "Form copy constructor called" << std::endl;
    }
      
Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}
Form::~Form() 
{}
const std::string& Form::getName() const 
{
     return name; 
}
bool Form::getIsSigned() const 
{
    return isSigned; 
}
int Form::getGradeToSign() const 
{
     return gradeToSign; 
}
int Form::getGradeToExecute() const 
{
     return gradeToExecute; 
}

void Form::beSigned(const Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) 
{
    os << "Form Name: " << form.getName() << ", Signed: ";
    if (form.getIsSigned()) 
        os << "Yes";
    else 
        os << "No";
    os << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}