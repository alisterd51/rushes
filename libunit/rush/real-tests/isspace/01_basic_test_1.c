/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:38:13 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:05:21 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	isspace_basic_test_1(void)
{
	char	c;

	c = ' ';
	if (fake_isspace(c) == ft_isspace(c))
		return (0);
	else
		return (-1);
}
