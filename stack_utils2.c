/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_value(t_list *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	chunk_size(int length)
{
	int	size;

	size = 1;
	while (size * size < length)
		size++;
	if (length > 100)
		size = size * 2;
	else
		size = size + (size / 2);
	return (size);
}

int	sqrt_approx(int n)
{
	int	result;

	result = 1;
	while (result * result < n)
		result++;
	return (result);
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
