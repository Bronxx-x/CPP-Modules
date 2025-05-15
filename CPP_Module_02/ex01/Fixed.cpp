/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 08:54:30 by yousef            #+#    #+#             */
/*   Updated: 2025/05/14 11:59:40 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fpValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int const raw)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fpValue = raw << _fractBits;
}

Fixed::Fixed(float const raw)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fpValue = roundf(raw * (1 << _fractBits));
}

Fixed& Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_fpValue = copy.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fpValue;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fpValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_fpValue / (1 << _fractBits);
}

int Fixed::toInt(void) const
{
    return this->_fpValue >> _fractBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}