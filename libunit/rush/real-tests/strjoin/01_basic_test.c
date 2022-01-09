/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:08:12 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:08:22 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fake_libft.h"

int	strjoin_basic_test(void)
{
	char	*str1;
	char	*str2;
	char	*joint_str;
	char	*joint_str_fake;
	int		ret;

	str1 = "hello";
	str2 = "world";
	joint_str = ft_strjoin(str1, str2);
	joint_str_fake = fake_strjoin(str1, str2);
	if (ft_strcmp(joint_str, joint_str_fake) == 0)
		ret = 0;
	else
		ret = -1;
	free(joint_str);
	joint_str = NULL;
	free(joint_str_fake);
	joint_str_fake = NULL;
	return (ret);
}
