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

void	map_error(void)
{
	printf("Map error!\n");
	exit(EXIT_FAILURE);
}

void	args_notfound(void)
{
	printf("SO, WE, EA or NO not found!\n");
	exit(EXIT_FAILURE);
}

void	color_notfound(void)
{
	printf("F or C not found!\n");
	exit(EXIT_FAILURE);
}

void	wrong_value(void)
{
	printf("Wrong color values!\n");
	exit(EXIT_FAILURE);
}

void	wrong_format(void)
{
	printf("Wrong format! Try without spaces between!\n");
	exit(EXIT_FAILURE);
}

void multiple_players_found(void)
{
	printf("Multiple players found!\n");
	exit (EXIT_FAILURE);
}

void player_not_found(void)
{
	printf("Player not found!\n");
	exit (EXIT_FAILURE);
}