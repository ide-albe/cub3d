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



void	print_map(t_map map)
{
	int i = 0;
	while (map.mat[i])
	{
		printf("%s\n", map.mat[i]);
		i++;
	}
}

t_map	set_and_clean(t_map map)
{
	map = find_so(map);
	map = find_we(map);
	map = find_ea(map);
	map = find_no(map);
	map = find_f(map);
	map = find_c(map);
	format_check(map.so);
	format_check(map.we);
	format_check(map.ea);
	format_check(map.no);
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

int	mod_strncmp(char *str, char *word, int start)
{
	int i;

	i = 0;
	while (word[i])
	{
		if (str[start] != word[i])
			return (-1);
		start++;
		i++;
	}
	return (0);
}

void	format_check(char *str)
{
	int i;

	str = ft_strtrim(str, " ");
	i = ft_strlen(str) - 4;
	if ((mod_strncmp(str, ".png", i) == -1) && (mod_strncmp(str, ".cub", i) == -1))
	{
		printf("wrong format\n");
		exit (EXIT_FAILURE);
	}
}

int	map_lines_count(t_map	map)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	j = 0;
	while (map.mat[i])
	{
		x = ft_strlen(map.mat[i]);
		if (x > 1)
			j++;
		i++;
	}
	return (j);
}

t_mat	**map_to_mat(t_map map)
{
	int		i;
	int		x;
	int		z;
	int		k;
	t_mat	**_matz;

	i = 0;
	x = 0;
	_matz = (t_mat **)malloc((map_lines_count(map) + 2) * sizeof(t_mat *));
	while (map.mat[i])
	{
		z = 0;
		k = ft_strlen(map.mat[i]);
		if (k > 0)
		{ 
			while (map.mat[i][z])
			{
				_matz[x] = malloc((ft_strlen(map.mat[i] + 2)) * sizeof(char));
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
		if (map.mat[i][0] != '1' && map.mat[i][end - 1] != '1')
			map_error();
		(void)end;
		if ((is_all_ones(map.mat[i]) == 1))
			break ;
		i++;
	}
	return (i);
}

int	iscaracter(int c)
{
	if ((c >= 33 && c < 256))
	{
		return (1);
	}		
	return (0);
}
///////////////////CHECKEANDO QUE EL FINAL DEL MAPA ESTE VACIO
void	checking_after_map(t_map map)
{
	int	i;
	int	j;

	i = rest_walls(map) + 1;
	while (map.mat[i])
	{
		j = 0;
		while(map.mat[i][j])
		{
			if ((iscaracter(map.mat[i][j]) == 1))
				map_error();
			j++;
		}
		i++;
	}
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


/////CHECK IF THIS "S" IS FOR PLAYER START LOCATION!
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
