# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/14 12:39:34 by nide-wil          #+#    #+#              #
#    Updated: 2026/10/15 13:27:48 by nide-wil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT		= libft/libft.a

SRCS		= ft_printf.c \
			  ft_print_percent.c \
			  ft_print_char.c \
			  ft_print_str.c \
			  ft_print_nbr.c \
			  ft_print_unsigned.c \
			  ft_print_hex.c \
			  ft_hex_utils.c \
			  ft_print_ptr.c \
			  ft_parse.c \

OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -g #-Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

TEST_BIN	= TEST
TEST_SRC	= main_test.c

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) -I. -o $(TEST_BIN)
	./$(TEST_BIN)
	$(MAKE) fclean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_BIN)

re: fclean all

.PHONY: all clean fclean re
