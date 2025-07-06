/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:09:56 by yousef            #+#    #+#             */
/*   Updated: 2025/06/20 17:37:20 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <cstdlib> 

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	if (!this->brain) {
		perror("Brain allocation failed");
		std::cerr << "Exiting." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain();
	if (!this->brain) {
		perror("Brain allocation failed");
		std::cerr << "Exiting." << std::endl;
		exit(1);
	}
	*this->brain = *other.brain;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;

		if (this->brain)
			delete this->brain;

		this->brain = new Brain();
		if (!this->brain) {
			perror("Brain allocation failed");
			std::cerr << "Exiting." << std::endl;
			exit(1);
		}
		*this->brain = *other.brain;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meeeoww" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea) {
	this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
	return this->brain->getIdea(index);
}
