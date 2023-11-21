/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:43:54 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/11 16:05:00 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	cont;

	cont = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize != 0)
	{
		while (src[cont] != '\0' && cont < (dstsize - 1))
		{
		dst[cont] = src[cont];
		cont++;
		}
	}
	dst[cont] = '\0';
	return (ft_strlen(src));
}
