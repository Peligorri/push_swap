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

### Sorting Algorithms
#### Simple Algorithm (O(n²))

The simple strategy is based on repeated minimum extraction, an adaptation of the Selection Sort algorithm. \

The algorithm repeatedly finds the smallest value in stack_a, rotates the stack until that value reaches the top, and pushes it to stack_b. Once all elements have been moved, they are pushed back to stack_a, resulting in a sorted stack. \

This approach is easy to understand and works well for small inputs, although it becomes inefficient as the number of elements grows.

#### Medium Algorithm (O(n√n))

The medium strategy uses a chunk-based sorting algorithm. \

After normalizing the input values, the algorithm divides them into value ranges (chunks). Elements belonging to the current chunk are pushed from stack_a to stack_b, while the remaining elements are rotated until they belong to the active range. Once all elements have been moved to stack_b, the largest values are moved back to stack_a in descending order, producing an ascending sequence. \

Processing the stack by ranges significantly reduces the number of operations compared to the simple algorithm.

#### Complex Algorithm (O(n log n))

The complex strategy uses a Radix Sort adapted to the two-stack constraints of the project. \

After normalizing the values to consecutive indices, the algorithm processes the binary representation of each value one bit at a time. For each bit position, elements with a 0 are pushed to stack_b, while elements with a 1 remain in stack_a through rotations. After each pass, all elements are moved back to stack_a. Repeating this process for every bit produces a fully sorted stack. \

This approach offers a time complexity of O(n log n) and scales efficiently for large datasets.

### Project Structure

The project is divided into small source files, each with a specific responsibility. This organization improves readability, simplifies maintenance, and ensures compliance with the 42 Norminette.

| File                  | Functions                                                                                                    |
| --------------------- | ------------------------------------------------------------------------------------------------------------ |
| **push_swap.c**       | `main()`, `init_program()`, `sort_program()`, `run_strategy()`, `free_program()`                             |
| **parser.c**          | `parse_flags()`, `is_known_flag()`, `apply_flag()`, `transform_argv()`, `validate_integer_range()`           |
| **validation.c**      | `search_duplicates()`, `stack_a_is_correct()`, `error_output()`                                              |
| **libft_utils.c**     | `ft_strlen()`, `ft_atoi()`, `ft_strcmp()`, `ft_putnbr_fd()`, `ft_putstr_fd()`                                |
| **libft_utils2.c**    | `search_symbol()`, `ft_strdup`                                                                               |
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
| **ft_split.c**        | `count_words()`, `word_dup()`, `free_all()`, `fill_words()`, `ft_split()`                                    |

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
- Reviewed and corrected the complex sorting algorithm (Radix).

### molariou
- Implemented the simple sorting algorithm.
- Implemented the medium sorting algorithm.
- Implemented the complex sorting algorithm.
- Implemented the adaptive algorithm that selects the most appropriate sorting strategy based on the input.
- Created the Makefile.
- Developed the project header files.
- Reviewed and corrected the English used throughout the project documentation.
