/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:26:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 18:21:30 by anclarma         ###   ########.fr       */
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
	if (WIFEXITED(status) && status == 0)
		ft_putendl_fd("[OK]", 1);
	else if (WIFEXITED(status) && status)
		ft_putendl_fd("[KO]", 1);
	else if (status & SIGSEGV)
		ft_putendl_fd("[SEGV]", 1);
	else if (status & SIGBUS)
		ft_putendl_fd("[SIGBUS]", 1);
	else if (status & SIGABRT)
		ft_putendl_fd("[SIGABRT]", 1);
	else if (status & SIGFPE)
		ft_putendl_fd("[SIGFPE]", 1);
	else if (status & SIGPIPE)
		ft_putendl_fd("[SIGPIPE]", 1);
	else if (status & SIGILL)
		ft_putendl_fd("[SIGILL]", 1);
}

static int	exec_test(t_unit_test **list, t_unit_test *test)
{
	pid_t	pid;
	int		status;

	print_test(test->name);
	pid = fork();
	if (pid == 0)
	{
		status = test->fonction();
		clean_tests(list);
		exit(status);
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
		ret += exec_test(list, test);
		test = test->next;
	}
	clean_tests(list);
	if (ret == 0)
		return (0);
	else
		return (-1);
}
