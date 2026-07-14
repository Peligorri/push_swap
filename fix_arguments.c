/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:10:21 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:10:23 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char **argv, int start)
{
	char	**split;
	int		total;
	int		i;
	int		j;

	total = 0;
	i = start;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
			j++;
		total += j;
		free_split(split);
		i++;
	}
	return (total);
}

static int	copy_split(char **dst, char **split, int index)
{
	int	i;

	i = 0;
	while (split[i])
	{
		dst[index] = ft_strdup(split[i]);
		index++;
		i++;
	}
	return (index);
}

char	**expand_arguments(char **argv, int start, int *len)
{
	char	**new_argv;
	char	**split;
	int		total;
	int		i;
	int		j;

	total = count_words(argv, start);
	if (total <= 0)
		return (NULL);
	new_argv = malloc(sizeof(char *) * (total + 1));
	if (!new_argv)
		return (NULL);
	i = start;
	j = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		j = copy_split(new_argv, split, j);
		free_split(split);
		i++;
	}
	new_argv[j] = NULL;
	*len = total;
	return (new_argv);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
