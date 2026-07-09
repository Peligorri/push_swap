/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:12:58 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:13:01 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_min_to_top(t_list **stack_a, int length,
		t_op_node **operations)
{
	int	min_pos;
	int	rotations;

	min_pos = find_min_position(*stack_a);
	if (min_pos <= length / 2)
	{
		while (min_pos-- > 0)
			ra(stack_a, operations);
	}
	else
	{
		rotations = length - min_pos;
		while (rotations-- > 0)
			rra(stack_a, operations);
	}
}

void	sort_four_five(t_list **stack_a, t_list **stack_b, int length,
		t_op_node **operations)
{
	int	current_len;

	current_len = length;
	while (current_len > 3)
	{
		rotate_min_to_top(stack_a, current_len, operations);
		pb(stack_a, stack_b, operations);
		current_len--;
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a, operations);
	while (*stack_b)
		pa(stack_a, stack_b, operations);
}

int	*copy_array(int *array, int length)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * length);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < length)
	{
		copy[i] = array[i];
		i++;
	}
	return (copy);
}

void	assign_ranks(int *array, int *copy, t_list *stack, int length)
{
	t_list	*current;
	int		i;
	int		j;
	int		rank;

	current = stack;
	i = 0;
	while (i < length)
	{
		rank = 0;
		j = 0;
		while (j < length)
		{
			if (copy[j] < current->content)
				rank++;
			j++;
		}
		array[i] = rank;
		current->content = rank;
		current = current->next;
		i++;
	}
}

int	normalize_values(int *array, t_list *stack, int length)
{
	int	*copy;

	copy = copy_array(array, length);
	if (!copy)
		return (0);
	assign_ranks(array, copy, stack, length);
	free(copy);
	return (1);
}
