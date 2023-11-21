/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-albe <ide-albe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:40:35 by ide-albe          #+#    #+#             */
/*   Updated: 2023/01/20 13:08:04 by ide-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(char format, va_list args)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_printpointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_u(va_arg(args, unsigned int));
	else if (format == 'x')
		print_len += ft_hexlowcase(va_arg(args, unsigned int));
	else if (format == 'X')
		print_len += ft_hexuppercase(va_arg(args, unsigned int));
	else if (format == '%')
		print_len += ft_printchar('%');
	return (print_len);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	args;
	int		print_len;

	va_start(args, str);
	i = 0;
	print_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			print_len += ft_format(str[++i], args);
		else
			print_len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

// int	main(void)
// {
// 	int i;
// 	int j;

// 	i = ft_printf("%u\n", -20);
// 	j = printf("%u\n", -20);
// 	printf("Mio : %i\nOrg : %i", i, j);
// }
