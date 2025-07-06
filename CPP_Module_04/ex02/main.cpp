/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:58:14 by yousef            #+#    #+#             */
/*   Updated: 2025/07/06 19:41:28 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << " Basic Allocation/Deletion " << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; // Should properly delete Dog and Brain
	delete i; // Should properly delete Cat and Brain

	std::cout << "\n Array of Animals " << std::endl;
	const int size = 6;
	Animal* zoo[size];
	//Animal a; error
	for (int n = 0; n < size; ++n) {
		if (n < size / 2)
			zoo[n] = new Dog();
		else
			zoo[n] = new Cat();
	}

	std::cout << "\n Deleting Animals " << std::endl;
	for (int n = 0; n < size; ++n)
		delete zoo[n];

	std::cout << "\n Deep Copy Test " << std::endl;
	Dog original;
	original.setIdea(0, "I want a bone");
	original.setIdea(1, "Chase the mailman");

	Dog copy = original; // Calls deep copy constructor

	std::cout << "Original Dog Idea 0: " << original.getIdea(0) << std::endl;
	std::cout << "Copied Dog Idea 0: " << copy.getIdea(0) << std::endl;

	original.setIdea(0, "Changed idea in original");

	std::cout << "After modification:" << std::endl;
	std::cout << "Original Dog Idea 0: " << original.getIdea(0) << std::endl;
	std::cout << "Copied Dog Idea 0: " << copy.getIdea(0) << std::endl;

	std::cout << "\nAll tests completed. Use Valgrind to confirm no leaks." << std::endl;
	return 0;
}
