/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:12:58 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:13:01 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_two(t_list **stack_a, t_op_node **operations)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		sa(stack_a);
		record_operation(operations, "sa");
	}
}

void	sort_three(t_list **stack_a, t_op_node **operations)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && second < third && first < third)
	{
		sa(stack_a);
		record_operation(operations, "sa");
	}
	else if (first > second && second > third)
	{
		sa(stack_a);
		record_operation(operations, "sa");
		rra(stack_a);
		record_operation(operations, "rra");
	}
	else if (first > second && second < third && first > third)
	{
		ra(stack_a);
		record_operation(operations, "ra");
	}
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		record_operation(operations, "sa");
		ra(stack_a);
		record_operation(operations, "ra");
	}
	else if (first < second && second > third && first > third)
	{
		rra(stack_a);
		record_operation(operations, "rra");
	}
}

int	find_min_position(t_list *stack)
{
	int	min;
	int	min_pos;
	int	current_pos;

	min = stack->content;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_pos);
}
