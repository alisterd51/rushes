/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:56:42 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:57:06 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fake_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
