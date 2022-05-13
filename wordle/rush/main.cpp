/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:42:40 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/14 00:13:36 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "wordle.hpp"

int	main(void)
{
	wordle	w;

	w.printTitle();
	w.printGrid();
	return (0);
}
