/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_updates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	total_operations(t_op_node *ops)
{
	int	count;

	count = 0;
	while (ops)
	{
		count++;
		ops = ops->next;
	}
	return (count);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}

void	ft_array_to_list(int *array_a, t_list **stack_a, int length)
{
	t_list	*new_node;
	t_list	*actual_node;
	int		i;

	i = 0;
	while (i < length)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return ;
		new_node->content = array_a[i];
		new_node->next = NULL;
		if (!*stack_a)
			*stack_a = new_node;
		else
		{
			actual_node = *stack_a;
			while (actual_node->next)
				actual_node = actual_node->next;
			actual_node->next = new_node;
		}
		i++;
	}
}
