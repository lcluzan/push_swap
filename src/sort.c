/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:54:33 by lcluzan           #+#    #+#             */
/*   Updated: 2024/10/13 15:41:45 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Moves all elements from stack a to stack b, excluding the last three,
pushing smaller values first for better sorting efficiency*/
static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			push_b(stack_a, stack_b);
			pushed++;
		}
		else
			rotate_a(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		push_b(stack_a, stack_b);
		pushed++;
	}
}

/*After sorting the stack, move the lowest value to the top.
If it's in the bottom half, reverse rotate; otherwise,
rotate to position it at the top*/
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rev_rotate_a(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate_a(stack_a);
			lowest_pos--;
		}
	}
}

/*Sorts a stack with more than 3 elements by:
Pushing all but 3 numbers to stack B.
 Sorting the remaining 3 in stack A.
Finding the most efficient move.
Shifting elements to order stack A*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	small_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
