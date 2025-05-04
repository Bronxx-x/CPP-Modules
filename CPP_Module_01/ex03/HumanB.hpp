/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:10:22 by yousef            #+#    #+#             */
/*   Updated: 2025/04/27 23:17:51 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;
public:
    HumanB(std::string name);
    ~HumanB();

    void setWeapon(Weapon& weapon);
    void attack() const;
};
#endif