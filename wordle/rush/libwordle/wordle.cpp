/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:43:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/14 06:32:28 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include "wordle.hpp"

wordle::wordle(void) :
	_index(0)
{
	for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
		for (unsigned int j = 0; j < WORDLE_NB_LETTER; ++j)
			_lines[i][j] = '_';
	return ;
}

wordle::wordle(wordle const &src)
{
	*this = src;
	return ;
}

wordle::wordle(std::string const &filename) :
	_index(0),
	_wordList(filename)
{
	for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
		for (unsigned int j = 0; j < WORDLE_NB_LETTER; ++j)
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
		this->_wordList = rhs._wordList;
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
			else if (_secretWord.find(_lines[i][j]) != std::string::npos)
				std::cout << COLOR_YELOW;
			std::cout << _lines[i][j] << COLOR_RESET;
			if (j + 1 < WORDLE_NB_LETTER)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void	wordle::getAttemp(void)
{
	std::string	word;

	std::cout << "input: ";
	std::getline(std::cin, word);
	std::transform(word.begin(), word.end(), word.begin(), ::toupper);
	if (word.size() == 0)
		std::cout << "empty word" << std::endl;
	else if (word.size() <= WORDLE_NB_LETTER)
	{
		for (unsigned int i = 0; word[i]; ++i)
		{
			if (!isalpha(word[i]))
			{
				std::cout << "contains non-alphabetic characters" << std::endl;
				return ;
			}
		}
		this->attempt(word);
	}
	else
		std::cout << "your input is longer than " << WORDLE_NB_LETTER
			<< " letter" << std::endl;
}

void	wordle::attempt(std::string const &word)
{
	for (unsigned int i = 0; word[i]; ++i)
		_lines[_index][i] = word[i];
	++this->_index;
}

bool	wordle::game(void)
{
	this->printTitle();
	this->chooseSecretWord();
	this->printGrid();
	while (this->_index < WORDLE_NB_LINE)
	{
		this->getAttemp();
		if (std::cin.eof())
		{
			std::cout << "unexpected end of file" << std::endl;
			return (false);
		}
		this->printGrid();
		if (this->isWin())
		{
			std::cout << "Congratulations you found word " << this->_secretWord
				<< " in " << this->_index << " guesses" << std::endl;
			return (true);
		}
	}
	std::cout << "unfortunately you did not find the word " << this->_secretWord
		<< " despite " << WORDLE_NB_LINE << " guesses" << std::endl;
	return (false);
}

bool	wordle::isWin(void) const
{
	if (_index > 0)
	{
		for (unsigned int i = 0; i < WORDLE_NB_LETTER; ++i)
		{
			if (_lines[_index - 1][i] != _secretWord[i])
				return (false);
		}
		return (true);
	}
	return (false);
}

void	wordle::chooseSecretWord(void)
{
	std::ifstream	infile;
	std::string		passwd;

	infile.open(this->_wordList.c_str());
	if (infile.is_open())
	{
		std::vector<std::string>	vectorPasswd;
		std::string					word;

		while (!infile.eof())
		{
			std::getline(infile, word);
			if (word.length() == WORDLE_NB_LETTER)
				vectorPasswd.push_back(word);
		}
		std::cout << "Total words available: " << vectorPasswd.size()
			<< std::endl;
		if (vectorPasswd.size() > 0)
			passwd = vectorPasswd[rand() % vectorPasswd.size()];
		else
		{
			std::cout << "not enough words, using default password"
				<< std::endl;
			passwd = WORDLE_DEFAULT_PWD;
		}
		infile.close();
	}
	else
	{
		std::cout << "Failed to open file " << _wordList
			<< ", using default password" << std::endl;
		passwd = WORDLE_DEFAULT_PWD;
	}
	std::transform(passwd.begin(), passwd.end(), passwd.begin(), ::toupper);
	this->_secretWord = passwd;
}
