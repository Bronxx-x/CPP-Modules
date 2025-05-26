/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:24:47 by yousef            #+#    #+#             */
/*   Updated: 2025/05/26 00:29:01 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created with default constructor." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created with parameterized constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap " << name << " created with copy constructor." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap " << name << " assigned using assignment operator." << std::endl;
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "FragTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else
    {
        std::cout << "FragTrap " << name << " cannot attack!" << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "🤖 FragTrap " << name << " shouts: 'High five, partner! Don't leave me hanging! ✋😎'" << std::endl;
}