/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:55:11 by lcluzan           #+#    #+#             */
/*   Updated: 2024/07/22 17:01:26 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_print_character(char c);
int	ft_print_str(char *str);
int	ft_print_unsigned_decimal(unsigned int nb);
int	ft_print_decimal_integer(int nb);
int	ft_print_ptr(void *arg);
int	ft_print_hex(unsigned int nb, int type);
int	ft_base16(unsigned long nb, char *alpha);
int	ft_check_type(const char type, va_list args);
int	ft_printf(const char *str, ...);

#endif
