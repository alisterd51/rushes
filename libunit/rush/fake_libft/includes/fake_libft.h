/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:10:12 by thi-nguy          #+#    #+#             */
/*   Updated: 2022/01/09 18:56:15 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAKE_LIBFT_H
# define FAKE_LIBFT_H

# include <stddef.h>

int		fake_strcmp(const char *s1, const char *s2);
size_t	fake_strlen(const char *s);
char	*fake_strjoin(char const *s1, char const *s2);
int		fake_isspace(int c);
int		fake_isdigit(int c);

#endif
