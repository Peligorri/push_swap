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

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	process_bit(t_list **stack_a, t_list **stack_b,
		t_op_node **ops_head, int bit)
{
	int	size;

	size = stack_length(*stack_a);
	while (size--)
	{
		if ((((*stack_a)->content >> bit) & 1) == 1)
			ra(stack_a, ops_head);
		else
			pb(stack_a, stack_b, ops_head);
	}
	while (*stack_b)
		pa(stack_a, stack_b, ops_head);
}

void	complex_sort(t_list **stack_a, t_list **stack_b,
		int *array, t_op_node **ops_head)
{
	int	max_bits;
	int	bit;

	(void)array;
	if (!stack_a || !stack_b || stack_length(*stack_a) < 2)
		return ;
	max_bits = get_max_bits(stack_length(*stack_a));
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(stack_a, stack_b, ops_head, bit);
		bit++;
	}
}
