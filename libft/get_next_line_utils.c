/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:36:18 by ide-albe          #+#    #+#             */
/*   Updated: 2023/03/08 18:50:24 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlengnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchrgnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoingnl(char *stash, char *buf)
{
	char			*str;

	if (!stash)
	{
		stash = malloc(1 * sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (!stash[0] && !buf[0])
	{
		free (stash);
		return (NULL);
	}
	str = malloc((ft_strlen(stash) + ft_strlen(buf) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_strjoinnomallocgnl(stash, buf, str);
	free(stash);
	return (str);
}

char	*ft_strjoinnomallocgnl(char *stash, char *buf, char *str)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	while (buf[j])
	{
		str[i + j] = buf[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
