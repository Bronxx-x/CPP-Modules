/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:02:34 by yousef            #+#    #+#             */
/*   Updated: 2025/08/25 21:59:04 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class PresidentialPardonForm : public AForm {
private:
    std::string target;
    PresidentialPardonForm();
public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
    void execute(const Bureaucrat& executor) const;
    std::string getTarget() const;
};
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);
#endif