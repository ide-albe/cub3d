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
	printf("map.height: %i\n", map.height);
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
	printf("%s\n", map.mat[0]);
	return (map);
}

void	find_so(t_map	map)
{
	int	i;
	int	j;
	char	**strings;

	i = 0;
	j = 0;
	while (map.mat[i])
	{
		if (ft_strncmp(map.mat[i], "SO", 2) == 0)
		{
			
			printf("map.so: %s", map.so);
			break ;
		}
		i++;
	}
}
