/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_fpe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:34:53 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 16:34:55 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** https://stackoverflow.com/questions/6234692/why-is-there-a-sigfpe
*/
int	all_return_fpe(void)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (i / j)
		return (0);
	else
		return (-1);
}
