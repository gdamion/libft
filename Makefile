# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 14:13:15 by gdamion-          #+#    #+#              #
#    Updated: 2019/08/18 19:37:26 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

######################### IS ########################
SRC_IS	=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_is_inf.c \
			ft_is_nan.c

SRC_IS_D = $(addprefix ft_is/,$(SRC_IS))

######################### LST ########################
SRC_LST	=	ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c

SRC_LST_D = $(addprefix ft_lst/,$(SRC_LST))

######################### MEM ########################
SRC_MEM	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memalloc.c \
			ft_memdel.c

SRC_MEM_D = $(addprefix ft_mem/,$(SRC_MEM))

######################### PUT ########################
SRC_PUT	=	ft_putchar.c \
			ft_putstr.c \
			ft_putnstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

SRC_PUT_D = $(addprefix ft_put/,$(SRC_PUT))

######################### STR ########################
SRC_STR	=	ft_strlen.c \
			ft_strnlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c

SRC_STR_D = $(addprefix ft_str/,$(SRC_STR))

######################### TRANSLATE ########################
SRC_TRNSLT =	ft_atoi.c \
				ft_itoa.c \
				ft_toupper.c \
				ft_tolower.c

SRC_TRNSLT_D = $(addprefix translate/,$(SRC_TRNSLT))

######################### GNL ##########################
SRC_GNL = get_next_line.c

SRC_GNL_D = $(addprefix get_next_line/,$(SRC_GNL))

######################## PRINTF ########################
SRC_PRINTF	=	c_handle.c \
				d_i_handle.c \
				o_handle.c \
				o_handle2.c \
				p_handle.c \
				proc_handle.c \
				f_handle.c \
				f_handle2.c \
				s_handle.c \
				u_handle.c \
				x_handle.c \
				x_handle2.c \
				ft_itoa_long.c \
				printf.c \
				printf_read.c \
				ulong_init.c

SRC_PRINTF_D = $(addprefix ft_printf/,$(SRC_PRINTF))
########################################################

FLAGS	=	-Wall -Wextra -Werror

INC		=	-I ./inc

SRC		=	$(SRC_IS) $(SRC_LST) $(SRC_MEM) $(SRC_PUT) \
			$(SRC_STR) $(SRC_GNL) $(SRC_TRNSLT) $(SRC_PRINTF)

SRC_D	=	$(addprefix src/,$(SRC_IS_D) $(SRC_LST_D) $(SRC_MEM_D) \
			$(SRC_PUT_D) $(SRC_STR_D) $(SRC_GNL_D) $(SRC_TRNSLT_D) $(SRC_PRINTF_D))

OBJ		=	$(addprefix obj/,$(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC_D)
	@gcc $(FLAGS) -c $(SRC_D) $(INC)
	@mkdir -p obj/
	@echo "$(GREEN)Oblect files are created!$(RESET)"
	@mv $(SRC:.c=.o) obj/
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME) library is created!$(RESET)"

clean:
	@rm -Rf obj/

fclean: clean
	@rm -f $(NAME);

re: fclean all
