/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:55:15 by lcluzan           #+#    #+#             */
/*   Updated: 2024/10/22 15:16:15 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

t_stack		*fill_stack_values(char **av);
void		assign_index(t_stack *stack_a, int ac);

int			is_sorted(t_stack *stack);
void		small_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_both(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_both(t_stack **stack_a, t_stack **stack_b);
void		rev_rotate_a(t_stack **stack_a);
void		rev_rotate_b(t_stack **stack_b);
void		rev_rotate_both(t_stack **stack_a, t_stack **stack_b);

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);

void		exit_error(t_stack **stack_a, t_stack **stack_b);

int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

char		**ft_split(char const *s, char c);
void		free_split(char **str);

#endif
