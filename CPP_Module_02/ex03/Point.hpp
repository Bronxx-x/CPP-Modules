/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:01:38 by yousef            #+#    #+#             */
/*   Updated: 2025/05/14 14:20:26 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"


class Point
{
	public:

		Point();
		Point(const Point &copy);
		Point(const float &x_init, const float &y_init);

		~Point();
        
        
        
		Point &operator=(const Point &assign);

		Fixed const	getX( void ) const;
		Fixed const	getY( void ) const;
		
	private:

		Fixed const	x;
		Fixed const	y;
};

#endif