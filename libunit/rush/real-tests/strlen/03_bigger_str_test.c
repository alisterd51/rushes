/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bigger_str_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:34:53 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 21:51:27 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	strlen_bigger_str_test(void)
{
	char	str[1000001];

	ft_memset(str, 'a', 1000000);
	str[1000000] = '\0';
	if (fake_strlen(str) == ft_strlen(str))
		return (0);
	else
		return (-1);
}
