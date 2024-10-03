/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:26:45 by lcluzan           #+#    #+#             */
/*   Updated: 2024/07/22 16:58:45 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start (args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_check_type(str[i], args);
		}
		else
			count += ft_print_character(str[i]);
		i++;
	}
	va_end (args);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_check_type(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += (char)ft_print_character(va_arg(args, int));
	if (type == 's')
		count += ft_print_str(va_arg(args, char *));
	if (type == 'd' || type == 'i')
		count += ft_print_decimal_integer(va_arg(args, int));
	if (type == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	if (type == 'u')
		count += ft_print_unsigned_decimal(va_arg(args, unsigned int));
	if (type == 'X' || type == 'x')
		count += (char)ft_print_hex(va_arg(args, int), type);
	if (type == '%')
		return (write(1, "%", 1));
	return (count);
}
