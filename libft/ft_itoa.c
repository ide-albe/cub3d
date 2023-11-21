/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:42:11 by ide-albe          #+#    #+#             */
/*   Updated: 2022/10/18 18:22:21 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_numlim(int n, char *str)
{
	if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

static char	*ft_returnstr(int n, int len, char *str)
{
	if (n >= 0)
	{
		while (len >= 0)
		{
			str[len] = n % 10 + '0';
			n = n / 10;
			len--;
		}
	}
	else
	{
		str[0] = '-';
		n = n * -1;
		while (len > 0)
		{
			str[len] = n % 10 + '0';
			n = n / 10;
			len--;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n == -2147483648)
		ft_numlim(n, str);
	else
		ft_returnstr (n, len, str);
	return (str);
}
