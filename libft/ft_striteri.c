/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:18:28 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/19 18:18:52 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	cont;

	cont = 0;
	if (s && f)
	{
		while (s[cont])
		{
			((f)(cont, &s[cont]));
			cont++;
		}	
	}
}
