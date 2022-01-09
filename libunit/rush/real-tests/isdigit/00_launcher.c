/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:27:16 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:45:54 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libunit.h"
#include "isdigit_test.h"

int	isdigit_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "ISDIGIT: Basic  test 1", &isdigit_basic_test_1);
	load_test(&testlist, "ISDIGIT: Basic  test 2", &isdigit_basic_test_2);
	load_test(&testlist, "ISDIGIT: Basic  test 3", &isdigit_basic_test_3);
	return (launch_tests(&testlist));
}
