/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_basic_test_6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:58:02 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:06:02 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	isspace_basic_test_6(void)
{
	char	c;

	c = '\v';
	if (fake_isspace(c) == ft_isspace(c))
		return (0);
	else
		return (-1);
}
