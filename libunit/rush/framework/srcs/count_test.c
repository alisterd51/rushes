/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:46:31 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 19:01:25 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	counter(int mode, int status)
{
	static int	count = 0;
	static int	valid = 0;

	if (mode == 0)
	{
		count++;
		if (status == 0)
			valid++;
	}
	else
	{
		ft_putnbr_fd(valid, 1);
		ft_putchar_fd('/', 1);
		ft_putnbr_fd(count, 1);
		ft_putendl_fd(" tests checked", 1);
	}
}

void	print_counter(void)
{
	counter(1, 0);
}

void	add_to_counter(int status)
{
	counter(0, status);
}
