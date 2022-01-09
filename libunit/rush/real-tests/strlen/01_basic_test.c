/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:34:53 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 14:08:20 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	strlen_basic_test(void)
{
	char	*str;

	str = "abc";
	if (fake_strlen(str) == ft_strlen(str))
		return (0);
	else
		return (-1);
}
