# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 21:31:26 by anclarma          #+#    #+#              #
#    Updated: 2022/05/13 22:35:10 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.0)
project(worlde)

add_subdirectory(libwordle)

set(SRCS
	main.cpp
	)

add_executable(main ${SRCS})

target_link_libraries(main wordle)
