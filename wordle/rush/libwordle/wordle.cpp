/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:43:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/14 00:50:53 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "wordle.hpp"

wordle::wordle(void)
{
	for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
		for (unsigned int j = 0; j < WORDLE_NB_LINE; ++j)
			_lines[i][j] = '_';
	return ;
}

wordle::wordle(wordle const &src)
{
	*this = src;
	return ;
}

wordle::~wordle(void)
{
	return ;
}

wordle	&wordle::operator=(wordle const &rhs)
{
//	if (this != &rhs)
//		this-> = rhs.get();
	(void)rhs;
	return (*this);
}

void	wordle::printTitle(void) const
{
	std::cout
		<< " __          __           _ _      " << std::endl
		<< " \\ \\        / /          | | |     " << std::endl
		<< "  \\ \\  /\\  / /__  _ __ __| | | ___ " << std::endl
		<< "   \\ \\/  \\/ / _ \\| '__/ _` | |/ _ \\" << std::endl
		<< "    \\  /\\  / (_) | | | (_| | |  __/" << std::endl
		<< "     \\/  \\/ \\___/|_|  \\__,_|_|\\___|" << std::endl
		<< "                                   " << std::endl
		<< "                                   " << std::endl;
}

void	wordle::printGrid(void) const
{
	for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
	{
		std::cout << "\t";
		for (unsigned int j = 0; j < WORDLE_NB_LETTER; ++j)
		{
			std::cout << _lines[i][j];
			if (j + 1 < WORDLE_NB_LETTER)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}
