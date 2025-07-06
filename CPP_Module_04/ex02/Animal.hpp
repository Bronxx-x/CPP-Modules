/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:07:48 by yousef            #+#    #+#             */
/*   Updated: 2025/06/20 17:54:15 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();
    Animal &operator=(const Animal &other);

    virtual void makeSound() const = 0; // PURE VIRTUAL → makes class abstract
    std::string getType() const;
};

#endif