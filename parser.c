/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:09:40 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:09:43 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	is_known_flag(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(arg, "--bench") == 0)
		return (1);
	return (0);
}

static void	apply_flag(t_flags *flags, char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		flags->strategy = SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		flags->strategy = MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		flags->strategy = COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		flags->strategy = ADAPTIVE;
	else if (ft_strcmp(arg, "--bench") == 0)
		flags->bench = 1;
}

t_flags	parse_flags(int argc, char **argv, int *start_index)
{
	t_flags	flags;
	int		i;

	flags.strategy = ADAPTIVE;
	flags.bench = 0;
	i = 1;
	while (i < argc && is_known_flag(argv[i]))
	{
		apply_flag(&flags, argv[i]);
		i++;
	}
	*start_index = i;
	return (flags);
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
