# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 14:13:15 by gdamion-          #+#    #+#              #
#    Updated: 2019/03/25 11:09:39 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

######################### LIBFT ########################
SRC =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
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
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
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
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_is_inf.c \
		ft_is_nan.c

SRC_DIR = src/
########################################################

######################## PRINTF ########################
P_SRC =	c_handle.c \
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

P_SRC_DIR = src_printf/
########################################################


OBJ = $(patsubst %.c,%.o,$(SRC))
P_OBJ = $(patsubst %.c,%.o,$(P_SRC))

OBJ_DIR_COMMON = obj/
OBJ_DIR = $(OBJ_DIR_COMMON)o_libft/
P_OBJ_DIR = $(OBJ_DIR_COMMON)o_printf/

HEADER_DIR = includes/

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $< -o $@ -I $(HEADER_DIR)

$(P_OBJ_DIR)%.o: $(P_SRC_DIR)%.c
	@mkdir -p $(P_OBJ_DIR)
	@gcc -c $< -o $@ -I $(HEADER_DIR)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJ)) $(addprefix $(P_OBJ_DIR),$(P_OBJ))
	@ar rcs $(NAME) $(addprefix $(OBJ_DIR),$(OBJ)) $(addprefix $(P_OBJ_DIR),$(P_OBJ))

clean:
	@rm -Rf $(OBJ_DIR_COMMON)

fclean: clean
	@rm -f $(NAME);

re: fclean all
