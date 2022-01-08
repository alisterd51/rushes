/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:09:56 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 15:13:46 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libunit.h"

void	clean_tests(t_unit_test **list)
{
	t_unit_test	*element;
	t_unit_test	*current;

	current = *list;
	while (current)
	{
		element = current;
		current = current->next;
		free(element);
	}
	*list = NULL;
}
