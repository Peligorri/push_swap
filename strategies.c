/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:09:40 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:09:43 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rotate_a_to_position(t_list **stack_a, int pos,
		t_op_node **ops_head)
{
	int	length;

	length = stack_length(*stack_a);
	if (pos <= length / 2)
	{
		while (pos-- > 0)
		{
			ra(stack_a);
			record_operation(ops_head, "ra");
		}
	}
	else
	{
		pos = length - pos;
		while (pos-- > 0)
		{
			rra(stack_a);
			record_operation(ops_head, "rra");
		}
	}
}

static void	rotate_b_to_position(t_list **stack_b, int pos,
		t_op_node **ops_head)
{
	int	length;

	length = stack_length(*stack_b);
	if (pos <= length / 2)
	{
		while (pos-- > 0)
		{
			rb(stack_b);
			record_operation(ops_head, "rb");
		}
	}
	else
	{
		pos = length - pos;
		while (pos-- > 0)
		{
			rrb(stack_b);
			record_operation(ops_head, "rrb");
		}
	}
}

void	simple_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	min;
	int	pos;

	while (*stack_a)
	{
		min = find_min_value(*stack_a);
		pos = find_position(*stack_a, min);
		rotate_a_to_position(stack_a, pos, ops_head);
		pb(stack_a, stack_b);
		record_operation(ops_head, "pb");
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		record_operation(ops_head, "pa");
	}
}

void	medium_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	int	index;
	int	window;
	int	max;
	int	pos;

	index = 0;
	window = chunk_size(stack_length(*stack_a));
	while (*stack_a)
	{
		if ((*stack_a)->content <= index)
		{
			pb(stack_a, stack_b);
			record_operation(ops_head, "pb");
			if (*stack_b && (*stack_b)->next)
			{
				rb(stack_b);
				record_operation(ops_head, "rb");
			}
			index++;
		}
		else if ((*stack_a)->content <= index + window)
		{
			pb(stack_a, stack_b);
			record_operation(ops_head, "pb");
			index++;
		}
		else
		{
			ra(stack_a);
			record_operation(ops_head, "ra");
		}
	}
	while (*stack_b)
	{
		max = find_max_value(*stack_b);
		pos = find_position(*stack_b, max);
		rotate_b_to_position(stack_b, pos, ops_head);
		pa(stack_a, stack_b);
		record_operation(ops_head, "pa");
	}
}

void	adaptive_sort(t_list **stack_a, t_list **stack_b, int *array,
		int length, t_op_node **ops_head)
{
	double	disorder;

	disorder = calculate_disorder_percentage(array, length);
	if (disorder < 0.5)
		medium_sort(stack_a, stack_b, ops_head);
	else
		complex_sort(stack_a, stack_b, array, length, ops_head);
}
