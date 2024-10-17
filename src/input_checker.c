/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:53:41 by lcluzan           #+#    #+#             */
/*   Updated: 2024/10/17 11:36:16 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Checks if the argument is a valid number (+1, 1, -1).
Return: 1 if valid, 0 otherwise*/
static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (!av[0])
		return (0);
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/*Checks if the argument is INT_MIN or INT_MAX.
Return: 1 if INT_MIN or INT_MAX, 0 otherwise*/
static int	arg_is_int(char *av)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	if (!av[0])
		return (0);
	if (is_sign(av[i]) && av[i + 1] != '\0')
	{
		if (av[i] == '-')
			sign = -1;
		i++;
	}
	while (av[i] && is_digit(av[i]))
	{
		num = num * 10 + (av[i] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && num > -(long long)INT_MIN))
			return (0);
		i++;
	}
	return (av[i] == '\0');
}

/*Checks for duplicate numbers in the list.
Returns: 1 if duplicates exist, 0 otherwise*/
static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*Checks if the argument is a zero (handles 0, +0, -0, 000, etc.).
 Returns: 1 if zero, 0 otherwise*/
static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/*Verifies if all arguments are unique numbers.
Return: 1 if valid, 0 otherwise*/
int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		if (!arg_is_int(av[i]))
			return (0);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	return (1);
}
