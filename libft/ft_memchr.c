/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:57:01 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/04 20:11:37 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	caracter;
	unsigned char	*str;
	size_t			cont;

	caracter = c;
	str = (unsigned char *)s;
	cont = 0;
	while (cont < n)
	{
		if (str[cont] == caracter)
		{
			return (&str[cont]);
		}
		cont++;
	}
	return (0);
}
