/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:33:21 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/08 18:31:05 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libunit.h"
#include "strlen_test.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "STRLEN: Basic test", &basic_test);
	load_test(&testlist, "STRLEN: NULL test", &null_test);
	load_test(&testlist, "STRLEN: Bigger string test", &bigger_str_test);
	return (launch_tests(&testlist));
}
