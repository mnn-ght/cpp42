/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:20:59 by magahat           #+#    #+#             */
/*   Updated: 2025/01/20 11:43:49 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

/*
	CONSTRUCTORS
*/

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer &other) {
	*this = other;
}

/*
	DESTRUCTORS
*/

Serializer::~Serializer() {
}

/*
	OPERATORS OVERLOAD
*/

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}