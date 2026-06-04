void	sa(t_list *stack_a)
{
	int	i;

	if(!stack_a || !stack_a->next)
		return ;
	i = *(int *)stack_a->content;
	*(int *)stack_a->content = *(int *)stack_a->next->content;
	*(int *)stack_a->next->content = i;
}
void	sb(t_list *stack_b)
{
	int	i;

	if(!stack_b || !stack_b->next)
		return ;
	i = *(int *)stack_b->content;
	*(int *)stack_b->content = *(int *)stack_b->next->content;
	*(int *)stack_b->next->content = i;
}
void	ss(t_list *stack_a, t_list *stack_b)
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
void	pb(char *stack_a, char *stack_b)
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
	t_list *temp;

	*temp->content = *stack_a->content;
    while(stack_a->next != NULL)
    {
    	stack_a = stack_a->next;
    }
    stack_a->next->content = temp->content;
}
void	rb(char *stack_b)
{
	int    i;
    char    temp;

    temp = stack_b[0];
    i = 0;
    while (stack_b[i] != '\0')
    {
        stack_b[i] = stack_b[i+1];
        i++;
    }
    stack_b[i-1] = temp;
}
void	rr(int *stack_a, int *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
//-------------------------------------------
void    rra(char *stack_a)
{
    int    i;
    char    temp;

    i = 0;
    while (stack_a[i] != '\0')
    {
        i++;
    }
    temp = stack_a[i-1];
    while (i > 0)
    {
      stack_a[i] = stack_a[i-1];
      i--;
    }
    stack_a[i] = temp;
}
void    rrb(char *stack_b)
{
    int    i;
    char    temp;

    i = 0;
    while (stack_b[i] != '\0')
    {
        i++;
    }
    temp = stack_b[i-1];
    while (i > 0)
    {
      stack_b[i] = stack_b[i-1];
      i--;
    }
    stack_b[i] = temp;
}
void	rrr(char *stack_a, char *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}