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

#include <stdio.h>
#include <vector>
#include <list>
#include <deque>
#include "Span.hpp"

int main()
{
    std::srand(time(NULL));
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp2 = Span(10001);
    std::vector<int> vec;
    for (int i = 0; i < 10001; i++)
        vec.push_back(std::rand() % 10001);
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        sp2.addNumber(*it);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    return 0;
}