/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 08:54:51 by yousef            #+#    #+#             */
/*   Updated: 2025/05/14 09:29:58 by yousef           ###   ########.fr       */
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
    Fixed& operator=(const Fixed &copy);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
#endif