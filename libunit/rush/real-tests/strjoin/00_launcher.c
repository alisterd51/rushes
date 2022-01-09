/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:33:21 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 18:08:04 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libunit.h"
#include "strjoin_test.h"

int	strjoin_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "STRJOIN: Basic test", &strjoin_basic_test);
	load_test(&testlist, "STRJOIN: Null test 1", &strjoin_null_test_1);
	load_test(&testlist, "STRJOIN: Null test 2", &strjoin_null_test_2);
	load_test(&testlist, "STRJOIN: Empty string test 1",
		&strjoin_empty_str_test_1);
	load_test(&testlist, "STRJOIN: Empty string test 2",
		&strjoin_empty_str_test_2);
	load_test(&testlist, "STRJOIN: Empty string test 3",
		&strjoin_empty_str_test_3);
	return (launch_tests(&testlist));
}
