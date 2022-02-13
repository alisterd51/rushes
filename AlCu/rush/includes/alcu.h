/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:19:46 by anclarma          #+#    #+#             */
/*   Updated: 2022/02/13 11:34:33 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include "libft.h"

int		game(int fd);
int		ai_turn(t_list **lst_line);
int		human_turn(t_list **lst_line);
void	apply_move(int move, t_list **lst_line);
int		line_size(t_list *lst_line);
int		line_size_max(t_list *lst_line);
int		empty_line(char *line);
int		valid_line(char *line);
int		ft_free(char **ptr, int ret);

#endif
