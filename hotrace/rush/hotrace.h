/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:45:11 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/11 13:59:19 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stddef.h>

/*
**
*/
typedef struct s_dico	t_dico;
struct	s_dico
{
	char	*value;
	t_dico	*next[128];
};

/*
** get_next_line.c
*/
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t count, size_t size);

#endif
