/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:33:21 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 18:17:57 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libunit.h"
#include "isspace_test.h"

int	isspace_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "ISSPACE: Basic  test 1", &isspace_basic_test_1);
	load_test(&testlist, "ISSPACE: Basic  test 2", &isspace_basic_test_2);
	load_test(&testlist, "ISSPACE: Basic  test 3", &isspace_basic_test_3);
	load_test(&testlist, "ISSPACE: Basic  test 4", &isspace_basic_test_4);
	load_test(&testlist, "ISSPACE: Basic  test 5", &isspace_basic_test_5);
	load_test(&testlist, "ISSPACE: Basic  test 6", &isspace_basic_test_6);
	return (launch_tests(&testlist));
}
