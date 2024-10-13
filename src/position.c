/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:54:00 by lcluzan           #+#    #+#             */
/*   Updated: 2024/10/13 15:32:03 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Assigns positions to stack elements from top to bottom in ascending order.
Example stack:
value:		 3	 0	 9	 1
index:		[3]	[1]	[4]	[2]
position:	<0>	<1>	<2>	<3>
Calculates the cost of moving elements to a position. For example,
in stack b, moving the first element to stack a costs 0. However,
moving the highest value, 9 (third position), costs 2 extra moves
to bring it to the top before pushing it to stack a*/
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

//Returns the index of the lowest element in the stack.
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/*Determines the best target position in stack A for an index from stack B.
It first checks if the B index can fit between elements in A by finding
an element in A with a greater index. If none exists, it assigns the
smallest index in A as the target.
Example 1:
B index: 3
A indexes: 9, 4, 2, 1, 0
target_pos starts at INT_MAX
9 > 3: target_pos = 9
4 > 3: target_pos = 4
2 < 3: no update
target_pos = 4 (closest index).*/
static int	get_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/*Assigns each element in stack A a target position for correct sorting
in stack B.
This position helps calculate the cost of moving elements to their target
in stack A*/
void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
