/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_abort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:34:53 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 16:25:07 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** https://stackoverflow.com/questions/11161126/what-causes-a-sigabrt-fault
*/
int	all_return_abort(void)
{
	abort();
	if (0)
		return (0);
	else
		return (-1);
}
