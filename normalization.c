/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:12:58 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:13:01 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
