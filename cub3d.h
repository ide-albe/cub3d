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
// # include "MLX42/include/MLX42/MLX42.h"
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
	// mlx_image_t	*img;
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
	char			*no;
	int			*f_color;
	int			*c_color;
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
void	print_map(t_map map);

/////RANDOM FUNCTIONS TO CLASIFY LATER
int	is_path(char c);
int	is_str_num(char c);
// void	mapisntvalid(void);
int	find_str_in_str(char *str1, char *str2);
int	iscaracter(int c);
int	mod_strncmp(char *str, char *word, int start);

//CHECKING MAT ARGS

//FIND SO, WE, EA, ND, f_color, c_color
t_map	mat_to_map(char *argv);
t_map	find_so(t_map	map);
t_map	find_we(t_map	map);
t_map	find_ea(t_map	map);
t_map	find_no(t_map	map);
t_map	find_f(t_map	map);
t_map	find_c(t_map	map);
t_map	set_and_clean(t_map map);
int *color_values(char *str);
int	mod_uns_atoi(const char *str);

///MAP TO MAT
int	map_lines_count(t_map	map);
t_mat	**map_to_mat(t_map map);

//ERROR PRINTING
void	map_error(void);
void	wrong_value(void);
void	wrong_format(void);
void	args_notfound(void);
void	color_notfound(void);
// void	check_empty_map(t_map	map);
void player_not_found(void);
void multiple_players_found(void);

//MAP CHECK
int	is_all_ones(char *str);
int	found_s(char *str);
int first_wall(t_map map);
int	rest_walls(t_map map);
t_map	relocating_map(t_map map);
void	check_active_player(t_map map);
void	check_map_errors(t_map map);
void	checking_after_map(t_map map);
void	format_check(char *str);


#endif
