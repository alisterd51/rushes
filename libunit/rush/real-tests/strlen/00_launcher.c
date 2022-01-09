/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:33:21 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 15:39:36 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libunit.h"
#include "strlen_test.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "STRLEN: Basic test", &strlen_basic_test);
	load_test(&testlist, "STRLEN: Basic test 2", &strlen_basic_test2);
	load_test(&testlist, "STRLEN: NULL test", &strlen_null_test);
	load_test(&testlist, "STRLEN: NULL test2", &strlen_null_test2);
	load_test(&testlist, "STRLEN: Bigger string test", &strlen_bigger_str_test);
	return (launch_tests(&testlist));
}
