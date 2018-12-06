#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 14:13:15 by gdamion-          #+#    #+#              #
#    Updated: 2018/12/06 20:23:37 by gdamion-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAMEL = libft.a
NAME = libft
SRCS = *.c
HEAD = *.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS) -I$(HEAD)
	ar rc $(NAMEL) *.o
	ranlib $(NAMEL)

clean:
	rm -rf *.o *.h.gch

fclean: clean
	rm -rf $(NAMEL)

re: fclean all