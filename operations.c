void	sa(t_list **stack_a)
{
	int	i;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	i = *(int *)(*stack_a)->content;
	*(int *)(*stack_a)->content = *(int *)(*stack_a)->next->content;
	*(int *)(*stack_a)->next->content = i;
}
void	sb(t_list **stack_b)
{
	int	i;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	i = *(int *)(*stack_b)->content;
	*(int *)(*stack_b)->content = *(int *)(*stack_b)->next->content;
	*(int *)(*stack_b)->next->content = i;
}
void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
//-------------------------------------------
void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*moving_node;

	if (!stack_b || !*stack_b)
		return ;
	moving_node = *stack_b;
	*stack_b = (*stack_b)->next;
	moving_node->next = *stack_a;
	*stack_a = moving_node;
}
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*moving_node;

	if (!stack_a || !*stack_a)
		return ;
	moving_node = *stack_a;
	*stack_a = (*stack_a)->next;
	moving_node->next = *stack_b;
	*stack_b = moving_node;
}
//-------------------------------------------
void    ra(t_list **stack_a)
{
	t_list *first_node;
	t_list *last_node;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return;
	first_node = *stack_a;
	last_node = *stack_a;
	while (last_node->next)
		last_node = last_node->next;
	*stack_a = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}
void	rb(t_list **stack_b)
{
	t_list *first_node;
	t_list *last_node;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return;
	first_node = *stack_b;
	last_node = *stack_b;
	while (last_node->next)
		last_node = last_node->next;
	*stack_b = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}
void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
//-------------------------------------------
void rra(t_list **stack_a)
{
	t_list *prev;
	t_list *last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return;
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}
void	rrb(t_list **stack_b)
{
	t_list *prev;
	t_list *last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return;
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}
void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
