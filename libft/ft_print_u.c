/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:18:07 by ide-albe          #+#    #+#             */
/*   Updated: 2023/01/20 13:04:09 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

int	ft_print_u(unsigned int n)
{
	if (n == 0)
	{
		return (write (1, "0", 1));
	}
	if (n >= 10)
	{
		ft_print_u(n / 10);
		ft_print_u(n % 10);
	}
	else
	{
		if (n <= 9)
		{
			ft_printchar(n + '0');
		}
	}
	return (ft_len(n));
}
