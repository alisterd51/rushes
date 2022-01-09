/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:33:21 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 16:46:06 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libunit.h"
#include "strcmp_test.h"

int	strcmp_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "STRCMP: Basic equal test", &strcmp_basic_equal_test);
	load_test(&testlist, "STRCMP: Basic non-equal test",
		&strcmp_basic_non_equal_test);
	load_test(&testlist, "STRCMP: Null test", &strcmp_null_test);
	load_test(&testlist, "STRCMP: Null 2 test", &strcmp_null_2_test);
	load_test(&testlist, "STRCMP: Null 3 test", &strcmp_null_3_test);
	load_test(&testlist, "STRCMP: Null 4 test", &strcmp_null_4_test);
	return (launch_tests(&testlist));
}
