/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:20:09 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/26 17:48:24 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	caracter;

	caracter = c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == caracter)
			return (&str[i]);
		i++;
	}
	if (str[i] == caracter)
		return (&str[i]);
	return (NULL);
}
