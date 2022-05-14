/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:43:42 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/14 02:42:16 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_HPP
# define WORDLE_HPP

# define WORDLE_NB_LINE		6U
# define WORDLE_NB_LETTER	5U

# define COLOR_GREEN		"\033[1;32m"
# define COLOR_YELOW		"\033[1;33m"
# define COLOR_RESET		"\033[0m"

class	wordle
{
	public:
		wordle(void);
		wordle(wordle const &src);
		wordle(std::string const &secret);
		virtual	~wordle(void);

		wordle	&operator=(wordle const &rhs);
		void	printTitle(void) const;
		void	printGrid(void) const;
		bool	getAttemp(void);
		void	attempt(std::string const &word);
		bool	game(void);
	protected:

	private:
		char			_lines[WORDLE_NB_LINE][WORDLE_NB_LETTER];
		unsigned int	_index;
		std::string		_secretWord;
};

#endif
