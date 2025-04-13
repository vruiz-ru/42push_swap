# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/12 18:22:52 by vruiz-ru          #+#    #+#              #
#    Updated: 2025/04/12 18:22:58 by vruiz-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
SRCS	= ft_split.c \
		ft_strings.c \
		main.c \
		push.c \
		rotate.c \
		swap.c \
		stack.c \
		radix.c \
		sort.c \

CC = cc
OBJS	= $(SRCS:.c=.o)
RM	= rm -f
FLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(FLAGS) -c $< -o $@ -I.

$(NAME): $(OBJS)
	 $(CC) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re .c.o
