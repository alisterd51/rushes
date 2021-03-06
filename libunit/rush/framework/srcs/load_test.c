/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:26:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 12:55:23 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libunit.h"

static void	testadd_back(t_unit_test **list, t_unit_test *new)
{
	while (*list)
		list = &((*list)->next);
	*list = new;
}

void	load_test(t_unit_test **list, char *name, int (*fonction)(void))
{
	t_unit_test	*new;

	new = (t_unit_test *)malloc(sizeof(t_unit_test));
	if (new == NULL)
		return ;
	new->name = name;
	new->fonction = fonction;
	new->next = NULL;
	testadd_back(list, new);
}
