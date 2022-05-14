/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:43:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/14 02:48:07 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "wordle.hpp"

wordle::wordle(void) :
	_index(0)
{
	for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
		for (unsigned int j = 0; j < WORDLE_NB_LINE; ++j)
			_lines[i][j] = '_';
	return ;
}

wordle::wordle(wordle const &src)
{
	*this = src;
	return ;
}

wordle::wordle(std::string const &secret) :
	_index(0),
	_secretWord(secret)
{
	for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
		for (unsigned int j = 0; j < WORDLE_NB_LINE; ++j)
			_lines[i][j] = '_';
	return ;
}

wordle::~wordle(void)
{
	return ;
}

wordle	&wordle::operator=(wordle const &rhs)
{
	if (this != &rhs)
	{
		for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
			for (unsigned int j = 0; j < WORDLE_NB_LINE; ++j)
				this->_lines[i][j] = rhs._lines[i][j];
		this->_index = rhs._index;
		this->_secretWord = rhs._secretWord;
	}
	return (*this);
}

void	wordle::printTitle(void) const
{
	std::cout
		<< " __          __           _ _      " << std::endl
		<< " \\ \\        / /          | | |     " << std::endl
		<< "  \\ \\  /\\  / /__  _ __ __| | | ___ " << std::endl
		<< "   \\ \\/  \\/ / _ \\| '__/ _` | |/ _ \\" << std::endl
		<< "    \\  /\\  / (_) | | | (_| | |  __/" << std::endl
		<< "     \\/  \\/ \\___/|_|  \\__,_|_|\\___|" << std::endl
		<< "                                   " << std::endl
		<< "                                   " << std::endl;
}

void	wordle::printGrid(void) const
{
	for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
	{
		std::cout << "\t";
		for (unsigned int j = 0; j < WORDLE_NB_LETTER; ++j)
		{
			if (_lines[i][j] == toupper(_secretWord[j]))
				std::cout << COLOR_GREEN;
			else if (_secretWord.find(_lines[i][j]) != std::string::npos
					|| _secretWord.find(tolower(_lines[i][j]))
					!= std::string::npos)
				std::cout << COLOR_YELOW;
			std::cout << _lines[i][j] << COLOR_RESET;
			if (j + 1 < WORDLE_NB_LETTER)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

bool	wordle::getAttemp(void)
{
	std::string	word;

	std::cout << "input: ";
	std::getline(std::cin, word);
	this->attempt(word);
	return (true);
}

void	wordle::attempt(std::string const &word)
{
	if (word.size() <= WORDLE_NB_LETTER)
	{
		for (unsigned int i = 0; word[i]; ++i)
		{
			_lines[_index][i] = toupper(word[i]);
		}
		++this->_index;
	}
}

bool	wordle::game(void)
{
	this->printTitle();
	while (this->_index < WORDLE_NB_LINE)
	{
		this->getAttemp();
		if (std::cin.eof())
		{
			std::cout << "unexpected end of file" << std::endl;
			break;
		}
		this->printGrid();
	}
	return (false);
}
