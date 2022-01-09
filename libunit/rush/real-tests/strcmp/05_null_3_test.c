/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:20:04 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 14:26:44 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fake_libft.h"

int	strcmp_null_3_test(void)
{
	char	*str1;
	char	*str2;
	int		ret;
	int		fake_ret;

	str1 = "";
	str2 = "abc";
	ret = ft_strcmp(str1, str2);
	fake_ret = fake_strcmp(str1, str2);
	if (fake_ret == ret)
		return (0);
	else
		return (-1);
}
