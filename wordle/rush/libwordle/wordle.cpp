/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:43:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/13 22:58:12 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "wordle.hpp"

wordle::wordle(void)
{
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
	return (*this);
}

void	wordle::title(void) const
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
