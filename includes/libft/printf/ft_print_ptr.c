/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:45:48 by lcluzan           #+#    #+#             */
/*   Updated: 2024/07/22 17:22:06 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *arg)
{
	int				count;
	char			*alpha;
	unsigned long	arg2;

	if (!arg)
		return (ft_print_str("(nil)"));
	arg2 = (unsigned long)arg;
	alpha = "0123456789abcdef";
	count = 0;
	count += ft_print_str("0x");
	count += ft_base16(arg2, alpha);
	return (count);
}
