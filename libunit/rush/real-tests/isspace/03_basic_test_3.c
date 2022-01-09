/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_basic_test_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:54:03 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:05:38 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	isspace_basic_test_3(void)
{
	char	c;

	c = '\n';
	if (fake_isspace(c) == ft_isspace(c))
		return (0);
	else
		return (-1);
}
