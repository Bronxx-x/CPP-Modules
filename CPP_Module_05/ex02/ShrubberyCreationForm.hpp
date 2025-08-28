/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:01:56 by yousef            #+#    #+#             */
/*   Updated: 2025/08/25 20:46:30 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string target;
    ShrubberyCreationForm();
public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
    void execute(const Bureaucrat& executor) const;
    std::string getTarget() const;
};
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form);
#endif