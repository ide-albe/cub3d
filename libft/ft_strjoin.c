/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:33:52 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/11 17:05:26 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	cont1;
	size_t			strsize;

	cont1 = 0;
	strsize = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((strsize + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	while (cont1 < ft_strlen(s2))
	{
		str[cont1 + ft_strlen(s1)] = s2[cont1];
		cont1++;
	}
	str[cont1 + ft_strlen(s1)] = '\0';
	return (str);
}
