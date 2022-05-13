/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:43:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/13 21:43:32 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
