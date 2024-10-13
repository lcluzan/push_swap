/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:54:25 by lcluzan           #+#    #+#             */
/*   Updated: 2024/10/13 15:39:44 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Returns the highest index in the stack
static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/*Sorts a stack of 3 numbers using 2 or fewer moves based on their indexes.
Example:
Values:         0   9   2
Indexes:      [1] [3] [2]
Solution in 2 moves:
rra:         2   0   9   -> [2] [1] [3]
sa:         0   2   9   -> [1] [2] [3]*/
void	small_sort(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		rotate_a(stack);
	else if ((*stack)->next->index == highest)
		rev_rotate_a(stack);
	if ((*stack)->index > (*stack)->next->index)
		swap_a(stack);
}
