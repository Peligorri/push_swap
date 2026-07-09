/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_position(t_list *stack)
{
	int	max;
	int	max_pos;
	int	pos;

	max = stack->content;
	max_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

static void	rotate_b_to_max(t_list **stack_b, t_op_node **ops_head)
{
	int	length;
	int	pos;

	length = stack_length(*stack_b);
	pos = find_max_position(*stack_b);
	if (pos <= length / 2)
	{
		while (pos-- > 0)
			rb(stack_b, ops_head);
	}
	else
	{
		pos = length - pos;
		while (pos-- > 0)
			rrb(stack_b, ops_head);
	}
}

static void	pass_sb(t_list **stack_a, t_list **stack_b, t_op_node **ops_head)
{
	while (*stack_b)
	{
		rotate_b_to_max(stack_b, ops_head);
		pa(stack_a, stack_b, ops_head);
	}
}

static void	extra_complex_sort(t_list **stack_a, t_list **stack_b,
		t_op_node **ops_head)
{
	pb(stack_a, stack_b, ops_head);
	if (*stack_b && (*stack_b)->next)
		rb(stack_b, ops_head);
}

void	complex_sort(t_list **stack_a, t_list **stack_b,
		int *array, t_op_node **ops_head)
{
	int	window;
	int	index;

	index = 0;
	if (!stack_a || !stack_b || !array || stack_length(*stack_a) < 2)
		return ;
	window = (sqrt_approx(stack_length(*stack_a)) * 13) / 10;
	if (window < 1)
		window = 1;
	while (*stack_a)
	{
		if ((*stack_a)->content <= index)
		{
			extra_complex_sort(stack_a, stack_b, ops_head);
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
	pass_sb(stack_a, stack_b, ops_head);
}
