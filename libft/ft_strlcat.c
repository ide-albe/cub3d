/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:11:23 by ide-albe          #+#    #+#             */
/*   Updated: 2022/09/27 18:31:34 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	z;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	z = 0;
	while (dst[x] != '\0')
		x++;
	while (src[z] != '\0')
		z++;
	if (dstsize <= x)
		z = z + dstsize;
	else
		z = z + x;
	while (src[i] && (x + 1) < dstsize)
	{
		dst[x] = src[i];
		i++;
		x++;
	}
	dst[x] = '\0';
	return (z);
}
