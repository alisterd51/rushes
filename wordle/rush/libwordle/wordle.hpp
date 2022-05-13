/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:43:42 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/13 21:43:50 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_HPP
# define WORDLE_HPP

class	wordle
{
	public:
		wordle(void);
		wordle(wordle const &src);
		virtual	~wordle(void);

		wordle	&operator=(wordle const &rhs);
	protected:

	private:
		
};

#endif
