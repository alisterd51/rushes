/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:06:56 by anclarma          #+#    #+#             */
/*   Updated: 2022/02/13 05:21:18 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#include <stdio.h>

int	line_size(t_list *lst_line)
{
	return (ft_atoi(lst_line->content));
}

int	line_size_max(t_list *lst_line)
{
	int	max;
	int	n_current;

	max = 0;
	while (lst_line)
	{
		n_current = line_size(lst_line);
		if (n_current > max)
			max = n_current;
		lst_line = lst_line->next;
	}
	return (max);
}

void	print_line(int current, int max)
{
	int	diff;

	diff = max - current;
	while (diff-- > 0)
		write(1, " ", 1);
	while (current-- > 0)
		write(1, " |", 2);
	write(1, "\n", 1);
}

void	print_board(t_list *lst_line)
{
	int	n_max;

	n_max = line_size_max(lst_line);
	while (lst_line)
	{
		print_line(line_size(lst_line), n_max);
		lst_line = lst_line->next;
	}
}

int	ft_strisdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	empty_line(char *line)
{
	return (line && line[0] == '\0');
}

int	valid_line(char *line)
{
	if (!empty_line(line) && (!ft_secure_atoi(line) || !ft_strisdigit(line)
				|| ft_atoi(line) <= 0))
		return (1);
	return (0);
}

int	read_board(t_list **lst_line, int fd)
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
		{
			free(line);
			return (0);
		}
		new_node = ft_lstnew(line);
		ft_lstadd_back(lst_line, new_node);
		nb_line++;
		if (nb_line > 10000 || valid_line(line) != 0)
			return (-1);
		ret = get_next_line(fd, &line);
	}
	if (ret == -1 || (ret == 0 && line))
	{
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}

int	is_valid_move(int move, t_list *lst_line)
{
	return (move >= 1 && move <= 3 && move <= ft_atoi(ft_lstlast(lst_line)->content));
}

void	apply_move(int move, t_list **lst_line)
{
	t_list *prev;
	t_list *current;
	int		num_tmp;

	if (*lst_line == NULL)
		return ;
	prev = NULL;
	current = *lst_line;
	while (current && current->next)
	{
		prev = current;
		current = current->next;
	}
	if (ft_atoi(current->content) == move)
	{
		ft_lstdelone(current, free);
		if (prev != NULL)
			prev->next = NULL;
		else
			*lst_line = NULL;
	}
	else
	{
		num_tmp = ft_atoi(current->content);
		free(current->content);
		current->content = ft_itoa(num_tmp - move);
	}
}
int	eval_line(int line)
{
	return (line == 1 || (line - 1) % 4 == 0);
}

int	eval_all_line(t_list *lst_line)
{
	int	n;

	n = 0;
	while (lst_line && lst_line->next)
	{
		n += eval_line(ft_atoi(lst_line->content));
		lst_line = lst_line->next;
	}
	return (n);
}

int	ia_choice_win(int line)
{
	if (line == 1 || (line - 1) % 4 == 0)
		return (1);
	else
		return ((line - 1) % 4);
}

int	ia_choice_lose(int line)
{
	if (line < 4)
		return (line);
	else
		return (4 - ia_choice_win(line));
}

int	ai_turn(t_list **lst_line)
{
	int	move;

	if (ft_lstsize(*lst_line) == 1 || eval_all_line(*lst_line) % 2 == 0)
		move = ia_choice_win(ft_atoi(ft_lstlast(*lst_line)->content));
	else
		move = ia_choice_lose(ft_atoi(ft_lstlast(*lst_line)->content));
	ft_putstr_fd("AI took ", 1);
	ft_putnbr_fd(move, 1);
	ft_putchar_fd('\n', 1);
	apply_move(move, lst_line);
	if (*lst_line == NULL)
		return (1);
	return (0);
}

int	human_turn(t_list **lst_line)
{
	int		ret;
	int		valid_choice;
	char	*line;

	(void)lst_line;
	valid_choice = 0;
	ft_putendl_fd("Please choose between 1 and 3 items", 1);
	ret = get_next_line(0, &line);
	while (valid_choice == 0 && line)
	{
		if (valid_line(line) == 0 && is_valid_move(ft_atoi(line), *lst_line))
		{
			apply_move(ft_atoi(line), lst_line);
			valid_choice = 1;
			free(line);
			line = NULL;
		}
		else
		{
			ft_putstr_fd(line, 1);
			ft_putendl_fd(" - Invalid choice", 1);
			ft_putendl_fd("Please choose between 1 and 3 items", 1);
			free(line);
			line = NULL;
			ret = get_next_line(0, &line);
		}
	}
	free(line);
	if (*lst_line == NULL)
		return (2);
	return (0);
}

void	game_loop(t_list **lst_line)
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
		return (1);
	}
	close(fd);
	if (fd == 0)
		open("/dev/tty", O_RDONLY);
	game_loop(&lst_line);
	ft_lstclear(&lst_line, free);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;

	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = -1;
	if (fd == -1 || game(fd) == -1 || (fd != 0 && close(fd) == -1))
		return (1);
	return (0);
}
