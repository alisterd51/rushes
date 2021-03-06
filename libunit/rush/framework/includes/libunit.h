/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:25:18 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 18:45:11 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

typedef struct s_unit_test	t_unit_test;
struct	s_unit_test
{
	char		*name;
	int			(*fonction)(void);
	t_unit_test	*next;
};

void	load_test(t_unit_test **list, char *name, int (*fonction)(void));
int		launch_tests(t_unit_test **list);
void	clean_tests(t_unit_test **list);
void	print_counter(void);
void	add_to_counter(int status);
#endif
