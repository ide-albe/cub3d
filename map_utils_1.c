/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:17:20 by ide-albe          #+#    #+#             */
/*   Updated: 2023/11/21 21:02:57 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mat	**maplloc(char *argv)
{
	int		i;
	t_mat	**_matriz;
	t_map	map_size;

	i = 0;
	map_size = mapdimesions(argv);
	_matriz = (t_mat **)malloc((map_size.height + 1) * sizeof(t_mat *));
	while (i < map_size.height)
	{
		_matriz[i] = (t_mat *)malloc((map_size.width[i] + 1) * sizeof(t_mat));
		i++;
	}
	_matriz[i] = NULL;
	free(map_size.width);
	return (_matriz);
}

t_map	mapdimesions(char *argv)
{
	int		i;
	t_map	map_size;
	int		fd;
	char	*line;

	i = 0;
	map_size.height = maplines(argv);
	map_size.width = (int *)malloc(map_size.height * sizeof(int));
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (i < map_size.height)
	{
		map_size.width[i] = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (map_size);
}

int	maplines(char *argv)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		args_notfound();
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	return (i);
}

int	ft_strlenon(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

t_mat	**matriz(char *argv)
{
	int		i;
	int		j;
	char	*line;
	t_mat	**_matriz;
	t_map	map;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	map = mapdimesions(argv);
	_matriz = maplloc(argv);
	line = get_next_line(fd);
	while (i < map.height)
	{
		j = 0;
		while (j < ft_strlenon(line))
		{
			_matriz[i][j].xar = line[j];
			j++;
		}
		_matriz[i][j].xar = '\0';
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	free(map.width);
	return (_matriz);
}

void	ft_free_matz(t_mat **_matriz, int x)
{
	while (_matriz[x++])
		free(_matriz[x]);
	free(_matriz);
}
