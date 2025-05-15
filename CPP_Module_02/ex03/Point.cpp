/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:01:27 by yousef            #+#    #+#             */
/*   Updated: 2025/05/14 14:17:24 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{
}

Point::Point(const float &x_init, const float &y_init) : x(x_init), y(y_init)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &assign)
{
	(void)assign;
	std::cout << "Point assignation operator does nothing" << std::endl;
	return *this;
}

Fixed const	Point::getX( void ) const
{
	return x;
}

Fixed const	Point::getY( void ) const
{
	return y;
}