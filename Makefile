# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:56:30 by ide-albe          #+#    #+#              #
#    Updated: 2023/04/24 18:19:26 by ide-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc -g
NAME		= cub3d
MLX_LIB     = MLX42/build/libmlx42.a
LIBFTA		= libft/libft.a
CFLAGS		= -Wall -Wextra -Werror
LIBRARIES	= -lglfw -lGL -ldl -pthread -lm
SRC			= main.c find_textures.c map_utils_1.c map_utils_2.c utils.c warnings.c
OBJ			= $(SRC:.c=.o)
FLAGS_MLX_LINUX = -Iinclude -ldl -lglfw -pthread -lm

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(LIBFTA) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_LIB) $(LIBFTA) $(FLAGS_MLX_LINUX)

$(LIBFTA):
	make -C libft

mlx:
	make -C MLX42/build
clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean:	clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY:		mlx libft cd all clean fclean re