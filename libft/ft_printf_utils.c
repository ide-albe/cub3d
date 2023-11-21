/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:40:26 by ide-albe          #+#    #+#             */
/*   Updated: 2023/01/20 13:04:12 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

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
