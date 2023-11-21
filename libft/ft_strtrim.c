/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:57:26 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/26 17:32:24 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_tofind(char c, char const *set)
{
	size_t	cont;

	cont = 0;
	while (set[cont])
	{
		if (set[cont] == c)
		{
			return (1);
		}
		cont++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_tofind(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > 0 && ft_tofind(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, (end - start)));
}
