/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:32:40 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 18:54:25 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen_test.h"
#include "libunit.h"

int	main(int ac, char **av)
{
	int	ret;

	(void)ac;
	(void)av;
	ret = 0;
	ret += strlen_launcher();
	print_counter();
	if (ret == 0)
		return (0);
	else
		return (-1);
}
