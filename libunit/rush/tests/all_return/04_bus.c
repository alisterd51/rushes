/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_bus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:34:53 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 14:33:06 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Enable Alignment Checking on x86_64
** https://en.wikipedia.org/wiki/Bus_error
*/
int	all_return_bus(void)
{
    __asm__("pushf\norl $0x40000,(%rsp)\npopf");
	if (0)
		return (0);
	else
		return (-1);
}
