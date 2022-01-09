/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_basic_test_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:02:48 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:05:46 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	isspace_basic_test_4(void)
{
	char	c;

	c = '\r';
	if (fake_isspace(c) == ft_isspace(c))
		return (0);
	else
		return (-1);
}
