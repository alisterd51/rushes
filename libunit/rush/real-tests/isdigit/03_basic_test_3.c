/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_basic_test_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:33:10 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:37:44 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	isdigit_basic_test_3(void)
{
	int	c;

	c = -1;
	if (fake_isspace(c) == ft_isspace(c))
		return (0);
	else
		return (-1);
}
