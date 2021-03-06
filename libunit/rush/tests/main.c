/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:32:40 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 11:21:28 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen_test.h"
#include "all_return_test.h"
#include "libunit.h"

int	main(int ac, char **av)
{
	int	ret;

	(void)ac;
	(void)av;
	ret = 0;
	ret += strlen_launcher();
	ret += all_return_launcher();
	print_counter();
	if (ret == 0)
		return (0);
	else
		return (-1);
}
