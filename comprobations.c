/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprobations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:11:50 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:11:52 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_symbol(const char *str, int *neg)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		*neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

int	validate_integer_range(const char *str)
{
	long	num;
	int		i;
	int		neg;
	long	limit;

	if (!str)
		return (0);
	neg = 0;
	i = search_symbol(str, &neg);
	if (str[i] < '0' || str[i] > '9')
		return (0);
	num = 0;
	limit = 2147483647 + neg;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if (num > limit)
			return (0);
		i++;
	}
	return (1);
}

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

int	*transform_argv(char **argv, int *length)
{
	int	*stack_a;
	int	i;
	int	j;

	if (!argv || (*length) < 0)
		return (0);
	i = 0;
	j = 0;
	if (*length < 1)
		return (0);
	stack_a = malloc(sizeof(int) * (*length));
	if (!stack_a)
		return (0);
	while (j < (*length))
	{
		if (stack_a_is_correct(argv[i]) == 1)
			return (free (stack_a), NULL);
		if (validate_integer_range(argv[i]) == 0)
			return (free (stack_a), NULL);
		stack_a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (stack_a);
}
