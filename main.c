/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:17:20 by ide-albe          #+#    #+#             */
/*   Updated: 2023/11/21 21:20:44 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//PRINTING MATZ///////////////////////////////////////////////////////////////////
void	print_matz(char *argv)
{
	t_mat **_matriz;
	t_map map = mapdimesions(argv);

	int i = 0;
	int j = 0;
	int x = 0;
	_matriz = matriz(argv);
	while (i < map.height)
	{
		j = 0;
		x = map.width[i];
		while (j < x)
		{
			printf("%c", _matriz[i][j].xar);
			j++;
		}
		printf("\n");
		map.width[i]++;
		i++;
	}
	ft_free_matz(_matriz, map.height);
}
//////////////////////////////////////////////////////////////////////////////////

void	check_map_errors(t_map map)
{
	///HACER NUEVA FUNCION CHECK_EMPTY_MAP
	// check_empty_map(map);
	first_wall(map);
	// check_active_player(map);
	rest_walls(map);
	checking_after_map(map);
}

int	main(int argc, char **argv)
{
	(void)argc;
	// t_mat **_matriz;
	t_map	map;
	map = mat_to_arraid(argv[1]);
	map = set_and_clean(map);
	check_map_errors(map);
	map = relocating_map(map);
	///MAP TO MAT FUNCIONA AVECES
	// _matriz = map_to_mat(map);
	// (void)_matriz;
	// system("leaks -q cub3d");

}
