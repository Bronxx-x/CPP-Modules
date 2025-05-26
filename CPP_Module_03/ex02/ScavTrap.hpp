/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:33:02 by yousef            #+#    #+#             */
/*   Updated: 2025/05/25 13:41:59 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{

private:
    bool isGateKeeperMode;
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &copy);
    
    ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &other);

    void attack(const std::string &target);
    void guardGate();
};
#endif