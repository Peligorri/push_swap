/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:08:39 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:08:41 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, t_op_node **operations)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first_node = *stack_a;
	last_node = *stack_a;
	while (last_node->next)
		last_node = last_node->next;
	*stack_a = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	record_operation(operations, "ra");
}

void	rb(t_list **stack_b, t_op_node **operations)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first_node = *stack_b;
	last_node = *stack_b;
	while (last_node->next)
		last_node = last_node->next;
	*stack_b = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	record_operation(operations, "rb");
}

void	rr(t_list **stack_a, t_list **stack_b, t_op_node **operations)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first_node = *stack_a;
	last_node = *stack_a;
	while (last_node->next)
		last_node = last_node->next;
	*stack_a = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first_node = *stack_b;
	last_node = *stack_b;
	while (last_node->next)
		last_node = last_node->next;
	*stack_b = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	record_operation(operations, "rr");
}

void	rotate_a_to_position(t_list **stack_a, int pos,
		t_op_node **ops_head)
{
	int	length;

	length = stack_length(*stack_a);
	if (pos <= length / 2)
	{
		while (pos-- > 0)
			ra(stack_a, ops_head);
	}
	else
	{
		pos = length - pos;
		while (pos-- > 0)
			rra(stack_a, ops_head);
	}
}

void	rotate_b_to_position(t_list **stack_b, int pos,
		t_op_node **ops_head)
{
	int	length;

	length = stack_length(*stack_b);
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
