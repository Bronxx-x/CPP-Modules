/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:08:03 by yousef            #+#    #+#             */
/*   Updated: 2025/06/20 17:29:40 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal {
private:
    Brain *brain; // Pointer to Brain object for Cat
public:
    Cat();
    Cat(const Cat &other);
    ~Cat();
    Cat &operator=(const Cat &other);
    void makeSound() const;
    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};

#endif