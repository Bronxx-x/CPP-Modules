/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:09:17 by yousef            #+#    #+#             */
/*   Updated: 2025/04/27 23:13:18 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
    std::string type;
public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();

    const std::string& getType() const;
    void setType(const std::string& type);
};
#endif