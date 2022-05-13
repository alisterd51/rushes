# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 21:39:07 by anclarma          #+#    #+#              #
#    Updated: 2022/05/13 22:26:00 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.0)

project(libwordle)

set(SRCS
    wordle.cpp
    )
    
set(HEADERS
    wordle.hpp
    )

add_library(wordle ${SRCS} ${HEADERS})
target_include_directories(wordle PUBLIC .)
