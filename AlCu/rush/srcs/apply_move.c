/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:06:56 by anclarma          #+#    #+#             */
/*   Updated: 2022/02/13 11:32:19 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	delete_line(t_list **begin, t_list *prev, t_list *current)
{
	ft_lstdelone(current, free);
	if (prev != NULL)
		prev->next = NULL;
	else
		*begin = NULL;
}

static void	change_line(int move, t_list *current)
{
	int	num_tmp;

	num_tmp = ft_atoi(current->content);
	free(current->content);
	current->content = ft_itoa(num_tmp - move);
}

void	apply_move(int move, t_list **lst_line)
{
	t_list	*prev;
	t_list	*current;

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
		delete_line(lst_line, prev, current);
	else
		change_line(move, current);
}
