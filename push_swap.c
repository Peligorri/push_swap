size_t  ft_strlen(const char *s)
{
  size_t  num;
  size_t  i;

  num = 0;
  i = 0;
  while (s[i] != '\0')
  {
    num++;
    i++;
  }
  return (num);
}

static int  ft_putnum(const char *str, int num, int i, int neg)
{
  while (str[i] >= '0' && str[i] <= '9')
  {
    num = (str[i] - 48) + (num * 10);
    i++;
  }
  if (neg == 1)
    num = num * -1;
  return (num);
}

int ft_atoi(const char *nptr)
{
  int i;
  int num;
  int neg;

  i = 0;
  num = 0;
  neg = 0;
  while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
    i++;
  if (nptr[i] == '-')
  {
    neg = 1;
    i++;
  }
  else if (nptr[i] == '+')
    i++;
  if (nptr[i] < '0' || nptr[i] > '9')
    return (0);
  num = ft_putnum(nptr, num, i, neg);
  return (num);
}

int search_duplicates(int *stack_a, int length)
{
  int i;
  int j;
  
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

int stack_a_is_correct(char *stack_a)
{
  int i;
  int len;

  i = 1;
  len = ft_strlen(stack_a);
  while (stack_a[i] == ' ')
    i++;
  if(stack_a[i] != '-' && stack_a[i] != '+' && (stack_a[i] < '0' || stack_a[i] > '9'))
      return (1);
  if (len == 1 && (stack_a[0] == '-' || stack_a[0] == '+'))
    return (1);
  while (i < len)
  {
    if(stack_a[i] < '0' || stack_a[i] > '9')
      return (1);
    i++;
  }
  return (0);
}

int calculate_disorder(int *stack_a, int length)
{
  int mistakes;
  int total_pairs;
  int i;
  int j;

  i = 0;
  mistakes = 0;
  total_pairs = 0;

  while (i < length)
  {
    j = i + 1;
    while (j < length)
    {
      total_pairs++;
      if (stack_a[i] > stack_a[j])
        mistakes++;
      j++;
    }
    i++;
  }
  return ((mistakes * 100)/total_pairs);
}

void  push_swap(int *stack_a, int length)
{
  int *stack_b;
  int disorder_index;

  if(search_duplicates(stack_a, length) == 1 || length < 2)
    return ;
  disorder_index = calculate_disorder(stack_a, length);
}

int *transform_argv(char *argv, int length)
{
  int *stack_a;
  int i;

  if (!argv || length < 0)
    return (0);
  stack_a = malloc(sizeof(int) * length);
  if (!stack_a)
    return (0);
  i = 0;
  while (i < length)
  {
    if(stack_a_is_correct(argv[i + 1]) == 1)
    {
      free (stack_a);
      return (0);
    }
    stack_a[i] = ft_atoi(argv[i + 1]);
    i++;
  }
  return (stack_a);
}

int main(int argc, char *argv[])
{
  int *stack_a;

  stack_a = transform_argv(argv, (argc - 1));
  if(!stack_a)
    return (1);
  push_swap(stack_a, (argc - 1));
  return (0);
}
