/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:57:17 by lcluzan           #+#    #+#             */
/*   Updated: 2024/07/22 17:27:18 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_print_decimal_integer(nb / 10);
		count += ft_print_decimal_integer(nb % 10);
	}
	else if (nb < 10)
		count += ft_print_character(nb + '0');
	return (count);
}
