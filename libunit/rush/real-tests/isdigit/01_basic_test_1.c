/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:38:13 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:36:06 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	isdigit_basic_test_1(void)
{
	int	c;

	c = 0;
	if (fake_isdigit(c) == ft_isdigit(c))
		return (0);
	else
		return (-1);
}
