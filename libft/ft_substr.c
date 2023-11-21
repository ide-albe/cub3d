/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:22:41 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/26 17:32:24 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<string.h>
#include<stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	cont;
	size_t			memoria;
	size_t			left;
	char			*str;

	left = ft_strlen(s) - start;
	if (left >= len)
		memoria = len;
	if (left < len)
		memoria = left;
	if (start > ft_strlen(s))
		memoria = 0;
	str = (char *)malloc(sizeof(char) * (memoria + 1));
	cont = 0;
	if (!str)
		return (NULL);
	while (cont < memoria)
	{
		str[cont] = s[start + cont];
		cont++;
	}
	str[cont] = '\0';
	return (str);
}
