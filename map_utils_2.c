/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:17:20 by ide-albe          #+#    #+#             */
/*   Updated: 2023/11/21 21:41:18 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	mat_to_arraid(char *argv)
{
	int		i;
	int		j;
	t_map	map;
	t_mat 	**_matriz;

	i = 0;
	j = 0;
	map = mapdimesions(argv);
	_matriz = matriz(argv);
	map.mat = (char **)malloc(map.height * sizeof(char *));
	while (_matriz[i])
	{
		j = 0;
		map.mat[i] = (char *)malloc((map.width[i] + 1) * sizeof(char));
		while (_matriz[i][j].xar)
		{
			map.mat[i][j] = _matriz[i][j].xar;
			j++;
		}
		map.mat[i][j] = '\0';
		i++;
	}
	map.mat[i] = NULL;
	return (map);
}

t_map	find_so(t_map	map)
{
	int i;
	int x;
	int j;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "SO");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			while ((is_path(map.mat[i][j]) == 1))
				j++;
			map.so = ft_substr(map.mat[i], x, j);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		args_notfound();
	return (map);
}

t_map	find_we(t_map	map)
{
	int i;
	int x;
	int j;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "WE");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			while ((is_path(map.mat[i][j]) == 1))
				j++;
			map.we = ft_substr(map.mat[i], x, j);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		args_notfound();
	return (map);
}

t_map	find_ea(t_map	map)
{
	int i;
	int x;
	int j;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "EA");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			while ((is_path(map.mat[i][j]) == 1))
				j++;
			map.ea = ft_substr(map.mat[i], x, j);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		args_notfound();
	return (map);
}

t_map	find_no(t_map	map)
{
	int i;
	int x;
	int j;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "NO");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			while ((is_path(map.mat[i][j]) == 1))
				j++;
			map.no = ft_substr(map.mat[i], x, j);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		args_notfound();
	return (map);
}

t_map	find_f(t_map	map)
{
	int i;
	int x;
	int j;
	char	*f_c;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "F");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			j++;
			while ((is_str_num(map.mat[i][j]) == 1))
			{
				j++;
				if (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
					wrong_format();
			}
			f_c = ft_substr(map.mat[i], x, j);
			map.f_color = color_values(f_c);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		color_notfound();
	return (map);
}

t_map	find_c(t_map	map)
{
	int i;
	int x;
	int j;
	char	*f_c;

	i = 0;
	while (map.mat[i])
	{
		x = find_str_in_str(map.mat[i], "C");
		if (x > 0)
		{
			x += 1;
			j = x;
			while (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
				j++;
			while ((is_str_num(map.mat[i][j]) == 1))
			{
				j++;
				if (map.mat[i][j] == ' ' || map.mat[i][j] == '	')
					wrong_format();
			}
			f_c = ft_substr(map.mat[i], x, j);
			map.c_color = color_values(f_c);
			ft_bzero(map.mat[i], ft_strlen(map.mat[i]));
			map.mat[i][0] = '\0';
			break ;
		}
		i++;
	}
	if (x == 0)
		color_notfound();
	return (map);
}

int *color_values(char *str)
{
	int 	i;
	int		*_color;
	char 	**nums;

	i = 0;
	nums = ft_split(str, ',');
	_color = (int *)malloc(4 * sizeof(int));
	while (nums[i])
	{

		_color[i] = mod_uns_atoi(nums[i]);
		if (i >= 3)
			wrong_value();
		i++;
	}
	if (i <= 2)
		wrong_value();
	return (_color);
}

void	print_map(t_map map)
{
	int i = 0;
	while (map.mat[i])
	{
		printf("%s\n", map.mat[i]);
		i++;
	}
}

void	check_empty_map(t_map	map)
{
	int i;
	int x;

	i = 0;
	if (map.mat[0] == NULL)
		map_error();
	while (map.mat[i])
	{
		x = ft_strlen(map.mat[i]);
		if (map.mat[i + 1] == NULL)
			if (x < 1)
				map_error();
		i++;
	}
	(void)map;
}

t_map	set_and_clean(t_map map)
{
	map = find_so(map);
	map = find_we(map);
	map = find_ea(map);
	map = find_no(map);
	map = find_f(map);
	map = find_c(map);
	map.so = ft_strtrim(map.so, " ");
	map.we = ft_strtrim(map.we, " ");
	map.ea = ft_strtrim(map.ea, " ");
	map.no = ft_strtrim(map.no, " ");
	// printf("map.so: %s\n", map.so);
	// printf("map.we: %s\n", map.we);
	// printf("map.ea: %s\n", map.ea);
	// printf("map.no: %s\n", map.no);
	// printf("map.f_color: %d\n", map.f_color[0]);
	// printf("map.f_color: %d\n", map.f_color[1]);
	// printf("map.f_color: %d\n", map.f_color[2]);
	// printf("map.c_color: %d\n", map.c_color[0]);
	// printf("map.c_color: %d\n", map.c_color[1]);
	// printf("map.c_color: %d\n", map.c_color[2]);
	return (map);
}

int	map_lines_count(t_map	map)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	while (map.mat[i])
	{
		x = ft_strlen(map.mat[i]);
		if (x > 1)
			j++;
		i++;
	}
	return (j);
}


///ESTA FUNCION TENDRIA QUE ARREGLARLA DESPUES DE CHECKEAR YA SI EL MAPA ES VALIDO
//POR AHORA LA DEJO ASI, Y TENDRE Q ADAPTARLA A LO Q ME DEVUELVA map.mat
t_mat	**map_to_mat(t_map map)
{
	int		i;
	int		x;
	int		z;
	int		k;
	t_mat	**_matz;

	i = 0;
	x = 0;
	_matz = (t_mat **)malloc((map_lines_count(map) + 1) * sizeof(t_mat *));
	while (map.mat[i])
	{
		z = 0;
		k = ft_strlen(map.mat[i]);
		if (k > 0)
		{ 
			while (map.mat[i][z])
			{
				_matz[x] = malloc((ft_strlen(map.mat[i] + 1)) * sizeof(char));
				_matz[x][z].xar = map.mat[i][z];
				printf("%c", _matz[x][z].xar);
				z++;
			}
			_matz[x][z].xar = '\0';
			printf("\n");
		}
		x++;
		i++;
	}
	_matz[x] = NULL;
	return(_matz);
}

int first_wall(t_map map)
{
	///CHECKS FIRST WALLS IS ALL ONEs, AND RETURN A INT WHERE TO FIND THIS WALL IN THE MAT
	int i;
	int x;
	int j;
	
	i = 0;
	while (map.mat[i])
	{
		x = ft_strlen(map.mat[i]);
		if (x > 0)
			break ;
		i++;
	}
	j = 0;
	while (map.mat[i][j])
	{
		if (map.mat[i][j] != '1' && map.mat[i][j] != 32)
			map_error();
		j++;
	}
	return (i);
}

int	is_all_ones(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != 32 && str[i] != '	')
			return (-1);
		i++;
	}
	return (1);
}

int	found_s(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'S')
			return (1);
		i++;
	}
	return (0);
}

int	rest_walls(t_map map)
{
	int i;
	int end;

	i = first_wall(map) + 1;
	while (map.mat[i])
	{
		end = ft_strlen(map.mat[i]);
		if ((map.mat[i][0] == '\0'))
			map_error();
		if (map.mat[i][0] != '1' || map.mat[i][end - 1] != '1')
			map_error();
		if ((is_all_ones(map.mat[i]) == 1))
			break ;
		i++;
	}
	return (i);
}

t_map	relocating_map(t_map map)
{
	int i;
	int start;
	int end;
	int linelength;
	t_map	relocated_map;

	i = 0;
	start = first_wall(map);
	end = rest_walls(map);
	relocated_map.mat = (char **)malloc(end * sizeof(char *));
	while (map.mat[start] && start <= end)
	{
		linelength = (ft_strlen(map.mat[start]));
		relocated_map.mat[i] = (char *)malloc((linelength + 1) * sizeof(char));
		relocated_map.mat[i] = map.mat[start];
		i++;
		start++;
	}
	return (relocated_map);
}

void	check_active_player(t_map map)
{
	int i;
	int j;
	int start;
	int end;

	i = 0;
	start = first_wall(map);
	end = rest_walls(map);
	while (map.mat[start] && start <= end)
	{
		j = 0;
		while (map.mat[start][j])
		{
			if (map.mat[start][j] == 'S')
				i++;
			j++;
		}
		start++;
	}
	if (i == 0)
		player_not_found();
	if (i != 1)
		multiple_players_found();
}
