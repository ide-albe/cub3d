/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:45:08 by ide-albe          #+#    #+#             */
/*   Updated: 2023/11/21 21:18:31 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_cont
{
	int		i;
	int		j;
	int		fd;
	int		maplines;
}	t_cont;

typedef struct s_mat
{
	mlx_image_t	*img;
	char		xar;
}	t_mat;

typedef struct s_map
{
	char			**mat;
	int				*width;
	int				height;
	char			*so;
	char			*we;
	char			*ea;
	char			*nd;
	int				*f_color;
	int				*c_color;
}	t_map;

//MAP && MAT FUNCTIONS
int		linelength(char *argv);
int		maplines(char *argv);
int		ft_strlenon(char *str);
t_mat	**matriz(char *argv);
t_mat	**maplloc(char *argv);
t_map	mapdimesions(char *argv);
//FREE _MAT
void	ft_free_matz(t_mat **_matriz, int x);
//PRINT MAT (DELETE THIS AT END
void	print_matz(char *argv);

// void	mapisntvalid(void);

//FIND SO, WE, EA, ND, f_color, c_color
t_map	mat_to_arraid(char *argv);
void	find_so(t_map	map);


#endif
