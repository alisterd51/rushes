/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:56:49 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:08:35 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fake_libft.h"

int	strjoin_null_test_1(void)
{
	char	*str1;
	char	*str2;
	char	*joint_str_fake;
	int		ret;

	str1 = "Hello World";
	str2 = NULL;
	joint_str_fake = fake_strjoin(str1, str2);
	if (joint_str_fake == NULL)
		ret = 0;
	else
		ret = -1;
	free(joint_str_fake);
	joint_str_fake = NULL;
	return (ret);
}
