/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:43:42 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/14 00:40:06 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_HPP
# define WORDLE_HPP

# define WORDLE_NB_LINE		6U
# define WORDLE_NB_LETTER	5U

class	wordle
{
	public:
		wordle(void);
		wordle(wordle const &src);
		virtual	~wordle(void);

		wordle	&operator=(wordle const &rhs);
		void	printTitle(void) const;
		void	printGrid(void) const;
	protected:

	private:
		char	_lines[WORDLE_NB_LINE][WORDLE_NB_LETTER];
};

#endif
