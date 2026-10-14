# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/14 12:39:34 by nide-wil          #+#    #+#              #
#    Updated: 2026/10/14 16:46:49 by nide-wil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c \
			  ft_print_percent.c \
			  ft_print_char.c \
			  ft_print_str.c \
			  ft_print_nbr.c \
			  ft_print_unsigned.c \
			  ft_print_hex.c \
			  ft_print_ptr.c \

OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

TEST_BIN	= TEST
TEST_SRC	= main_test.c

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) -I. -o $(TEST_BIN)
	./$(TEST_BIN)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_BIN)

re: fclean all

.PHONY: all clean fclean re
