NAME	:= libftprintf.a

PATH_LIBFT	:= ./libft

LIBFT	:= ./libft/libft.a

CC	:= clang

CFLAGS	:= -Wall -Werror -Wextra

SRC	:=	ft_printf.c \
		ft_printf_csdiu%.c \
		ft_printf_pxX.c \
		ft_usgitoa.c \
		ft_hxitoa.c \

OBJ	:= $(SRC:.c=.o)

all:	$(NAME)

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