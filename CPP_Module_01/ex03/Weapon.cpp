/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:09:05 by yousef            #+#    #+#             */
/*   Updated: 2025/04/27 23:25:05 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("default") {
    std::cout << "Weapon default constructor called" << std::endl;
}

Weapon::Weapon(std::string type) : type(type) {
    std::cout << "Weapon constructor called with type: " << type << std::endl;
}

Weapon::~Weapon() {
    std::cout << "Weapon destructor called for type: " << type << std::endl;
}

const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& type) {
    this->type = type;
    std::cout << "Weapon type set to: " << type << std::endl;
}