/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:34:53 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 18:30:35 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	strlen_null_test2(void)
{
	char	*str;

	str = "";
	if (fake_strlen(str) == ft_strlen(str))
		return (0);
	else
		return (-1);
}
