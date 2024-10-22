/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:53:36 by lcluzan           #+#    #+#             */
/*   Updated: 2024/10/22 14:16:19 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Fills stack_a with values. Exits with an error if values are out of range*/
t_stack	*fill_stack_values(char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

/* Assigns an index to each value in stack a, allowing comparison using indexes
 instead of values, which may not be adjacent.
     ex. values:   -3   0   9   2
         indexes:  [1] [2] [4] [3]
Indexes range from stack_size (largest) to 1 (smallest)*/
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*bigger;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		bigger = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				bigger = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (bigger != NULL)
			bigger->index = stack_size;
	}
}
