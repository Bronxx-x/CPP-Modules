/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:02:17 by yousef            #+#    #+#             */
/*   Updated: 2025/08/25 20:49:30 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
class RobotomyRequestForm : public AForm {
private:
    std::string target;
    RobotomyRequestForm();
public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
    void execute(const Bureaucrat& executor) const;
    std::string getTarget() const;
};
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);
#endif