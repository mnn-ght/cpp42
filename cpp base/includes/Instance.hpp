/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 13:41:42 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <iostream>

class Instance
{
private:
	std::string base_need;
	
public:
	Instance();
	Instance(const Instance &Instance);
	
	Instance(std::string name);
	~Instance();

	Instance &operator=(const Instance &Instance);

	std::string	getbase_need() const;
	void		setbase_need(std::string base_need);
};

#endif