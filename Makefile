# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 17:51:18 by nmanzini          #+#    #+#              #
#    Updated: 2018/01/30 17:09:31 by nmanzini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = 	./main.c 				\
		./fractals.c			\
		./call_keys.c			\
		./call_keys_general.c	\
		./mlx_utils.c			\
		./colors_utils.c		\
		./colors_palette_1.c	\
		./colors_palette_2.c	\
		./mouse.c				\
		./data_init.c  			\

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

HEADER = -c -I fdf.h

W_FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -lmlx -framework Opengl -framework Appkit

MLX_FLAGS_MAC_AIR =  -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext $(MLX_FLAGS) 

all: $(NAME)

$(OBJ): %.o: %.c
		-@gcc -c  -I libft/ $< -o $@

$(LIBFT):
	-@ make -C libft 

$(NAME): $(LIBFT) $(OBJ)
	-@ gcc $(MLX_FLAGS)  $(OBJ) $(LIBFT) -o $(NAME)

clean:
	-@ /bin/rm -f $(OBJ)
	-@ make -C libft clean

fclean: clean
	-@ /bin/rm -f $(NAME)
	-@ make -C libft fclean

re: fclean all
