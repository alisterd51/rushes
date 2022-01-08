/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bigger_str_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:34:53 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 16:41:39 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

int	bigger_str_test(void)
{
	char	*str;

	str = malloc(1000001);
	if (str == NULL)
		return (-1);
	ft_memset(str, 'a', 1000000);
	str[1000000] = '\0';
	if (ft_strlen(str) == 1000000)
		return (0);
	else
		return (-1);

}
