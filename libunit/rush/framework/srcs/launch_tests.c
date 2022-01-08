/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:26:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 14:17:56 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "libunit.h"

static void	print_test(char *name)
{
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" : ", 1);
}

static void	print_result(int status)
{
	if (status == 0)
		ft_putendl_fd("[OK]", 1);
	else if (0)
		ft_putendl_fd("[SIGSEGV]", 1);
	else if (0)
		ft_putendl_fd("[SIGBUS]", 1);
	else
		ft_putendl_fd("[KO]", 1);
}

static int	exec_test(t_unit_test *test)
{
	pid_t	pid;
	int		status;

	print_test(test->name);
	pid = fork();
	if (pid == 0)
	{
		exit(test->fonction());
	}
	else
	{
		wait(&status);
	}
	print_result(status);
	if (status == 0)
		return (0);
	else
		return (-1);
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
