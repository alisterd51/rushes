/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_all_return_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:33:21 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 11:33:04 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libunit.h"
#include "all_return_test.h"

int	all_return_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "ALL: ok test", &all_return_ok);
	load_test(&testlist, "ALL: ko test", &all_return_ko);
	load_test(&testlist, "ALL: sigsegv test", &all_return_segv);
	load_test(&testlist, "ALL: sigbus test", &all_return_bus);
	return (launch_tests(&testlist));
}
