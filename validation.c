/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:11:50 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:11:52 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_duplicates(int *stack_a, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			if (i != j)
				if (stack_a[i] == stack_a[j])
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	stack_a_is_correct(char *stack_a)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(stack_a);
	while (stack_a[i] == ' ')
		i++;
	if (stack_a[i] != '-' && stack_a[i] != '+'
		&& (stack_a[i] < '0' || stack_a[i] > '9'))
		return (1);
	if (stack_a[i] == '-' || stack_a[i] == '+')
		i++;
	if (i == len)
		return (1);
	while (i < len)
	{
		if (stack_a[i] < '0' || stack_a[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	error_output(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
