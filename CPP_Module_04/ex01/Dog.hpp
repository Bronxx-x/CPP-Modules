/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:08:13 by yousef            #+#    #+#             */
/*   Updated: 2025/06/20 17:29:21 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal {
private:
    Brain *brain; // Pointer to Brain object for Dog
public:
    Dog();
    Dog(const Dog &other);
    ~Dog();
    Dog &operator=(const Dog &other);

    void makeSound() const;
    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};
#endif