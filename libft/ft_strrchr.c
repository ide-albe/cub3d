/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:40:20 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/04 18:33:41 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	caracter;

	caracter = c;
	i = ft_strlen(s);
	if (caracter == 0)
	{
		return ((char *)s + i);
	}
	while (i >= 0)
	{
		if (s[i] == caracter)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (NULL);
}
