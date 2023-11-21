/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:56:08 by ide-albe          #+#    #+#             */
/*   Updated: 2023/05/10 15:41:46 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_findchar(char s, char c)
{
	if (s == c)
	{
		return (1);
	}
	return (0);
}

static int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	wordcount;
	int	end;

	i = 0;
	wordcount = 0;
	end = 1;
	while (s[i] != '\0')
	{
		if (ft_findchar(s[i], c) == 0 && end == 1)
		{
			wordcount++;
		}
		end = ft_findchar(s[i], c);
		i++;
	}
	return (wordcount);
}

static void	ft_free(char **strs, int x)
{
	while (x-- > 0)
		free(strs[x]);
	free(strs);
}

static int	ft_wordlen(const char *s, char c, int index)
{
	int	i;

	i = index + 1;
	while (ft_findchar(s[i], c) == 0 && s[i] != '\0')
	{
		i++;
	}
	return (i - index);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		x;
	char	**strs;

	i = 0;
	x = 0;
	strs = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	while (!strs)
		return (NULL);
	while (x < ft_wordcount(s, c))
	{
		while (s[i] == c)
			i++;
		strs[x] = ft_substr(s, i, ft_wordlen(s, c, i));
		if (!strs[x])
		{
			ft_free(strs, x);
			return (NULL);
		}
		i = i + ft_wordlen(s, c, i);
		x++;
	}
	strs[x] = 0;
	return (strs);
}
