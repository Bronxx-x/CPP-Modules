/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 08:54:51 by yousef            #+#    #+#             */
/*   Updated: 2025/05/14 13:45:04 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
private:
    int                 _fpValue;
    static const int    _fractBits = 8;
public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed(int const raw);
    Fixed(float const raw);
    Fixed& operator=(const Fixed &copy);
    ~Fixed();
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
    //
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    //
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    //
    Fixed& operator++(); // pre-increment
    Fixed operator++(int); // post-increment
    Fixed& operator--(); // pre-decrement
    Fixed operator--(int); // post-decrement
    //
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
    
};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
#endif