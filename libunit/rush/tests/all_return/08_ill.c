/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_ill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:34:53 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 16:56:02 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

/*
**
*/
int	all_return_ill(void)
{
	if (raise(SIGILL))
		return (0);
	else
		return (-1);
}