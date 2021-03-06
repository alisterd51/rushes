/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:32:40 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 17:36:22 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen_test.h"
#include "strcmp_test.h"
#include "strjoin_test.h"
#include "isspace_test.h"
#include "isdigit_test.h"
#include "libunit.h"

int	main(int ac, char **av)
{
	int	ret;

	(void)ac;
	(void)av;
	ret = 0;
	ret += strlen_launcher();
	ret += strcmp_launcher();
	ret += strjoin_launcher();
	ret += isspace_launcher();
	ret += isdigit_launcher();
	print_counter();
	if (ret == 0)
		return (0);
	else
		return (-1);
}
