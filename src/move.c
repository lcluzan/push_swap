/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:53:53 by lcluzan           #+#    #+#             */
/*   Updated: 2024/10/13 15:27:46 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Reverse rotates both stacks A and B until one is in position.
The negative cost indicates that both positions are in the bottom half.
 As stacks are rotated, the cost increases until one reaches 0,
 indicating it has been rotated as far as possible and the top position
is correct*/
static void	do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a,
	int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rev_rotate_both(a, b);
	}
}

/*Rotates both stacks A and B until one is in position. The cost is positive,
indicating both positions are in the top half. The cost decreases with each
rotation, and when it reaches 0, the stack is fully rotated, and the top
position is correct*/
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_both(a, b);
	}
}

/*Rotates stack A to the correct position. Negative cost reverses the rotation,
while positive cost rotates it normally*/
static void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate_a(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rev_rotate_a(a);
			(*cost)++;
		}
	}
}

static void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate_b(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rev_rotate_b(b);
			(*cost)++;
		}
	}
}

/*Determines the best move to position the B stack element in stack A.
If the costs for moving stacks A and B are equal (both positive or negative),
they will be rotated or reversed together. Otherwise, they may be rotated
separately before pushing the top B element onto stack A*/
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	push_a(a, b);
}
