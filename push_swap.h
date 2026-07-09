/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:09:40 by jangonza          #+#    #+#             */
/*   Updated: 2026/07/07 12:17:32 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_flags
{
	t_strategy	strategy;
	int			bench;
}	t_flags;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_op_node
{
	char				*operation;
	struct s_op_node	*next;
}	t_op_node;

typedef struct s_program
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_op_node	*operations;
	int			*array_a;
	int			array_len;
	int			start_index;
}	t_program;

int			search_duplicates(int *stack_a, int length);
int			stack_a_is_correct(char *stack_a);
int			*transform_argv(char **argv, int *length);
void		ft_array_to_list(int *array_a, t_list **stack_a, int length);
int			validate_integer_range(const char *str);
void		error_output(void);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *str, int fd);
t_flags		parse_flags(int argc, char **argv, int *start_index);
void		simple_sort(t_list **stack_a, t_list **stack_b,
				t_op_node **ops_head);
void		medium_sort(t_list **stack_a, t_list **stack_b,
				t_op_node **ops_head);
void		complex_sort(t_list **stack_a, t_list **stack_b, int *array,
				t_op_node **ops_head);
double		calculate_disorder_percentage(int *array, int length);
void		adaptive_sort(t_list **stack_a, t_list **stack_b, int *array,
				t_op_node **ops_head);
void		benchmark_output(int *array, int length, t_flags flags,
				t_op_node *ops);
void		sa(t_list **stack_a, t_op_node **operations);
void		sb(t_list **stack_b, t_op_node **operations);
void		ss(t_list **stack_a, t_list **stack_b, t_op_node **operations);
void		pa(t_list **stack_a, t_list **stack_b, t_op_node **operations);
void		pb(t_list **stack_a, t_list **stack_b, t_op_node **operations);
void		ra(t_list **stack_a, t_op_node **operations);
void		rb(t_list **stack_b, t_op_node **operations);
void		rr(t_list **stack_a, t_list **stack_b, t_op_node **operations);
void		rra(t_list **stack_a, t_op_node **operations);
void		rrb(t_list **stack_b, t_op_node **operations);
void		rrr(t_list **stack_a, t_list **stack_b, t_op_node **operations);

t_op_node	*create_op_node(char *op_name);
void		record_operation(t_op_node **ops_head, char *op_name);
void		print_operations(t_op_node *ops_head);
void		free_operations(t_op_node *ops_head);
int			count_operations(t_op_node *ops, char *op_name);
void		free_list(t_list *stack);
int			is_sorted(t_list *stack);
void		sort_two(t_list **stack_a, t_op_node **operations);
void		sort_three(t_list **stack_a, t_op_node **operations);
int			find_min_position(t_list *stack);
int			stack_length(t_list *stack);
int			find_position(t_list *stack, int value);
int			find_min_value(t_list *stack);
int			find_max_value(t_list *stack);
int			chunk_size(int length);
int			total_operations(t_op_node *ops);
void		rotate_b_to_position(t_list **stack_b, int pos,
				t_op_node **ops_head);
void		rotate_a_to_position(t_list **stack_a, int pos,
				t_op_node **ops_head);
int			sqrt_approx(int n);
int			normalize_values(int *array, t_list *stack, int length);
void		assign_ranks(int *array, int *copy, t_list *stack, int length);
int			*copy_array(int *array, int length);
void		sort_four_five(t_list **stack_a, t_list **stack_b, int length,
				t_op_node **operations);
void		rotate_min_to_top(t_list **stack_a, int length,
				t_op_node **operations);
int			search_symbol(const char *str, int *neg);

#endif
