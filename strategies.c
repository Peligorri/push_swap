/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:09:40 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/07 12:25:02 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	min;
	int	pos;

	while (*stack_a)
	{
		min = find_min_value(*stack_a);
		pos = find_position(*stack_a, min);
		rotate_a_to_position(stack_a, pos, ops_head);
		pb(stack_a, stack_b, ops_head);
	}
	while (*stack_b)
		pa(stack_a, stack_b, ops_head);
}

static void	extra_ms(t_list **stack_a, t_list **stack_b,
					t_op_node **ops_head)
{
	pb(stack_a, stack_b, ops_head);
	if (*stack_b && (*stack_b)->next)
		rb(stack_b, ops_head);
}

static void	fill_stack_b(t_list **stack_a, t_list **stack_b,
						t_op_node **ops_head)
{
	int	max;
	int	pos;

	while (*stack_b)
	{
		max = find_max_value(*stack_b);
		pos = find_position(*stack_b, max);
		rotate_b_to_position(stack_b, pos, ops_head);
		pa(stack_a, stack_b, ops_head);
	}
}

void	medium_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	window;
	int	index;

	index = 0;
	window = chunk_size(stack_length(*stack_a));
	while (*stack_a)
	{
		if ((*stack_a)->content <= index)
		{
			extra_ms(stack_a, stack_b, ops_head);
			index++;
		}
		else if ((*stack_a)->content <= index + window)
		{
			pb(stack_a, stack_b, ops_head);
			index++;
		}
		else
			ra(stack_a, ops_head);
	}
	fill_stack_b(stack_a, stack_b, ops_head);
}

void	adaptive_sort(t_list **stack_a, t_list **stack_b, int *array,
		t_op_node **ops_head)
{
	double	disorder;
	int		stack_len;

	stack_len = stack_length(*stack_a);
	disorder = calculate_disorder_percentage(array, stack_len);
	if (disorder < 0.5)
		medium_sort(stack_a, stack_b, ops_head);
	else
		complex_sort(stack_a, stack_b, array, ops_head);
}
