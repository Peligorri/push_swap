void pull_up(t_list **stack_a, int pos, int len)
{
	int	i;

	i = 0;
	if (pos < (len/2))
	{
		while (i < pos)
		{
			ra(stack_a);
			i++;
		}
	}
	else
		while (i < (len-pos))
		{
			rra(stack_a);
			i++;
		}
}

void move_lower_number_to_top(t_list **stack_a)
{
	t_list	*temp;
	t_list	*minimun;
	int		pos;
	int		len;

	if (!stack_a || *stack_a == NULL)
		return ;
	temp = *stack_a;
	minimun = *stack_a;
	pos = 0;
	len = 0;
	while(temp != NULL)
	{
		if(*temp->content < *minimun->content)
		{
			minimun = temp;
			pos = len;
		}
		temp = temp->next;
		len++;
	}
	pull_up(stack_a, pos, len);
}

void simple_algorythm(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || *stack_a == NULL)
		return ;
	if (!stack_b)
		return ;
	while (*stack_a != NULL)
	{
		move_lower_number_to_top(stack_a);
		pb(stack_a, stack_b);
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
/*Buscar el valor mínimo.
Llevarlo arriba usando ra o rra.
Hacer pb.
Repetir.
Hacer pa hasta devolver todos los elementos.*/