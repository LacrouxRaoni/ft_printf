# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 13:21:20 by rruiz-la          #+#    #+#              #
#    Updated: 2021/11/02 16:21:26 by rruiz-la         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

PATH_LIBFT	= ./libft

LIBFT	= ./libft/libft.a

CC	= clang

CFLAGS	= -Wall -Werror -Wextra

SRC	=	ft_printf.c \
		ft_printf_csdiu%.c \
		ft_printf_pxX.c \
		ft_usgitoa.c \
		ft_hxitoa.c \


OBJ	=	$(SRC:.c=.o)

all:	$(NAME) $(LIBFT) $(HEADER)

$(NAME):	$(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs	$(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(PATH_LIBFT)

clean:
		rm -rf $(OBJ)
		make -C $(PATH_LIBFT) clean

fclean: clean
		rm -rf $(NAME)
		make -C $(PATH_LIBFT) fclean

re:	fclean all

.PHONY: all clean fclean re