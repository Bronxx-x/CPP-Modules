/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:29:34 by yousef            #+#    #+#             */
/*   Updated: 2025/04/25 23:43:26 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "Zombie " << this->name << " is hungry for BraiiiiiiinnnzzzZ" << std::endl;
}
Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " slipped on a banana" << std::endl;
}

void Zombie::announce() const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}