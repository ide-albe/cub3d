/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:11:45 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/05 17:04:34 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			cont1;
	size_t			cont2;

	cont1 = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[cont1] != '\0' && cont1 < len)
	{
		cont2 = 0;
		while (haystack[cont1 + cont2] != '\0'
			&& haystack[cont1 + cont2] == needle[cont2]
			&& (cont1 + cont2) < len)
		{
			if (needle[cont2 + 1] == '\0')
			{
				return ((char *)&haystack[cont1]);
			}
			cont2++;
		}
		cont1++;
	}
	return (0);
}
