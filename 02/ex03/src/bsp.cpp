/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:50:20 by magahat           #+#    #+#             */
/*   Updated: 2024/12/04 15:17:23 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1 = ((point.getFloatX() - b.getFloatX()) * (a.getFloatY() - b.getFloatY()) - (a.getFloatX() - b.getFloatX()) * (point.getFloatY() - b.getFloatY()));
	float d2 = ((point.getFloatX() - c.getFloatX()) * (b.getFloatY() - c.getFloatY()) - (b.getFloatX() - c.getFloatX()) * (point.getFloatY() - c.getFloatY()));
	float d3 = ((point.getFloatX() - a.getFloatX()) * (c.getFloatY() - a.getFloatY()) - (c.getFloatX() - a.getFloatX()) * (point.getFloatY() - a.getFloatY()));

	bool is_vertex = (d1 == 0) || (d2 == 0) || (d3 == 0);
	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	
	if (is_vertex)
		return (0);
	return (!(has_neg && has_pos));
}