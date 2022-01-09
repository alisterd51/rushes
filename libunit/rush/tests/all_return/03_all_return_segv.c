/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_all_return_segv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:34:53 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 11:40:32 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	all_return_segv(void)
{
	char	*str;

	str = (char *)0x1;
	if (ft_strlen(str) == 0)
		return (0);
	else
		return (-1);
}
