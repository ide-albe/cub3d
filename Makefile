# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:42:39 by ide-albe          #+#    #+#              #
#    Updated: 2023/11/21 19:32:45 by ide-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc -g
NAME		= cub3d
# MLX_LIB     = MLX42/libmlx42.a
LIBFTA		= libft/libft.a
CFLAGS		= -Wall -Wextra -Werror
# LIBRARIES	= -lglfw -L "/Users/ide-albe/.brew/opt/glfw/lib" -lm -framework OpenGL
SRC			= main.c map_utils_1.c map_utils_2.c warnings.c utils.c find_textures.c
OBJ			= $(SRC:.c=.o)

all:		libft mlx $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

# //AÑADIR "mlx" AQUI ABAJO
$(NAME):	mlx libft $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) -o $(NAME)
# //AÑADIR $(LIBRARIES) $(MLX_LIB) AQUI ARRIBA

libft:
	make -C libft
# mlx:
# 	make -C MLX42
clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean:	
	rm -rf $(NAME)
	make -C libft fclean

re:

.PHONY:		mlx libft cd all clean fclean re