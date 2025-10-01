/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:03:31 by yousef            #+#    #+#             */
/*   Updated: 2025/09/27 21:03:32 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    try {
        std::cout << "==== Basic test ====" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;

        std::cout << "\n==== Test adding over the size limit (single add) ====" << std::endl;
        try {
            sp.addNumber(42); // Should throw
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "\n==== Test shortest/longest with too few elements ====" << std::endl;
        Span spEmpty(3);
        spEmpty.addNumber(5);
        try {
            std::cout << spEmpty.shortestSpan() << std::endl; // Should throw
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "\n==== Bulk add test (within limit) ====" << std::endl;
        Span sp2(10);
        std::vector<int> v2;
        v2.push_back(10);
        v2.push_back(20);
        v2.push_back(30);
        v2.push_back(40);
        v2.push_back(50);
        v2.push_back(60);
        sp2.addNumbers(v2.begin(), v2.end());
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp2.longestSpan() << std::endl;

        std::cout << "\n==== Bulk add test (exceeding limit) ====" << std::endl;
        Span sp3(5);
        std::vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        try {
            sp3.addNumbers(v1.begin(), v1.end());
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "\n==== Large test (safe size) ====" << std::endl;
        Span sp4(10001);
        std::vector<int> vec;
        for (int i = 0; i < 10001; i++) //  match limit
            vec.push_back(std::rand() % 10002);
        sp4.addNumbers(vec.begin(), vec.end());
        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp4.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}