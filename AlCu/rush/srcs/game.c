/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:06:56 by anclarma          #+#    #+#             */
/*   Updated: 2022/02/13 12:50:21 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "alcu.h"

static void	print_line(int current, int max)
{
	int	diff;

	diff = max - current;
	while (diff-- > 0)
		write(1, " ", 1);
	while (current-- > 0)
		write(1, " |", 2);
	write(1, "\n", 1);
}

static void	print_board(t_list *lst_line)
{
	int	n_max;

	n_max = line_size_max(lst_line);
	while (lst_line)
	{
		print_line(line_size(lst_line), n_max);
		lst_line = lst_line->next;
	}
}

static int	read_board(t_list **lst_line, int fd)
{
	t_list	*new_node;
	size_t	nb_line;
	char	*line;
	int		ret;

	nb_line = 0;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		if (empty_line(line))
			return (ft_free(&line, 0));
		new_node = ft_lstnew(line);
		if (new_node == NULL)
			return (ft_free(&line, -1));
		ft_lstadd_back(lst_line, new_node);
		nb_line++;
		if (nb_line > 10000 || valid_line(line) != 0)
			return (-1);
		ret = get_next_line(fd, &line);
	}
	if (ret == -1 || (ret == 0 && line))
		return (ft_free(&line, -1));
	return (ft_free(&line, 0));
}

static void	game_loop(t_list **lst_line)
{
	int	end;

	end = 0;
	while (!end)
	{
		print_board(*lst_line);
		end = ai_turn(lst_line);
		if (!end)
		{
			print_board(*lst_line);
			end = human_turn(lst_line);
		}
	}
	if (end == 2)
		ft_putendl_fd("AI is the winner! shame on you!", 1);
	else if (end == 1)
		ft_putendl_fd("You are the winner! Congratulations!", 1);
	else if (end == -1)
		ft_putendl_fd("stdin has been closed for an unknown reason", 1);
	else if (end == -2)
		ft_putendl_fd("malloc error", 1);
}

int	game(int fd)
{
	t_list	*lst_line;

	lst_line = NULL;
	if (read_board(&lst_line, fd) != 0 || lst_line == NULL)
	{
		close(fd);
		ft_lstclear(&lst_line, free);
		ft_putendl_fd("ERROR", 2);
		return (-1);
	}
	close(fd);
	if (fd == 0)
		open("/dev/tty", O_RDONLY);
	game_loop(&lst_line);
	ft_lstclear(&lst_line, free);
	return (0);
}
