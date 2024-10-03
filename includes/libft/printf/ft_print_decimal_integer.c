/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_integer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:53:55 by lcluzan           #+#    #+#             */
/*   Updated: 2024/07/22 13:53:57 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal_integer(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (nb < 0)
	{
		count += ft_print_character('-');
		count += ft_print_decimal_integer(-nb);
	}
	else if (nb > 9)
	{
		count += ft_print_decimal_integer(nb / 10);
		count += ft_print_decimal_integer(nb % 10);
	}
	else
		count += ft_print_character(nb + '0');
	if (count < 0)
		return (-1);
	return (count);
}
