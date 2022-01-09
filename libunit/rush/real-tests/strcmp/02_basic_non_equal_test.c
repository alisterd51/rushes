/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_basic_non_equal_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:18:52 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 14:22:19 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	strcmp_basic_non_equal_test(void)
{
	char	*str1;
	char	*str2;
	int		ret;
	int		fake_ret;

	str1 = "abc";
	str2 = "xyz";
	ret = ft_strcmp(str1, str2);
	fake_ret = fake_strcmp(str1, str2);
	if (fake_ret == ret)
		return (0);
	else
		return (-1);
}
