/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:58:14 by yousef            #+#    #+#             */
/*   Updated: 2025/07/06 19:19:32 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void testAnimal(const Animal* animal) {
	std::cout << "Type: " << animal->getType() << std::endl;
	animal->makeSound();
	delete animal;
	std::cout << "-----------------------------" << std::endl;
}

void testWrongAnimal(const WrongAnimal* animal) {
	std::cout << "Type: " << animal->getType() << std::endl;
	animal->makeSound();
	delete animal;
	std::cout << "-----------------------------" << std::endl;
}

int main() {
	std::cout << "Testing Correct Polymorphism" << std::endl;
	testAnimal(new Animal());
	testAnimal(new Cat());
	testAnimal(new Dog());

	std::cout << "Testing Incorrect Polymorphism" << std::endl;
	testWrongAnimal(new WrongAnimal());
	testWrongAnimal(new WrongCat());

	std::cout << "Testing Direct WrongCat" << std::endl;
	const WrongCat* wc = new WrongCat();
	std::cout << "Type: " << wc->getType() << std::endl;
	wc->makeSound();
	delete wc;
	std::cout << "-----------------------------" << std::endl;

	return 0;
}
