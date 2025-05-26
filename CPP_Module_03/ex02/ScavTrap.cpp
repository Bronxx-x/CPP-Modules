/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:32:41 by yousef            #+#    #+#             */
/*   Updated: 2025/05/25 13:48:48 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), isGateKeeperMode(false)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " created with default constructor." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name), isGateKeeperMode(false)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " created with parameterized constructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy), isGateKeeperMode(copy.isGateKeeperMode)
{
    std::cout << "ScavTrap " << name << " created with copy constructor." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        isGateKeeperMode = other.isGateKeeperMode;
    }
    std::cout << "ScavTrap " << name << " assigned using assignment operator." << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else
    {
        std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (!isGateKeeperMode)
    {
        isGateKeeperMode = true;
        std::cout << "ScavTrap " << name << " is now in Gate Keeper mode." << std::endl;
    } else
    {
        std::cout << "ScavTrap " << name << " already entered Gate Keeper mode" << std::endl;
    }
}