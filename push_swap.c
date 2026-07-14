/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:12:58 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:13:01 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_flags flags, t_program *program)
{
	if (flags.strategy == SIMPLE)
		simple_sort(&program->stack_a, &program->stack_b,
			&program->operations);
	else if (flags.strategy == MEDIUM)
		medium_sort(&program->stack_a, &program->stack_b,
			&program->operations);
	else if (flags.strategy == COMPLEX)
		complex_sort(&program->stack_a, &program->stack_b,
			program->array_a, &program->operations);
	else
		adaptive_sort(&program->stack_a, &program->stack_b,
			program->array_a, &program->operations);
}

static void	init_program(int argc, char **argv,
	t_flags *flags, t_program *program)
{
	char	**expanded;

	*flags = parse_flags(argc, argv, &program->start_index);
	expanded = expand_arguments(argv, program->start_index, &program->array_len);
	if (!expanded)
		error_output();
	if (program->array_len < 1)
		exit(0);
	program->array_a = transform_argv(expanded,
			&program->array_len);
	free_split(expanded);
	if (!program->array_a)
		error_output();
	if (search_duplicates(program->array_a, program->array_len))
	{
		free(program->array_a);
		error_output();
	}
	program->stack_a = NULL;
	program->stack_b = NULL;
	program->operations = NULL;
	ft_array_to_list(program->array_a, &program->stack_a,
		program->array_len);
}

static void	sort_program(t_flags flags, t_program *program)
{
	if (is_sorted(program->stack_a))
		return ;
	if (program->array_len == 2)
		sort_two(&program->stack_a, &program->operations);
	else if (program->array_len == 3)
		sort_three(&program->stack_a, &program->operations);
	else if (program->array_len <= 5)
		sort_four_five(&program->stack_a, &program->stack_b,
			program->array_len, &program->operations);
	else
	{
		if (!normalize_values(program->array_a, program->stack_a,
				program->array_len))
		{
			free_list(program->stack_a);
			free(program->array_a);
			error_output();
		}
		run_strategy(flags, program);
	}
}

static void	free_program(t_program *program)
{
	free_list(program->stack_a);
	free_list(program->stack_b);
	free_operations(program->operations);
	free(program->array_a);
}

int	main(int argc, char **argv)
{
	t_flags		flags;
	t_program	program;

	if (argc < 2)
		return (0);
	init_program(argc, argv, &flags, &program);
	sort_program(flags, &program);
	print_operations(program.operations);
	benchmark_output(program.array_a, program.array_len,
		flags, program.operations);
	free_program(&program);
	return (0);
}
