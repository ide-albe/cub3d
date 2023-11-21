/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:52:57 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/11 17:14:16 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*str1;
	size_t	cont;

	str1 = (char *)s1;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	cont = 0;
	if (!ptr)
		return (NULL);
	while (str1[cont] != '\0')
	{
		ptr[cont] = str1[cont];
		cont++;
	}
	ptr[cont] = '\0';
	return (ptr);
}
