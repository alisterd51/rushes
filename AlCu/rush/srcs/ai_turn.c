/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:06:56 by anclarma          #+#    #+#             */
/*   Updated: 2022/02/13 17:33:17 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"

static int	eval_line(int line)
{
	return (line == 1 || (line - 1) % 4 == 0);
}

static int	ia_choice_win(int line)
{
	if (line == 1 || (line - 1) % 4 == 0)
		return (1);
	else
		return ((line - 1) % 4);
}

static int	ia_choice_lose(int line)
{
	if (line % 4 == 0)
		return (1);
	else
		return (line % 4);
}

static int	eval_all_line(t_list *lst_line)
{
	int	objectif;

	objectif = 0;
	while (lst_line && lst_line->next)
	{
		if (objectif == 0 && eval_line(ft_atoi(lst_line->content)) == 0)
			objectif = 0;
		else if (objectif == 0 && eval_line(ft_atoi(lst_line->content)) == 1)
			objectif = 1;
		else if (objectif == 1 && eval_line(ft_atoi(lst_line->content)) == 0)
			objectif = 0;
		else if (objectif == 1 && eval_line(ft_atoi(lst_line->content)) == 1)
			objectif = 0;
		lst_line = lst_line->next;
	}
	return (objectif);
}

int	ai_turn(t_list **lst_line)
{
	int	move;

	if (ft_lstsize(*lst_line) == 1 || eval_all_line(*lst_line) == 0)
		move = ia_choice_win(ft_atoi(ft_lstlast(*lst_line)->content));
	else
		move = ia_choice_lose(ft_atoi(ft_lstlast(*lst_line)->content));
	ft_putstr_fd("AI took ", 1);
	ft_putnbr_fd(move, 1);
	ft_putchar_fd('\n', 1);
	apply_move(move, lst_line);
	if (*lst_line == NULL)
		return (1);
	if (ft_lstlast(*lst_line)->content == NULL)
		return (-2);
	return (0);
}
