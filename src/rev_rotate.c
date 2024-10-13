/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:54:12 by lcluzan           #+#    #+#             */
/*   Updated: 2024/10/13 15:35:46 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Moves the bottom stack element to the top
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

//Moves the bottom element of stack a to the top and prints "rra"
void	rev_rotate_a(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

//Moves the bottom element of stack b to the top and prints "rrb"
void	rev_rotate_b(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/*Moves the bottom element of stacks A and B to the top.
Prints "rrr" to standard output*/
void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
