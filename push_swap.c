int search_duplicates(int *stack_a)
{
  int i;
  int j;
  
  i = 0;
  while (stack_a[i] != '\0')
  {
    j = 0;
    while (stack_a[j] != '\0')
    {
      if (stack_a[i] == stack_a[j])
        return (1);
      j++;
    }
    i++;
  }
  return (0);
}

void  push_swap(int *stack_a)
{
  int *stack_b;

  if(search_duplicates(stack_a) == 1)
    return ;
  
}

int main(void)
{
  int parser[5];
  
  parser[0] = 1;
  parser[1] = 2;
  parser[2] = 3;
  parser[3] = 4;
  parser[4] = 5;
  push_swap(parser);
  return (0);
}
