/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:54:18 by lcluzan           #+#    #+#             */
/*   Updated: 2024/10/13 15:38:30 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Moves the top stack element to the bottom
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

// Moves the top element of stack a to the bottom and prints "ra"
void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

//Moves the top element of stack b to the bottom and prints "rb"
void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/*Moves the top elements of stacks a and b to their bottoms.
Prints "rr" to standard output*/
void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
