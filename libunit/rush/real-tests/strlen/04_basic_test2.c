/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_basic_test2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:38:27 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 15:39:51 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	strlen_basic_test2(void)
{
	char	*str;

	str = "a";
	if (fake_strlen(str) == ft_strlen(str))
		return (0);
	else
		return (-1);
}
