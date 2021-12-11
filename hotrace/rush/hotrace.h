/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:45:11 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/11 16:18:35 by anclarma         ###   ########.fr       */
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
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		get_next_line(int fd, char **line);

/*
** ft.c
*/
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_put_error(char *str);
void	ft_putendl_stdout(char *str);

/*
** intern_dico.c
*/
void	intern_dico(int mode, char **line);

#endif
