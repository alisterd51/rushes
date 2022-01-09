/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:32:40 by anclarma          #+#    #+#             */
/*   Updated: 2022/01/09 13:01:02 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft_test.h"

int	main(void)
{
	int	ret;

	ret = 0;
	ret += ft_isalnum_launcher();
	ret += ft_isalpha_launcher();
	ret += ft_isascii_launcher();
	ret += ft_tolower_launcher();
	ret += ft_toupper_launcher();
	ret += ft_memccpy_launcher();
	ret += ft_memcpy_launcher();
	ret += ft_memset_launcher();
	ret += ft_strdup_launcher();
	ret += ft_strlcat_launcher();
	ret += ft_strlcpy_launcher();
	ret += ft_strlen_launcher();
	ret += ft_strlen_launcher();
	ret += ft_bzero_launcher();
	ret += ft_atoi_launcher();
	ret += ft_calloc_launcher();
	print_counter();
	if (ret == 0)
		return (0);
	else
		return (-1);
}
