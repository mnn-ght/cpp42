/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/02 12:20:45 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string get_content(std::fstream &fs_in)
{
	std::string dest;
	char		buf;
	
	while (fs_in.get(buf))
		dest.append(&buf);
	return (dest);
}

std::string replace_str(std::string buffer, std::string s1, std::string s2)
{
	std::string dest;
	unsigned int i;

	if (s2.empty() || buffer.empty())
		return (buffer);
	
	i = 0;
	while (i < buffer.size())
	{
		if (i + s1.size() > buffer.size() || buffer.compare(i, s1.size(), s1) != 0)
		{
			dest.append(1, buffer[i]);
			i++;
		}
		else
		{
			dest.append(s2);
			i += s1.size();
		}
	}
	return (dest);
}

bool	check_args(std::string filename, std::string s1)
{
	if (filename.empty())
	{
		std::cout << "Error" << std::endl;
		std::cout << "The name of the file is empty." << std::endl;
		return (0);
	}
	else if (s1.empty())
	{
		std::cout << "Error" << std::endl;
		std::cout << "String 1 is empty." << std::endl;
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	std::fstream	fs_in, fs_out;
	std::string		buffer, filename, s1, s2;

	if (argc != 4)
	{
		std::cout << "Your program needs 3 arguments: a filename, string 1 that occurs in filename that will be replace by string 2." << std::endl;
		std::cout << "For example: ./program file1 'World' 'monde'" << std::endl;
		return (-1);
	}
	filename = argv[1];
	s1 = argv[2];
	if (!check_args(filename, s1))
		return (-1);
	s2 = argv[3];
	fs_in.open(filename.c_str(), std::fstream::in);
	if (!(fs_in.is_open()))
	{
		std::cout << "Error" << std::endl;
		std::cout << "Could not open '" << filename << "'." << std::endl;
		return (-1);
	}
	buffer = get_content(fs_in);
	fs_in.close();
	fs_out.open(filename.append(".replace").c_str(), std::fstream::out);
	if (!(fs_out.is_open()))
	{
		std::cout << "Error" << std::endl;
		std::cout << "Could not open the new file." << std::endl;
		return (-1);
	}
	buffer = replace_str(buffer, s1, s2);
	fs_out << buffer;
	fs_out.close();
	return 0;
}
