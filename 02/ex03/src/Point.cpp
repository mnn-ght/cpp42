/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:21:02 by magahat           #+#    #+#             */
/*   Updated: 2024/12/04 14:58:02 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

/*
	CONSTRUCTORS
*/

Point::Point() : x( Fixed(0) ), y( Fixed(0) )
{
}

Point::Point(const Point &point)
{
	*this = point;
}

Point::Point(const float f_x, const float f_y) : x( Fixed(f_x) ), y( Fixed(f_y) )
{
}

/*
	DESTRUCTOR
*/

Point::~Point()
{
}

/*
	OPERATOR OVERLOAD
*/

Point& 	Point::operator=(const Point &point)
{
	this->~Point();
	new(this) Point(point.x.toFloat(), point.y.toFloat());
	return (*this);
}

/*
	OTHER FUNCTIONS
*/

float	Point::getFloatX( void ) const
{
	return this->x.toFloat();
}

float	Point::getFloatY( void ) const
{
	return this->y.toFloat();
}