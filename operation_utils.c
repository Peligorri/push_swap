/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:09:40 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/16 13:09:43 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_operations(t_op_node *ops)
{
	int	count;

	count = 0;
	while (ops)
	{
		count++;
		ops = ops->next;
	}
	return (count);
}
