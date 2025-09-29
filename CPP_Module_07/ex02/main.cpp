/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:52:37 by yousef            #+#    #+#             */
/*   Updated: 2025/09/27 20:59:19 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        std::cout << "=== Test 1: Empty Array ===" << std::endl;
        Array<int> empty;
        std::cout << "Size: " << empty.getSize() << std::endl;

        std::cout << "\n=== Test 2: Array of ints ===" << std::endl;
        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.getSize(); i++)
            numbers[i] = i * 10;
        for (unsigned int i = 0; i < numbers.getSize(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;

        std::cout << "\n=== Test 3: Array of strings ===" << std::endl;
        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "Array";
        words[2] = "World";
        for (unsigned int i = 0; i < words.getSize(); i++)
            std::cout << words[i] << " ";
        std::cout << std::endl;

        std::cout << "\n=== Test 4: Copy constructor ===" << std::endl;
        Array<std::string> copy(words);
        words[0] = "Changed";
        std::cout << "Original[0]: " << words[0] << std::endl;
        std::cout << "Copy[0]: " << copy[0] << std::endl;

        std::cout << "\n=== Test 5: Assignment operator ===" << std::endl;
        Array<int> other(2);
        other[0] = 100;
        other[1] = 200;
        numbers = other;
        std::cout << "numbers[0]: " << numbers[0] << ", numbers[1]: " << numbers[1] << std::endl;

        std::cout << "\n=== Test 6: Out of bounds access ===" << std::endl;
        std::cout << numbers[10] << std::endl;  // should throw
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}