#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 14:13:15 by gdamion-          #+#    #+#              #
#    Updated: 2018/12/06 21:41:04 by gdamion-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRCS = *.c
HEAD = *.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS) -I$(HEAD)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -rf *.o *.h.gch

fclean: clean
	rm -rf $(NAME)

re: fclean all