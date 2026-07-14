# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#              #
#    Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

# Source files
SRCS			= push_swap.c \
				parser.c \
				validation.c \
				libft_utils.c \
				libft_utils2.c \
				operation_list.c \
				operation_utils.c \
				swap_push.c \
				rotate.c \
				reverse_rotate.c \
				strategies.c \
				complex_sort.c \
				small_sort.c \
				normalization.c \
				stack_utils.c \
				stack_utils2.c \
				benchmark.c \
				fix_arguments.c \
				ft_split.c

# Object files
OBJS			= $(SRCS:.c=.o)

# Header files
HEADERS			= push_swap.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
