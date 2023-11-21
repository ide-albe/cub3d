/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:33:10 by ide-albe          #+#    #+#             */
/*   Updated: 2023/01/20 13:03:56 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = (num / 16);
		i++;
	}
	return (i);
}

int	ft_hexlowcase(unsigned long num)
{
	if (num == 0)
	{
		return (write (1, "0", 1));
	}
	if (num >= 16)
	{
		ft_hexlowcase(num / 16);
		ft_hexlowcase(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			ft_printchar(num + '0');
		}
		else
		{
			ft_printchar(num - 10 + 'a');
		}
	}
	return (ft_hexlen(num));
}

int	ft_hexuppercase(unsigned int num)
{
	if (num == 0)
	{
		return (write (1, "0", 1));
	}
	if (num >= 16)
	{
		ft_hexuppercase(num / 16);
		ft_hexuppercase(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			ft_printchar(num + '0');
		}
		else
		{
			ft_printchar(num - 10 + 'A');
		}
	}
	return (ft_hexlen(num));
}
