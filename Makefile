#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 14:13:15 by gdamion-          #+#    #+#              #
#    Updated: 2018/11/29 17:07:28 by gdamion-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRCS = srcs/*.c
HEAD = srcs/*.h
FLAGS = -Wall -Wextra -Werror

all: make_lib

make_lib:
	gcc -c $(FLAGS) $(SRCS) -I$(HEAD)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -rf *.o *.h.gch

fclean: clean
	rm -rf $(NAME)

re: fclean all