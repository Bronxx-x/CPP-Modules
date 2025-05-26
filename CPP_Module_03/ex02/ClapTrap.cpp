/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:04:18 by yousef            #+#    #+#             */
/*   Updated: 2025/05/24 22:03:43 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created with parameterized constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : name(copy.name), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage)
{
    std::cout << "ClapTrap " << name << " created with copy constructor." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned using assignment operator." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else
    {
        std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        if (amount >= hitPoints)
            hitPoints = 0;
        else
            hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount 
                  << " points of damage! Hit points left: " << hitPoints << std::endl;
    } else
    {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount 
                  << " points! Hit points now: " << hitPoints << std::endl;
    } else
    {
        std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
    }
}