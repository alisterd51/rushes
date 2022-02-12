/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:06:56 by anclarma          #+#    #+#             */
/*   Updated: 2022/02/12 11:30:08 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	valid_line(char *line)
{
	(void)line;
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
		if (fd == 0 && ft_strlen(line) == 0)
		{
			free(line);
			return (0);
		}
		new_node = ft_lstnew(line);
		ft_lstadd_back(lst_line, new_node);
		nb_line++;
		if (nb_line > 10000 || valid_line(line) == -1)
			return (-1);
		ret = get_next_line(fd, &line);
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int	game(int fd)
{
	t_list	*lst_line;

	lst_line = NULL;
	if (read_board(&lst_line, fd) != 0)
	{
		ft_lstclear(&lst_line, free);
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	ft_lstclear(&lst_line, free);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;

	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[0], O_RDONLY);
	else
		fd = -1;
	if (fd == -1 || game(fd) == -1 || (fd != 0 && close(fd) == -1))
		return (1);
	return (0);
}
