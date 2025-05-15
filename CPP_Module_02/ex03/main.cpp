/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 08:54:39 by yousef            #+#    #+#             */
/*   Updated: 2025/05/14 14:26:36 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

bool bsp(const Point a, const Point b, const Point c, const Point point);


int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(0.0f, 4.0f);
	Point point(1.0f, 1.0f);

	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle\n";
	else
		std::cout << "The point is outside the triangle\n";
	return 0;
}