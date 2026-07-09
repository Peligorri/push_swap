*This project has been created as part of the 42 curriculum by <jangonza> and <molariou>*
# push_swap

## Description
push_swap is a sorting algorithm project from the 42 curriculum. The objective is to sort a stack of integers in ascending order using only a limited set of allowed operations while producing the smallest possible number of instructions. \

Our implementation analyzes the input by calculating its disorder percentage. Based on this value, it automatically selects the most appropriate sorting strategy: 

- Simple algorithm for small datasets.
- Medium algorithm for moderately disordered inputs.
- Complex algorithm for large or highly disordered datasets.
To sort the stack, we were only allowed to use the following operations: 
- **sa (swap a):** Swaps the first two elements at the top of stack_a. Does nothing if there are fewer than two elements.
- **sb (swap b):** Swaps the first two elements at the top of stack_b. Does nothing if there are fewer than two elements.
- **ss:** Performs **sa** and **sb** simultaneously.
- **pa (push a):** Takes the first element from stack_b and places it at the top of stack_a. Does nothing if stack_b is empty.
- **pb (push b):** Takes the first element from stack_a and places it at the top of stack_b. Does nothing if stack_a is empty.
- **ra (rotate a):** Rotates stack_a upwards by one position, moving the first element to the bottom of the stack.
- **rb (rotate b):** Rotates stack_b upwards by one position, moving the first element to the bottom of the stack.
- **rr:** Performs **ra** and **rb** simultaneously.
- **rra (reverse rotate a):** Rotates stack_a downwards by one position, moving the last element to the top of the stack.
- **rrb (reverse rotate b):** Rotates stack_b downwards by one position, moving the last element to the top of the stack.
- **rrr:** Performs **rra** and **rrb** simultaneously.

### Project Structure

The project is divided into small source files, each with a specific responsibility. This organization improves readability, simplifies maintenance, and ensures compliance with the 42 Norminette.

| File                  | Functions                                                                                                    |
| --------------------- | ------------------------------------------------------------------------------------------------------------ |
| **push_swap.c**       | `main()`, `init_program()`, `sort_program()`, `run_strategy()`, `free_program()`                             |
| **parser.c**          | `parse_flags()`, `is_known_flag()`, `apply_flag()`, `transform_argv()`, `validate_integer_range()`           |
| **validation.c**      | `search_duplicates()`, `stack_a_is_correct()`, `error_output()`                                              |
| **libft_utils.c**     | `ft_strlen()`, `ft_atoi()`, `ft_strcmp()`, `ft_putnbr_fd()`, `ft_putstr_fd()`                                |
| **libft_utils2.c**    | `search_symbol()`                                                                                            |
| **operation_list.c**  | `create_op_node()`, `record_operation()`, `print_operations()`, `free_operations()`, `count_operations()`    |
| **operation_utils.c** | `total_operations()`                                                                                         |
| **swap_push.c**       | `sa()`, `sb()`, `ss()`, `pa()`, `pb()`                                                                       |
| **rotate.c**          | `ra()`, `rb()`, `rr()`, `rotate_a_to_position()`, `rotate_b_to_position()`                                   |
| **reverse_rotate.c**  | `rra()`, `rrb()`, `rrr()`                                                                                    |
| **strategies.c**      | `adaptive_sort()`, `simple_sort()`, `medium_sort()`, `extra_ms()`, `fill_stack_b()`                          |
| **complex_sort.c**    | `complex_sort()`, `extra_complex_sort()`, `pass_sb()`, `rotate_b_to_max()`, `find_max_position()`            |
| **small_sort.c**      | `sort_two()`, `sort_three()`, `sort_four_five()`, `rotate_min_to_top()`, `find_min_position()`               |
| **normalization.c**   | `normalize_values()`, `assign_ranks()`, `copy_array()`                                                       |
| **stack_utils.c**     | `free_list()`, `is_sorted()`, `stack_length()`, `find_position()`, `find_min_value()`                        |
| **stack_utils2.c**    | `find_max_value()`, `chunk_size()`, `sqrt_approx()`, `ft_array_to_list()`, `calculate_disorder_percentage()` |
| **benchmark.c**       | `benchmark_output()`, `strategy_name()`, `complexity_name()`, `print_percent()`, `extra_benchmark()`         |

## Instructions

Compile the project using:

```bash
make
```
This generates the executable: push_swap. \
Execute the program by passing the numbers to sort as arguments:

```bash
./push_swap --bench 2 1 3 6 5 8
```
The program outputs the sequence of operations required to sort the stack.

```bash
pb
pb
rb
pb
rb
pb
pb
rb
pb
rb
rrb
pa
pa
rrb
pa
rrb
pa
pa
pa

=== BENCHMARK ===
Disorder: 13.33%
Strategy: adaptive (adaptive)
Total operations: 19
sa: 0 sb: 0 ss: 0
pa: 6 pb: 6
ra: 0 rb: 4 rr: 0
rra: 0 rrb: 3 rrr: 0
```

## Resources
- https://www.youtube.com/watch?v=OaG81sDEpVk&t=1603s
- https://www.youtube.com/watch?v=wRvipSG4Mmk&t=378s
- https://www.youtube.com/watch?v=4dMsuxfqufg&t=442s
We watched these videos to fully understand what we had to do in this project. They also helped us understand how to approach the code and how to structure it. \

- https://chatgpt.com/
We used AI as a tool to help us replace the Molinette and to assist us during the debugging process. We never used it to figure out how to implement parts of the program or to generate code for us. Janire also used it to improve the English in her texts.

## Contributions

### jangonza
- Designed the initial project structure.
- Implemented the program entry point and argument validation.
- Developed the stack manipulation operations.
- Reorganized the project structure and refactored the codebase.
- Ensured full compliance with the 42 Norminette.
- Wrote the initial version of the README.

### molariou
- Implemented the simple sorting algorithm.
- Implemented the medium sorting algorithm.
- Implemented the complex sorting algorithm.
- Implemented the adaptive algorithm that selects the most appropriate sorting strategy based on the input.
- Created the Makefile.
- Developed the project header files.
- Reviewed and corrected the English used throughout the project documentation.
