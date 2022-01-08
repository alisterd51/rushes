/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:25:18 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 12:52:52 by anclarma         ###   ########.fr       */
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

#endif

