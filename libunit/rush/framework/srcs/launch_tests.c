/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:26:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 13:34:23 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "libunit.h"

static int	exec_test(t_unit_test *test)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		exit(test->fonction());
	}
	else
	{
		wait(&status);
	}
	return (0);
}

int	launch_tests(t_unit_test **list)
{
	int			ret;
	t_unit_test	*test;

	ret = 0;
	test = *list;
	while (test)
	{
		ret += exec_test(test);
		test = test->next;
	}
	if (ret == 0)
		return (0);
	else
		return (-1);
}
