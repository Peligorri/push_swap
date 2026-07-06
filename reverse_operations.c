/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:08:39 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:08:41 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
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
}

void	rb(t_list **stack_b)
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
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

double	calculate_disorder_percentage(int *array, int length)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	if (length < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			total_pairs++;
			if (array[i] > array[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}
