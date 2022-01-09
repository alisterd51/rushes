/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:26:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 16:12:46 by anclarma         ###   ########.fr       */
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
	if (!WIFEXITED(status))
	{
		if (status == SIGBUS)
			ft_putendl_fd("\033[0;33m[SIGBUS]\033[0m", 1);
		else if (status == SIGABRT)
			ft_putendl_fd("\033[0;33m[SIGABRT]\033[0m", 1);
		else if (status == SIGFPE)
			ft_putendl_fd("\033[0;33m[SIGFPE]\033[0m", 1);
		else if (status == SIGPIPE)
			ft_putendl_fd("\033[0;33m[SIGPIPE]\033[0m", 1);
		else if (status == SIGILL)
			ft_putendl_fd("\033[0;33m[SIGILL]\033[0m", 1);
		else if (status == SIGSEGV)
			ft_putendl_fd("\033[0;33m[SEGV]\033[0m", 1);
	}
	else if (status == 0)
		ft_putendl_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putendl_fd("\033[0;31m[KO]\033[0m", 1);
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
	add_to_counter(status);
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
