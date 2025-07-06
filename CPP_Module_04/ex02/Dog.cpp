/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:09:56 by yousef            #+#    #+#             */
/*   Updated: 2025/06/20 17:36:54 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <cstdlib>

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	if (!this->brain) {
		perror("Brain allocation failed");
		std::cerr << "Exiting." << std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain();
	if (!this->brain) {
		perror("Brain allocation failed");
		std::cerr << "Exiting." << std::endl;
		exit(1);
	}
	*this->brain = *other.brain;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog assignment operator called" << std::endl;
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

void Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea) {
	this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
	return this->brain->getIdea(index);
}
