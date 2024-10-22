/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:53:45 by lcluzan           #+#    #+#             */
/*   Updated: 2024/10/22 15:22:28 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Checks if a stack is sorted.Returns 1 if sorted, 0 otherwise.
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

//Selects a sorting method based on the number of values
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		swap_a(stack_a);
	else if (stack_size == 3)
		small_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/*Validates input, initializes and sorts stacks a and b, assigns indexes,
then frees the stacks and exits*/
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	++av;
	if (ac < 2)
		return (0);
	if (ac == 2)
		av = ft_split(av[0], ' ');
	if (!av[0] || !is_correct_input(av))
	{
		if (ac == 2)
			free_split(av);
		exit_error(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = fill_stack_values(av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (ac == 2)
		free_split(av);
	return (0);
}
