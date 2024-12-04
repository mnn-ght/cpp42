/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/04 13:20:44 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const	x;
	Fixed const	y;
	
public:
	Point();
	Point(const Point &point);
	Point(const float f_x, const float f_y);
	~Point();

	Point& 	operator=(const Point &point);

	Fixed		getx( void ) const;
	Fixed		gety( void ) const;
	Fixed	setx(float const raw);
	Fixed	sety(float const raw);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif